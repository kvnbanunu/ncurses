build:
	gcc -lncurses main.c external.c game.c -o game

run: build
	./game

clean:
	rm game
