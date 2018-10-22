IDIR=include
ODIR=obj
CC=g++
CFLAGS=-I$(IDIR) -std=c++11
VPATH = src:../src

_DEPS=tree.h postfix.h
DEPS= $(patsubst %,$(IDIR)/%,$(_DEPS))
_OBJ=main.o tree.o postfix.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

a.out: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm $(ODIR)/*.o