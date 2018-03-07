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
* Created on 2018/02/28 at 19:50:29 by Benoit Hivert <hivert.benoit@gmail.com>
* Updated on 2018/03/07 at 01:32:49 by Benoit Hivert <hivert.benoit@gmail.com>
*/

#include "list.h"
#include "node.h"

// list utils

inline void	list_clear(list_t *lst) {
	*lst = (list_t){0, NULL, NULL};
}

inline size_t	list_size(list_t *lst) {
	return lst->size;
}

// list handling

node_t	*list_popFront(list_t *lst) {
	node_t	*tmp = list_begin(lst);
	lst->head = list_next(tmp);
	if (lst->head == list_end(lst))
		lst->tail = list_end(lst);
	--lst->size;
	return tmp;
}

void	list_pushFront(list_t *lst, node_t *node) {
	node->ptr = list_begin(lst);
	lst->head = node;
	if (lst->tail == list_end(lst))
		lst->head = node;
	++lst->size;
}

void	list_pushBack(list_t *lst, node_t *node) {
	node->ptr = list_end(lst);
	if (lst->head == list_end(lst)) {
		lst->head = node;
		lst->tail = node;
		++lst->size;
		return ;
	}
	lst->tail->ptr = node;
	lst->tail = node;
	++lst->size;
}

// list iterators

inline node_t	*list_begin(list_t *lst) {
	return lst->head;
}

inline node_t	*list_end(list_t *lst) {
	(void)lst;
	return NULL;
}

inline node_t	*list_next(node_t *node) {
	return node->ptr;
}

void	list_iter(list_t *lst, void (fct)(node_t *)) {
	for (node_t *node = list_begin(lst); node != list_end(lst); node = list_next(node)) {
		fct(node);
	}
}
