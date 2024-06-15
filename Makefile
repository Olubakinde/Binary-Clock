# Makefile

INCLUDE := -I ~/include
LDFLAGS := -L ~/lib -lsense -lm

all: clockdisplay

clockdisplay: main.o display.o
        cc -o clockdisplay main.o display.o $(LDFLAGS)

run: clockdisplay
        chmod +x clock.sh  # Grant execution permissions to the script
        ./clock.sh | ./clockdisplay

clean:
        rm -f *.o clockdisplay

main.o: main.c display.h
        cc -c main.c $(INCLUDE)

display.o: display.c display.h
        cc -c display.c $(INCLUDE)
