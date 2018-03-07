/*
* flist.c is part of a project.
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
* Created on 2018/02/28 at 19:50:29 by Benoit Hivert <hivert.benoit@gmail.com>
* Updated on 2018/03/07 at 18:50:34 by Benoit Hivert <hivert.benoit@gmail.com>
*/

#include "flist.h"
#include "node.h"

// flist utils

inline void	flist_clear(flist_t *lst) {
	*lst = (flist_t){0, NULL, NULL};
}

inline size_t	flist_size(flist_t *lst) {
	return lst->size;
}

// flist handling

node_t	*flist_popFront(flist_t *lst) {
	node_t	*tmp = flist_begin(lst);
	lst->head = flist_next(tmp);
	if (lst->head == flist_end(lst))
		lst->tail = flist_end(lst);
	--lst->size;
	return tmp;
}

void	flist_pushFront(flist_t *lst, node_t *node) {
	node->ptr = flist_begin(lst);
	lst->head = node;
	if (lst->tail == flist_end(lst))
		lst->head = node;
	++lst->size;
}

void	flist_pushBack(flist_t *lst, node_t *node) {
	node->ptr = flist_end(lst);
	if (lst->head == flist_end(lst)) {
		lst->head = node;
		lst->tail = node;
		++lst->size;
		return ;
	}
	lst->tail->ptr = node;
	lst->tail = node;
	++lst->size;
}

// flist iterators

inline node_t	*flist_begin(flist_t *lst) {
	return lst->head;
}

inline node_t	*flist_end(flist_t *lst) {
	(void)lst;
	return NULL;
}

inline node_t	*flist_next(node_t *node) {
	return node->ptr;
}

void	flist_iter(flist_t *lst, void (fct)(node_t *)) {
	for (node_t *node = flist_begin(lst); node != flist_end(lst); node = flist_next(node)) {
		fct(node);
	}
}
