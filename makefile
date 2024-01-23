CC = gcc
CFLAGS = -Wall -g

#recursives recursived loops

all:loopd maindrec maindloop mains

#loops static library
loops: libclassloops.a

 libclassloops.a :advancedClassificationLoop.o basicClassClassification.o 
	ar rcs libclassloops.a advancedClassificationLoop.o basicClassClassification.o

advancedClassificationLoop.o: advancedClassificationLoop.c  NumClass.h
	$(CC) $(CFLAGS) -c advancedClassificationLoop.c



#recursive static lirary
recursives:libclassrec.a

libclassrec.a: advancedClassificationRecursion.o basicClassClassification.o
	ar rcs libclassrec.a advancedClassificationRecursion.o basicClassClassification.o

advancedClassificationRecursion.o: advancedClassificationRecursion.c  NumClass.h
	$(CC) $(CFLAGS) -c advancedClassificationRecursion.c

basicClassClassification.o: basicClassClassification.c  NumClass.h
	$(CC) $(CFLAGS) -c basicClassClassification.c



# loops dynamic library
loopd: libclassloops.so

libclassloops.so: advancedClassificationLoop.o basicClassClassification.o
	$(CC) -shared -o libclassloops.so advancedClassificationLoop.o basicClassClassification.o

#advancedClassificationLoop_dynamic.o:  advancedClassificationLoop.c NumClass.h
#	$(CC) $(CFLAGS) -fPIC -c advancedClassificationLoop.c


# recursive dynamic library
recursived:libclassrec.so

libclassrec.so: advancedClassificationRecursion.o basicClassClassification.o
	$(CC) -shared -o libclassrec.so advancedClassificationRecursion.o basicClassClassification.o

#advancedClassificationRecursion_dynamic.o: advancedClassificationRecursion.c  NumClass.h

#	$(CC) $(CFLAGS) -fPIC -c advancedClassificationRecursion.c

#basicClassClassification_dynamic.o: basicClassClassification.c  NumClass.h
#	$(CC) $(CFLAGS) -fPIC -c basicClassClassification.c




main.o: main.c
	$(CC) $(CFLAGS) -c main.c


# main with static recursive
mains: main.o libclassrec.a 
	$(CC) $(CFLAGS) main.o ./libclassrec.a -o mains

# main with dynamic recursive
maindrec: main.o libclassrec.so 
	$(CC) $(CFLAGS) main.o ./libclassrec.so -o maindrec
		
#main with dynamic loops
maindloop: main.o libclassloops.so 
	$(CC) $(CFLAGS) main.o ./libclassloops.so -o maindloop


# clean all
 clean:
	rm -f *.o *.a *.so mains maindrec maindloop