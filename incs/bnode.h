/*
* bnode.h is part of a project.
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
* Created on 2018/03/03 at 00:17:02 by Benoit Hivert <hivert.benoit@gmail.com>
* Updated on 2018/03/08 at 18:29:07 by Benoit Hivert <hivert.benoit@gmail.com>
*/

#ifndef BNODE_H
# define BNODE_H

typedef struct _bnode_t {
	struct _bnode_t	*ptr[2];
} bnode_t;

#endif
