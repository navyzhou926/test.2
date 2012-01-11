SRC = $(wildcard *.c)
OBJ	= $(patsubst %.c, %.o, $(SRC))
CC := gcc
INC_FLAGS := ./inc
CFLAGS := -g
LINK_FLAGS := -o
TARGET = str

$(TARGET):$(OBJ)
	$(CC) $(CFLAGS) $^ $(LINK_FLAGS) $@
%.o:%.c
	$(CC) $(CFLAGS) -c $^ -I $(INC_FLAGS) $(LINK_FLAGS) $@
clean:
	rm -rf $(OBJ)
	rm $(TARGET)

	@echo $(OBJ)
