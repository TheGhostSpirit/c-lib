NAME=c-lib

CC=gcc
LD=ld

CFLAGS=-Wall -fPIC -O3 -I"src" -pedantic --std=c18
HFLAGS=-E -P -I"src"
LDFLAGS=-r

OUT_PATH=out
OBJ_PATH=obj
SRC_PATH=src

UTILS_PATH=$(SRC_PATH)/utils
STRUCT_PATH=$(SRC_PATH)/struct

UTILS=alloc/alloc.c \
	format/format.c \
	logger/logger.c

STRUCT=array-list/array-list.c \
	buffer/buffer.c \
	map/map.c \
	string-wrapper/string-wrapper.c

SRC=$(foreach file,$(UTILS),$(UTILS_PATH)/$(file)) \
	$(foreach file,$(STRUCT),$(STRUCT_PATH)/$(file))

OBJ=$(foreach file,$(SRC:.c=.o),$(OBJ_PATH)/$(notdir $(file)))

all: $(SRC:.c=.o) index.h
	$(LD) $(LDFLAGS) $(OBJ) -o $(OUT_PATH)/$(NAME).o

%.o:
	$(CC) $(CFLAGS) -c $*.c -o $(OBJ_PATH)/$(notdir $@)

index.h:
	$(CC) $(HFLAGS) $(SRC_PATH)/$@ -o $(OUT_PATH)/$(NAME).h
	sed -i "1s/^/#ifndef _CLIB_H\n\n#define _CLIB_H\n/" $(OUT_PATH)/$(NAME).h
	echo "#endif" >> $(OUT_PATH)/$(NAME).h

clean:
	rm -f $(OBJ_PATH)/*.o

mrproper: clean
	rm -f $(OUT_PATH)/*