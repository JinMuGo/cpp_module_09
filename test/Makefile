include ../make_config/Color.mk
include ../make_config/Funcs.mk
include ../make_config/Flags.mk

ifndef TOPDIR
	TOPDIR := $(abspath ../)
endif

.DEFAULT_GOAL := all
CXXFLAGS += -g3 -std=c++11

SRCS := ex02_tester.cpp

NAME := ex02_tester
OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)
-include $(DEPS)

include ../make_config/Recipes.mk
