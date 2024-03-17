CC = clang
FLAGS = -I./ -I./libs/include -L./libs/lib -lstdc++ -lraylib -lglfw -lGL -lm	# -lpthread -ldl -lrt -lX11

game-linux: game.cpp
	$(CC) -o game-linux game.cpp  $(FLAGS)

run-linux: game-linux
	./game-linux
	rm ./game-linux

