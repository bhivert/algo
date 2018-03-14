/*
* lifo.c is part of a project.
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
* Updated on 2018/03/14 at 03:56:49 by Benoit Hivert <hivert.benoit@gmail.com>
*/

/*!
  @file testing/lifo.c
  @brief lifo_t testing/example file
  */

#include "algo/lifo.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _data_t {
	node_t		next;
	int			value;
} data_t;

void	print(data_t *data) {
	fprintf(stderr, "|%d|", data->value);
}

int main(int ac, char *av[]) {
	lifo_t	lifo;
	data_t	*nodes;
	int		values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int		ret = EXIT_SUCCESS;

	(void)ac;
	setbuf(stderr, NULL);
	if (!(nodes = (data_t *)malloc(sizeof(data_t) * (sizeof(values) / sizeof(*values))))) {
		fprintf(stderr, "%s error memory allocation failled\n", av[0]);
		return EXIT_FAILURE;
	}

	lifo_clear(&lifo);
	size_t i = ~0;
	while (++i < (sizeof(values) / sizeof(*values))) {
		nodes[i] = (data_t){{NULL}, values[i]};
		lifo_push(&lifo, (node_t *)&nodes[i]);
	}
	fprintf(stderr, "lifo size [%zu|%zu]\nlifo iter [", lifo_size(&lifo), sizeof(values) / sizeof(*values));
	lifo_iter(&lifo, (void(*)(node_t *))&print);
	fprintf(stderr, "]\nlifo pop while != end [");
	while (lifo_begin(&lifo) != lifo_end(&lifo)) {
		data_t *tmp = (data_t *)lifo_pop(&lifo);
		fprintf(stderr, "|%d|", tmp->value);
		if (tmp->value != values[--i]) {
			fprintf(stderr, "/!\\");
			ret = EXIT_FAILURE;
		}
	}
	fprintf(stderr, "]\n");
	data_t tmp = {{NULL}, sizeof(values) / sizeof(*values)};
	lifo_push(&lifo, (node_t *)&tmp);
	fprintf(stderr, "lifo size [%zu|1]\n", lifo_size(&lifo));
	if (lifo_size(&lifo) != 1)
		ret = EXIT_FAILURE;
	free(nodes);
	return ret;
}
/*
  Output:
  lifo size [10|10]
  lifo iter [|9||8||7||6||5||4||3||2||1||0|]
  lifo pop while != end [|9||8||7||6||5||4||3||2||1||0|]
  lifo size [1|1]
*/
