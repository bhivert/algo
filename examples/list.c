/*
* list.c is part of a project.
* Copyright (C) 2018 Benoit Hivert <hivert.benoit@gmail.com>
*
* This project is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This project is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this project. If not, see <http://www.gnu.org/licenses/>
*
* Created on 2018/02/28 at 19:50:27 by Benoit Hivert <hivert.benoit@gmail.com>
* Updated on 2018/03/03 at 17:51:20 by Benoit Hivert <hivert.benoit@gmail.com>
*/

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _argv_t {
	node_t		*next;
	const char	*ptr;
}				argv_t;

void	print(argv_t *av) {
	printf("|%s|", av->ptr);
}

void	swap(argv_t *n0, argv_t *n1) {
	const char *tmp;

	tmp = n1->ptr;
	n1->ptr = n0->ptr;
	n0->ptr = tmp;
}

int main(int ac, char *av[]) {
	if (ac < 2) {
		printf("usage : %s argvs\n", av[0]);
		return EXIT_SUCCESS;
	}

	list_t	pf;
	list_t	pb;
	argv_t	*nodes;
	argv_t	*pf_nodes;
	argv_t	*pb_nodes;

	if (!(nodes = (argv_t *)malloc(sizeof(argv_t) * ac * 2))) {
		fprintf(stderr, "%s error memory allocation failled\n", av[0]);
		return EXIT_FAILURE;
	}
	pf_nodes = nodes;
	pb_nodes = &nodes[ac];

	list_clear(&pf);
	list_clear(&pb);
	while (--ac) {
		pf_nodes[ac] = (argv_t){NULL, av[ac]};
		pb_nodes[ac] = (argv_t){NULL, av[ac]};
		list_pushFront(&pf, (node_t *)&pf_nodes[ac]);
		list_pushBack(&pb, (node_t *)&pb_nodes[ac]);
	}
	printf("list size [pf|pb] [%zu|%zu]\n", list_size(&pf), list_size(&pb));
	if (list_size(&pf) > 1) {
		printf("swaping first two elem of pb and pb\n");
		list_swapTwo(list_begin(&pf), list_next(list_begin(&pf)), (void(*)(node_t *, node_t *))&swap);
		list_swapTwo(list_begin(&pb), list_next(list_begin(&pb)), (void(*)(node_t *, node_t *))&swap);
	}
	printf("list iter pf[");
	list_iter(&pf, (void(*)(node_t *))&print);
	printf("]\nlist iter pb[");
	list_iter(&pb, (void(*)(node_t *))&print);
	printf("]\nlist iter reverse pf[");
	list_iterReverse(list_begin(&pf), (void(*)(node_t *))&print);
	printf("]\nlist iter reverse pb[");
	list_iterReverse(list_begin(&pb), (void(*)(node_t *))&print);
	printf("]\n");
	ac = list_size(&pf) / 2 + list_size(&pf) % 2;
	printf("list pop front x %d\n", ac - 1);
	while (--ac) {
		list_popFront(&pf);
		list_popFront(&pb);
	}
	printf("list size [pf|pb] [%zu|%zu]\n", list_size(&pf), list_size(&pb));
	printf("list iter pf[");
	list_iter(&pf, (void(*)(node_t *))&print);
	printf("]\nlist iter pb[");
	list_iter(&pb, (void(*)(node_t *))&print);
	printf("]\nlist iter reverse pf[");
	list_iterReverse(list_begin(&pf), (void(*)(node_t *))&print);
	printf("]\nlist iter reverse pb[");
	list_iterReverse(list_begin(&pb), (void(*)(node_t *))&print);
	printf("]\n");
	while (list_size(&pb)) {
		list_popFront(&pf);
		list_popFront(&pb);
	}
	list_clear(&pf);
	list_clear(&pb);
	free(nodes);
	return EXIT_SUCCESS;
}
