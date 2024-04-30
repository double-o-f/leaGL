all:
	gcc -o build/leaGL src/main.c src/shadercomp.c src/glad.c src/windowinit.c src/tri.c -Iinclude -ldl -lglfw -g
