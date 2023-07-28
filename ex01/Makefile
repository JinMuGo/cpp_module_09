# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 19:34:14 by jgo               #+#    #+#              #
#    Updated: 2023/07/28 18:39:31 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../make_config/Color.mk
include ../make_config/Rules.mk
include ../make_config/Funcs.mk
include ../make_config/Flags.mk

SRCS := main.cpp

NAME :=	RPN

OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)
-include $(DEPS)

include ../make_config/Recipes.mk
