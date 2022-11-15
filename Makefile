C_SOURCES = $(wildcard matriz/*.c neurona/*.c utilidades/*.c *.c)
HEADERS = $(wildcard matriz/*.h neurona/*.h utilidades/*.h *.h)
OBJ = ${C_SOURCES:.c=.o}
CFLAGS = 

MAIN = main
CC = /usr/bin/gcc
LINKER = /usr/bin/ld

run: ${MAIN}
	./${MAIN}

main: ${OBJ}
	${CC} ${CFLAGS} $^ -o $@ -lm

# Generic rules
%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -c $< -o $@ -lm

clean:
	rm matriz/*.o *.o neurona/*.o utilidades/*.o ${MAIN}
