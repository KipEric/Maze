build:
	gcc -Wall -Wpedantic -Werror -Wextra -std=gnu89 -Iheader src/*.c -lm -lSDL2 -lSDL2_image -o maze

run:
	./maze

clean:
	rm maze
