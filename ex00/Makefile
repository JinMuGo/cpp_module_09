# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 19:34:14 by jgo               #+#    #+#              #
#    Updated: 2023/07/25 10:09:23 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../make_config/Color.mk
include ../make_config/Rules.mk
include ../make_config/Funcs.mk
include ../make_config/Flags.mk

SRCS := main.cpp

NAME :=	btc

OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)
-include $(DEPS)

include ../make_config/Recipes.mk
