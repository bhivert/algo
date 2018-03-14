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
* Updated on 2018/03/14 at 04:01:01 by Benoit Hivert <hivert.benoit@gmail.com>
*/

#ifndef FIFO_H
# define FIFO_H

/*!
  @file fifo.h
  @brief first in first out data structure and basic operations
  @struct fifo_t
  @implements dlist_t
  */

# include "dlist.h"
# include <stdlib.h>

/*!
  @relates fifo_t
  @{
  */

typedef dlist_t	fifo_t;

//! @name fifo utils
//! @{
void	fifo_clear(fifo_t *);
size_t	fifo_size(fifo_t *);
//! @}

//! @name fifo handling
//! @{
bnode_t	*fifo_pop(fifo_t *);
void	fifo_push(fifo_t *, bnode_t *);
void	fifo_iter(fifo_t *, void (*)(bnode_t *));
//! @}

//! @name fifo iterators
//! @{
bnode_t	*fifo_begin(fifo_t *);
bnode_t	*fifo_end(fifo_t *);
bnode_t	*fifo_prev(bnode_t *);
bnode_t	*fifo_next(bnode_t *);
//! @}

/*!
  @}
  */

#endif
