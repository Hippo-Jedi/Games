all: hello

hello: room.o player.o wump.o pit.o gold.o bats.o game.o driver.o
	clang++ room.o player.o wump.o pit.o gold.o bats.o game.o driver.o
room.o: room.cpp
	clang++ -c -g room.cpp
player.o: player.cpp
	clang++ -c -g player.cpp
wump.o: wump.cpp
	clang++ -c -g wump.cpp
pit.o: pit.cpp
	clang++ -c -g pit.cpp
gold.o: gold.cpp
	clang++ -c -g gold.cpp
bats.o: bats.cpp
	clang++ -c -g bats.cpp
game.o: game.cpp
	clang++ -c -g game.cpp
driver.o: driver.cpp
	clang++ -c -g driver.cpp
clean:
	rm -f *.out *.o
