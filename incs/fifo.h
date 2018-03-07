/*
* fifo.h is part of a project.
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
* Created on 2018/03/06 at 23:58:41 by Benoit Hivert <hivert.benoit@gmail.com>
* Updated on 2018/03/07 at 18:51:48 by Benoit Hivert <hivert.benoit@gmail.com>
*/

#ifndef FIFO_H
# define FIFO_H

# include <stdlib.h>

typedef struct _node_t	node_t;
typedef struct _flist_t	fifo_t;

// fifo utils
void	fifo_clear(fifo_t *);
size_t	fifo_size(fifo_t *);
// fifo handling
node_t	*fifo_pop(fifo_t *);
void	fifo_push(fifo_t *, node_t *);
// fifo iterators
node_t	*fifo_begin(fifo_t *);
node_t	*fifo_end(fifo_t *);
node_t	*fifo_next(node_t *);
void	fifo_iter(fifo_t *, void (*)(node_t *));

#endif
