/*
* lifo.h is part of a project.
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
* Created on 2018/03/07 at 01:21:02 by Benoit Hivert <hivert.benoit@gmail.com>
* Updated on 2018/03/14 at 04:00:11 by Benoit Hivert <hivert.benoit@gmail.com>
*/

#ifndef LIFO_H
# define LIFO_H

/*!
  @file lifo.h
  @brief last in first out data structure and basic operations
  @struct lifo_t
  @example testing/lifo.c
  */

# include "node.h"
# include <stdlib.h>

typedef struct _lifo_t	{
	size_t	size;
	node_t	*head;
	node_t	sentinel;
} lifo_t;

/*!
  @relates lifo_t
  @{
  */

//! @name lifo utils
//! @{
void	lifo_clear(lifo_t *);
size_t	lifo_size(lifo_t *);
//! @}

//! @name lifo handling
//! @{
node_t	*lifo_pop(lifo_t *);
void	lifo_push(lifo_t *, node_t *);
void	lifo_iter(lifo_t *, void (*)(node_t *));
//! @}

//! @name lifo iterators
//! @{
node_t	*lifo_begin(lifo_t *);
node_t	*lifo_end(lifo_t *);
node_t	*lifo_next(node_t *);
//! @}

/*!
  @}
  */

#endif
