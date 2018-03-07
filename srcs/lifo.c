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
* Created on 2018/03/07 at 01:19:36 by Benoit Hivert <hivert.benoit@gmail.com>
* Updated on 2018/03/07 at 14:01:33 by Benoit Hivert <hivert.benoit@gmail.com>
*/

#include "node.h"
#include "lifo.h"

// lifo utils

void	lifo_clear(lifo_t *lifo) {
	*lifo = (lifo_t){0, NULL};
}

size_t	lifo_size(lifo_t *lifo) {
	return lifo->size;
}

// lifo handling

node_t	*lifo_pop(lifo_t *lifo) {
	node_t	*tmp = lifo_begin(lifo);
	lifo->head = tmp->ptr;
	--lifo->size;
	return tmp;;
}

void	lifo_push(lifo_t *lifo, node_t *node) {
	node->ptr = lifo_begin(lifo);
	lifo->head = node;
	++lifo->size;
}

// lifo iterators

node_t	*lifo_begin(lifo_t *lifo) {
	return lifo->head;
}

node_t	*lifo_end(lifo_t *lifo) {
	(void)lifo;
	return NULL;
}

node_t	*lifo_next(node_t *node) {
	return node->ptr;
}

void	lifo_iter(lifo_t *lifo, void (fct)(node_t *)) {
	for (node_t *node = lifo_begin(lifo); node != lifo_end(lifo); node = lifo_next(node)) {
		fct(node);
	}
}
