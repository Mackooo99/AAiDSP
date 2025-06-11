CC = gcc
CFLAGS = -Wall -g

SOURCES = main.c wavhdr.c iir.c
OBJECTS = $(SOURCES:.c=.o)
EXEC = program

ARGS ?= /home/maja/Documents/7_semestar/AAiDSP/VS_projekat/TestStreams/speech_2ch.wav /home/maja/Documents/7_semestar/AAiDSP/VS_projekat/Outputs/output1.wav


all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c wavhdr.h iir.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXEC)


run: $(EXEC)
	./$(EXEC) $(ARGS)
