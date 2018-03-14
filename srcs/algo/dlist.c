/*
* dlist.c is part of a project.
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
* Created on 2018/03/03 at 17:55:56 by Benoit Hivert <hivert.benoit@gmail.com>
* Updated on 2018/03/08 at 23:01:16 by Benoit Hivert <hivert.benoit@gmail.com>
*/

#include "dlist.h"

enum {
	PREV = 0,
	NEXT
};

// dlist utils
inline void	dlist_clear(dlist_t *lst) {
	*lst = (dlist_t){0, {{dlist_end(lst), dlist_end(lst)}}};
}

inline size_t	dlist_size(dlist_t *lst) {
	return lst->size;
}

// dlist handling
inline bnode_t	*dlist_popFront(dlist_t *lst) {
	return dlist_delete(lst, dlist_begin(lst));
}

inline bnode_t	*dlist_popBack(dlist_t *lst) {
	return dlist_delete(lst, dlist_prev(dlist_end(lst)));
}

inline void	dlist_pushFront(dlist_t *lst, bnode_t *node) {
	dlist_insert_after(lst, dlist_end(lst), node);
}

inline void	dlist_pushBack(dlist_t *lst, bnode_t *node) {
	dlist_insert_before(lst, dlist_end(lst), node);
}

bnode_t	*dlist_delete(dlist_t *lst, bnode_t *node) {
	dlist_prev(node)->ptr[NEXT] = dlist_next(node);
	dlist_next(node)->ptr[PREV] = dlist_prev(node);
	--lst->size;
	return node;
}

void	dlist_insert_before(dlist_t *lst, bnode_t *node, bnode_t *new) {
	new->ptr[PREV] = dlist_prev(node);
	new->ptr[NEXT] = dlist_next(node);
	dlist_prev(new)->ptr[NEXT] = new;
	dlist_next(new)->ptr[PREV] = new;
	++lst->size;
}

void	dlist_insert_after(dlist_t *lst, bnode_t *node, bnode_t *new) {
	new->ptr[PREV] = node;
	new->ptr[NEXT] = dlist_next(node);
	dlist_prev(new)->ptr[NEXT] = node;
	dlist_next(new)->ptr[PREV] = node;
	++lst->size;
}

inline void	dlist_iter(dlist_t *lst, void (fct)(bnode_t *)) {
	for (bnode_t *node = dlist_begin(lst); node != dlist_end(lst); node = dlist_next(node)) {
		fct(node);
	}
}

// dlist iterators
inline bnode_t	*dlist_begin(dlist_t *lst) {
	return dlist_end(lst)->ptr[NEXT];
}

inline bnode_t	*dlist_end(dlist_t *lst) {
	return &lst->sentinel;
}

inline bnode_t	*dlist_prev(bnode_t *node) {
	return node->ptr[PREV];
}

inline bnode_t	*dlist_next(bnode_t *node) {
	return node->ptr[NEXT];
}

