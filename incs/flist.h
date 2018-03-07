/*
* flist.h is part of a project.
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
* Updated on 2018/03/07 at 18:50:01 by Benoit Hivert <hivert.benoit@gmail.com>
*/

#ifndef FLIST_H
# define FLIST_H

# include <stdlib.h>

typedef struct _node_t	node_t;
typedef struct	_flist_t {
	size_t	size;
	node_t	*head;
	node_t	*tail;
} flist_t;

// flist utils
void	flist_clear(flist_t *);
size_t	flist_size(flist_t *);
// flist handling
node_t	*flist_popFront(flist_t *);
void	flist_pushFront(flist_t *, node_t *);
void	flist_pushBack(flist_t *, node_t *);
// flist iterators
node_t	*flist_begin(flist_t *);
node_t	*flist_end(flist_t *);
node_t	*flist_next(node_t *);
void	flist_iter(flist_t *, void (*)(node_t *));

#endif
