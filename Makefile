COMPILER=g++
CFALGS=-Wall -g
CCO=$(COMPILER) $(CFALGS) -c
CC=$(COMPILER) $(CFALGS)
RM=rm -rf

OUTPUT=model.exe
ALLFILES=Outtputter.o Initializer.o GridField.o LeapFrogMethod.o
MAIN=main.cpp

all: $(ALLFILES)
	$(CC) $(MAIN) $(ALLFILES) -o $(OUTPUT)
	
Outtputter.o:
	$(CCO) Outtputter.cpp

Initializer.o:
	$(CCO) Initializer.cpp
	
GridField.o:
	$(CCO) GridField.cpp

LeapFrogMethod.o:
	$(CCO) LeapFrogMethod.cpp

	
clean:
	$(RM) *.o
	$(RM) *.exe
	$(RM) *.txt
	$(RM) *~
	clear

run:

	./$(OUTPUT)
