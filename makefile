# Define the C compiler to use
CC = gcc
# Define any directories containing header files other than /usr/include
AR = ar
# Define any compile-time flags
FLAGS = -Wall -g

#OBJECTS_MAIN = main.o basicClassification.o advancedClassificationLoop.o advancedClassificationRecursion.o

OBJECTS_BASIC = basicClassification.o 
OBJECTS_LOOP = advancedClassificationLoop.o 
OBJECTS_RECURSION = advancedClassificationRecursion.o
OBJECTS_MAIN = main.o



# make run files:
all: mains maindloop maindrec loops recursives loopd recursived

mains: $(OBJECTS_MAIN) libclassrec.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libclassrec.a

maindloop: $(OBJECTS_MAIN) libclassloops.so
	$(CC) $(FLAGS) -o maindloop $(OBJECTS_MAIN) ./libclassloops.so

maindrec: $(OBJECTS_MAIN) libclassrec.so
	$(CC) $(FLAGS) -o maindrec $(OBJECTS_MAIN) ./libclassrec.so

loops: libclassloops.a

recursives: libclassrec.a

recursived: libclassrec.so

loopd: libclassloops.so

# init static libraries:
libclassloops.a: $(OBJECTS_LOOP) $(OBJECTS_BASIC) 
	$(AR) -rcs libclassloops.a $(OBJECTS_LOOP) $(OBJECTS_BASIC)

libclassrec.a: $(OBJECTS_RECURSION) $(OBJECTS_BASIC)
	$(AR) -rcs libclassrec.a $(OBJECTS_RECURSION) $(OBJECTS_BASIC)

# init dynamic libraries:
libclassloops.so: $(OBJECTS_LOOP) $(OBJECTS_BASIC)
	$(CC) -shared -o libclassloops.so $(OBJECTS_LOOP) $(OBJECTS_BASIC)

libclassrec.so: $(OBJECTS_RECURSION) $(OBJECTS_BASIC)
	$(CC) -shared -o libclassrec.so $(OBJECTS_RECURSION) $(OBJECTS_BASIC)



# init .o files:

main.o: main.c NumClass.h 
	$(CC) $(CFLAGS) -c main.c -o $@

basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(CFLAGS) -c basicClassification.c -o $@

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(CFLAGS) -c advancedClassificationLoop.c -o $@

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(CFLAGS) -c advancedClassificationRecursion.c -o $@

	


# clean all files:
make clean:
	rm *.o *.so *.a mains maindloop maindrec
