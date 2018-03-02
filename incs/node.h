/*
* node.h is part of a project.
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
* along with this program. If not, see <http://www.gnu.org/licenses/>
*
* Created on 2018/02/28 at 20:16:43 by Benoit Hivert <hivert.benoit@gmail.com>
* Updated on 2018/03/03 at 00:25:29 by Benoit Hivert <hivert.benoit@gmail.com>
*/

#ifndef NODE_H
# define NODE_H

typedef struct	_node_t {
	struct _node_t	*ptr;
} node_t;

#endif
