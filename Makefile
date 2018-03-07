##
# Makefile is part of a project.
# Copyright (C) 2018 Benoit Hivert <hivert.benoit@gmail.com>
#
# This project is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This project is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this project. If not, see <http://www.gnu.org/licenses/>
#
# Created on 2018/02/28 at 19:56:53 by Benoit Hivert <hivert.benoit@gmail.com>
# Updated on 2018/03/07 at 14:54:19 by Benoit Hivert <hivert.benoit@gmail.com>
##

.PHONY: all, clean, fclean, re, _make, _make_clean, _make_fclean
.SUFFIXES:

NAME		=	libcalgo.a

DEBUG		=	0
ifeq ($(DEBUG), 0)
	CC	=	gcc
	CFLAGS	=	-Wall -Wextra -Werror $(INCS_FLAGS) -O3
else
	CC	=	clang
	CFLAGS	=	-Wall -Wextra $(INCS_FLAGS) -g3
endif

DEPENDS		=	

LIBS_DIR	=	

LIBS		=	

INCS_FLAGS	=	-Iincs \

SUB_MAKE	=	

SRCS_DIR	=	srcs
SRCS_SRCS	=	$(SRCS_DIR)/lifo.c \
				$(SRCS_DIR)/list.c \
				$(SRCS_DIR)/fifo.c \

SRCS		=	$(SRCS_SRCS) \

OBJS		=	$(SRCS:.c=.o)

all		:	_make $(NAME)

$(NAME)		:	$(OBJS)
	@ar rc $@ $^
	ranlib $@

%.o	:	%.c $(DEPENDS)
	$(CC) $(CFLAGS) -c $< -o $@

clean		:	_make_clean
	rm -rf $(OBJS)

fclean		:	_make_fclean clean
	rm -rf $(NAME)

re			:	fclean all

_make		:
ifeq ($(DEBUG), 2)
	$(foreach MAKE, $(SUB_MAKE),make -C $(MAKE) DEBUG=$(DEBUG);)
else
	$(foreach MAKE, $(SUB_MAKE),make -C $(MAKE);)
endif

_make_clean		:
	$(foreach MAKE, $(SUB_MAKE),make -C $(MAKE) clean;)

_make_fclean		:
	$(foreach MAKE, $(SUB_MAKE),make -C $(MAKE) fclean;)
