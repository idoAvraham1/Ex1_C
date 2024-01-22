CC = gcc
CFLAGS = -Wall

all: recursives recursived  loopd loops  maindrec maindloop  mains

#loops static library
loops: advancedClassificationLoop.o basicClassClassification.o
	ar rcs libclassloops.a advancedClassificationLoop.o basicClassClassification.o

advancedClassificationLoop.o: advancedClassificationLoop.c
	$(CC) $(CFLAGS) -c advancedClassificationLoop.c


# loops dynamic library
loopd: advancedClassificationLoop_dynamic.o basicClassClassification_dynamic.o
	$(CC) -shared -o libclassloops.so advancedClassificationLoop.o basicClassClassification.o

advancedClassificationLoop_dynamic.o:  advancedClassificationLoop.c
	$(CC) $(CFLAGS) -fPIC -c advancedClassificationLoop.c



#recursive static lirary
recursives: advancedClassificationRecursion.o basicClassClassification.o
	ar rcs libclassrec.a advancedClassificationRecursion.o basicClassClassification.o

advancedClassificationRecursion.o: advancedClassificationRecursion.c
	$(CC) $(CFLAGS) -c advancedClassificationRecursion.c

basicClassClassification.o: basicClassClassification.c
	$(CC) $(CFLAGS) -c basicClassClassification.c



# recursive dynamic library
recursived: advancedClassificationRecursion_dynamic.o basicClassClassification_dynamic.o
	$(CC) -shared -o libclassrec.so advancedClassificationRecursion.o basicClassClassification.o

advancedClassificationRecursion_dynamic.o: advancedClassificationRecursion.c
	$(CC) $(CFLAGS) -fPIC -c advancedClassificationRecursion.c

basicClassClassification_dynamic.o: basicClassClassification.c
	$(CC) $(CFLAGS) -fPIC -c basicClassClassification.c



# main with static recursive
mains: main.c libclassrec.a
	$(CC) $(CFLAGS) main.c -L. -lclassrec -o mains

# main with dynamic recursive
maindrec: main.c libclassrec.so
	$(CC) $(CFLAGS) main.c -L. -lclassrec -o maindrec
		
#main with dynamic loops
maindloop: main.c libclassloops.so
	$(CC) $(CFLAGS) main.c -L. -lclassloops -o maindloop


# clean all
 clean:
	rm -f *.o *.a *.so mains maindrec maindloop