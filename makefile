LIBRARIES =-lfcgi
CFLAGS =-Wall -std=c99
SRC =src/
BIN =bin/

all:
	gcc $(CFLAGS) $(SRC)hello.c $(SRC)myhttp.c -o $(BIN)hello $(LIBRARIES)

deploy: 
	gcc $(CFLAGS) $(SRC)hello.c $(SRC)myhttp.c -o $(BIN)hello $(LIBRARIES)
	-killall -q hello
	spawn-fcgi -a127.0.0.1 -p9000 -n ./$(BIN)hello &

clean:
	rm -rf $(BIN)*
