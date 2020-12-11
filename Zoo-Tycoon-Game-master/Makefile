all: hello

hello: zoo.o animal.o tiger.o sealion.o blackbear.o driver.o
	clang++ zoo.o animal.o tiger.o sealion.o blackbear.o driver.o
zoo.o: zoo.cpp
	clang++ -c -g zoo.cpp
animal.o: animal.cpp
	clang++ -c -g animal.cpp
tiger.o: tiger.cpp
	clang++ -c -g tiger.cpp
sealion.o: sealion.cpp
	clang++ -c -g sealion.cpp
blackbear.o: blackbear.cpp
	clang++ -c -g blackbear.cpp
driver.o: driver.cpp
	clang++ -c -g driver.cpp
clean:
	rm -f *.out *.o 
