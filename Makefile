CFLAGS = -Wall -O2 -I.

all: bouncing_ghosts jumping_blocks stable_mover sticky_edge trap

bouncing_ghosts: matrix_lib.o bouncing_ghosts.c
	$(CC) $(CFLAGS) bouncing_ghosts.c matrix_lib.o -o bouncing_ghosts

jumping_blocks: matrix_lib.o jumping_blocks.c
	$(CC) $(CFLAGS) jumping_blocks.c matrix_lib.o -o jumping_blocks

stable_mover: matrix_lib.o stable_mover.c
	$(CC) $(CFLAGS) stable_mover.c matrix_lib.o -o stable_mover

sticky_edge: matrix_lib.o sticky_edge.c
	$(CC) $(CFLAGS) sticky_edge.c matrix_lib.o -o sticky_edge

trap: matrix_lib.o trap.c
	$(CC) $(CFLAGS) trap.c matrix_lib.o -o trap

matrix_lib.o: matrix_lib.c matrix_lib.h
	$(CC) matrix_lib.c -c -o matrix_lib.o

clean:
	- rm matrix_lib.o bouncing_ghosts jumping_blocks stable_mover sticky_edge trap
