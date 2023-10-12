TARGETS = info pendulum linear_algebra sqrt test

CFLAGS = -O3
WARNINGS = -Wall -Wconversion
CC = gcc

all: $(TARGETS)

debug: CFLAGS += -DDEBUG -g
debug: all

info: info.c
	$(CC) $(WARNINGS) $(CFLAGS) $< -o $@ -lm

pendulum: pendulum.c
	$(CC) $(WARNINGS) $(CFLAGS) $< -o $@ -lm

linear_algebra: linear_algebra.c
	$(CC) $(WARNINGS) $(CFLAGS) $< -o $@ -lm	

sqrt: sqrt.c
	$(CC) $(WARNINGS) $(CFLAGS) $< -o $@ -lm	

test: unittests.c
	$(CC) $(WARNINGS) $(CFLAGS) $< -o $@ -lm

.PHONY: clean
clean:
	rm -rf *~ *.o $(TARGETS) auto/ *.dSYM
