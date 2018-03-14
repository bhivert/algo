/*
* dlist.h is part of a project.
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
* Created on 2018/03/03 at 17:55:20 by Benoit Hivert <hivert.benoit@gmail.com>
* Updated on 2018/03/14 at 04:01:14 by Benoit Hivert <hivert.benoit@gmail.com>
*/

#ifndef DLIST_H
# define DLIST_H

# include "bnode.h"
# include <stdlib.h>

/*!
  @file dlist.h
  @brief doubly linked list data structure and basic operations
  @struct dlist_t
  */

typedef struct	_dlist_t {
	size_t	size;
	bnode_t	sentinel;
} dlist_t;

/*!
  @relates dlist_t
  @{
  */

//! @name dlist utils
//! @{
void	dlist_clear(dlist_t *);
size_t	dlist_size(dlist_t *);
//! @}

//! @name dlist handling
//! @{
bnode_t	*dlist_popFront(dlist_t *);
bnode_t	*dlist_popBack(dlist_t *);
void	dlist_pushFront(dlist_t *, bnode_t *);
void	dlist_pushBack(dlist_t *, bnode_t *);
bnode_t	*dlist_delete(dlist_t *, bnode_t *);
void	dlist_insert_before(dlist_t *, bnode_t *, bnode_t *);
void	dlist_insert_after(dlist_t *, bnode_t *, bnode_t *);
void	dlist_iter(dlist_t *, void (*)(bnode_t *));
//! @}

//! @name dlist iterators
//! @{
bnode_t	*dlist_begin(dlist_t *);
bnode_t	*dlist_end(dlist_t *);
bnode_t	*dlist_prev(bnode_t *node);
bnode_t	*dlist_next(bnode_t *);
//! @}

/*!
  @}
  */

#endif
