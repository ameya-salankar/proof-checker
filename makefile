IDIR1=Part1/include
IDIR2=Part2/include
ODIR1=Part1/obj
ODIR2=Part2/obj
SDIR1=Part1/src
SDIR2=Part2/src
CC=g++
CFLAGS=-I$(IDIR1) -I$(IDIR2) -std=c++11
# VPATH = src:../src

DEP=start.h

_DEPS1=tree.h postfix.h
DEPS1= $(patsubst %,$(IDIR1)/%,$(_DEPS1))
_OBJ1=start1.o tree.o postfix.o
OBJ1 = $(patsubst %,$(ODIR1)/%,$(_OBJ1))

_DEPS2=and.h helpers.h impl.h or.h postfix.h
_DEPS22= $(patsubst %,$(IDIR2)/%,$(_DEPS2))
DEPS2= $(patsubst $(IDIR2)/postfix.h,$(IDIR1)/postfix.h,$(_DEPS22))
_OBJ2=start2.o check.o helpers.o impl.o or.o and.o postfix.o
_OBJ22 = $(patsubst %,$(ODIR2)/%,$(_OBJ2))
OBJ2 = $(patsubst $(ODIR2)/postfix.o,$(ODIR1)/postfix.o,$(_OBJ22))

# Debugging output
# $(info $$DEPS2 is [${DEPS2}])
# $(info $$OBJ2 is [${OBJ2}])

$(ODIR1)/%.o: $(SDIR1)/%.cpp $(DEPS1) $(DEP)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR2)/%.o: $(SDIR2)/%.cpp $(DEPS1) $(DEPS2) $(DEP)
	$(CC) -c -o $@ $< $(CFLAGS)

a.out: $(OBJ1) $(OBJ2) $(ODIR2)/main.o
	$(CC) -o $@ $^ $(CFLAGS)

$(ODIR2)/main.o: main.cpp $(DEPS1) $(DEPS2) $(DEP)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -r $(ODIR1)/*.o
	rm -r $(ODIR2)/*.o