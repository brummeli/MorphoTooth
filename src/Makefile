CC=g++

CADD=-std=c++11

CFLAGS=-g -Wall $(WARNINGS)
ifdef OPT
  CFLAGS=-O3 $(WARNINGS)
endif

COPT=-c $<  -o $@  $(CFLAGS) $(CADD)

TARGETS= Geometrics.o Initial.o Input.o Model.o Noise.o Output.o Print.o ProgramMorphoTooth.o Utility.o ModelParams.o

all: $(TARGETS)


Geometrics.o: Geometrics.cpp Geometrics.h ImplementParams.h consts.h Model.h
	$(CC) $(COPT)
Initial.o: Initial.cpp Initial.h Cell.h ImplementParams.h Geometrics.h consts.h
	$(CC) $(COPT)
Input.o: Input.cpp Input.h Utility.h json.h
	$(CC) $(COPT)
Model.o: Model.cpp Model.h Geometrics.h ImplementParams.h consts.h Noise.h Utility.h
	$(CC) $(COPT)
Noise.o: Noise.cpp Noise.h Input.h
	$(CC) $(COPT)
Output.o: Output.cpp Output.h consts.h ImplementParams.h Geometrics.h
	$(CC) $(COPT)
Print.o: Print.cpp Print.h
	$(CC) $(COPT)
ProgramMorphoTooth.o: ProgramMorphoTooth.cpp ProgramMorphoTooth.h Input.h Initial.h Output.h Geometrics.h Model.h ImplementParams.h ModelParams.h consts.h Print.h Utility.h
	$(CC) $(COPT)
Utility.o: Utility.cpp Utility.h Cell.h
	$(CC) $(COPT)
ModelParams.o: ModelParams.cpp ModelParams.h
	$(CC) $(COPT)

clean:
	rm -f *.o $(TARGETS)

