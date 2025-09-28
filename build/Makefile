# make LIB=static STACK=vector (для сборки со статической библиотекой и стеком на массиве)
# make LIB=dynamic STACK=list (для сборки с динамической библиотекой и стеком на списке)
# и т.д.

CC ?= gcc 
CFLAGS ?= -Wall -Wextra
LIB ?= static
STACK ?= vector
LIB_NAME := library_stack
PLAY_IN_15_H := play_in_15.h
TARGET = main

SRCS := $(STACK_SRC) input.c logic.c
OBJS := $(SRCS:.c=.o)

ifeq ($(LIB), static)
	LIB_OPT := $(LIB_NAME).a
	LIB_FLAGS := -L.  $(LIB_OPT)
else 
	ifeq ($(LIB), dynamic)
		LIB_OPT := $(LIB_NAME).so
    	LIB_FLAGS := -L. $(LIB_OPT)
    	CFLAGS += -fPIC
	endif
endif

ifeq ($(STACK), vector)
	STACK_SRC := stack_on_massive.c
	STACK_OPT := -DSTACK_VECTOR
else 
	ifeq ($(STACK), list)
		STACK_SRC := stack_on_list.c
		STACK_OPT := -DSTACK_LIST
	endif
endif

ifeq ($(LIB), dynamic)
    LDFLAGS += -Wl,-rpath,.
endif

.PHONY: all

all:$(TARGET)

$(TARGET): $(LIB_OPT) main.c
	$(CC) $(CFLAGS) $(STACK_OPT) main.c -o $@ $(LIB_FLAGS) $(LDFLAGS)

$(LIB_NAME).a: $(OBJS)
	ar rcs $@ $^

$(LIB_NAME).so: $(OBJS)
	$(CC) -shared -o $@ $^

%.o: %.c $(PLAY_IN_15_H)
	$(CC) $(CFLAGS) $(STACK_OPT) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS) $(LIB_NAME).a $(LIB_NAME).so