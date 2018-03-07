/*
* list.h is part of a project.
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
* Created on 2018/02/28 at 19:50:24 by Benoit Hivert <hivert.benoit@gmail.com>
* Updated on 2018/03/07 at 01:04:01 by Benoit Hivert <hivert.benoit@gmail.com>
*/

#ifndef LIST_H
# define LIST_H

# include "node.h"
# include <stdlib.h>

typedef struct	_list_t {
	size_t	size;
	node_t	*head;
	node_t	*tail;
} list_t;

// list utils
void	list_clear(list_t *);
size_t	list_size(list_t *);
// list handling
node_t	*list_popFront(list_t *);
void	list_pushFront(list_t *, node_t *);
void	list_pushBack(list_t *, node_t *);
// list iterators
node_t	*list_begin(list_t *);
node_t	*list_end(list_t *);
node_t	*list_next(node_t *);
void	list_iter(list_t *, void (*)(node_t *));

#endif
