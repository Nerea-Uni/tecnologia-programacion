PROG:=main
SRCS:=instruccion.cc programa.cc main.cc

CXX:= g++ -O2

OBJS:=$(SRCS:.cc=.o)

all: $(PROG) main.s

$(PROG): $(OBJS)
	$(CXX) -o $@ $(OBJS)

.cc.o:
	$(CXX) -c $<

edit:
	geany -s *.h *.cc &

clean:
	@rm -f $(PROG) $(OBJS) core *.s

instruccion.o: instruccion.cc instruccion.h
programa.o: programa.cc programa.h
main.o: main.cc instruccion.h programa.h
main.s: main.cc instruccion.h programa.h