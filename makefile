CC = gcc
CFLAGS = -Wall -g
OBJ_REC= advancedClassificationRecursion.o basicClassClassification.o
OBJ_LOOP= advancedClassificationLoop.o basicClassClassification.o 

all:loopd maindrec maindloop mains recursives recursived loops

# Create static library with OBJ_LOOP
loops: libclassloops.a

# Create shared library with OBJ_LOOP
loopd: libclassloops.so

# Create static library with OBJ_REC
recursives: libclassrec.a

# Create shared library with OBJ_REC
recursived: libclassrec.so

# Build main with static recursive
mains: main.o libclassrec.a 
	$(CC) $(CFLAGS) main.o ./libclassrec.a -o mains

# Build main with dynamic recursive
maindrec: main.o libclassrec.so 
	$(CC) $(CFLAGS) main.o ./libclassrec.so -o maindrec
		
# Build main with dynamic loops
maindloop: main.o libclassloops.so 
	$(CC) $(CFLAGS) main.o ./libclassloops.so -o maindloop

# Compile main.c
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

# Create static library with OBJ_LOOP
libclassloops.a: $(OBJ_LOOP)
	ar rcs $@ $^

# Create shared library with OBJ_LOOP
libclassloops.so: $(OBJ_LOOP)
	$(CC) -shared -fpic -o $@ $^

# Create static library with OBJ_REC
libclassrec.a: $(OBJ_REC)
	ar rcs $@ $^

# Create shared library with OBJ_REC
libclassrec.so: $(OBJ_REC)
	$(CC) -shared -fpic -o $@ $^
# clean all
 clean:
	rm -f *.o *.a *.so mains maindrec maindloop