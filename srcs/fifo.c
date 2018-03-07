/*
* stack.c is part of a project.
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
* Created on 2018/03/06 at 23:59:18 by Benoit Hivert <hivert.benoit@gmail.com>
* Updated on 2018/03/07 at 14:01:21 by Benoit Hivert <hivert.benoit@gmail.com>
*/

#include "fifo.h"
#include "list.h"
#include "node.h"

// fifo utils

inline void	fifo_clear(fifo_t *fifo) {
	list_clear((list_t *)fifo);
}

inline size_t	fifo_size(fifo_t *fifo) {
	return list_size((list_t *)fifo);
}

// fifo handling

inline node_t	*fifo_pop(fifo_t *fifo) {
	return list_popFront((list_t *)fifo);
}

inline void	fifo_push(fifo_t *fifo, node_t *node) {
	list_pushBack((list_t *)fifo, node);
}

// fifo iterators

inline node_t	*fifo_begin(fifo_t *fifo) {
	return list_begin((list_t *)fifo);
}

inline node_t	*fifo_end(fifo_t *fifo) {
	(void)fifo;
	return NULL;
}

inline node_t	*fifo_next(node_t *node) {
	return list_next(node);
}

inline void	fifo_iter(fifo_t *fifo, void (fct)(node_t *)) {
	list_iter((list_t *)fifo, fct);
}
