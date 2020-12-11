all: hello

hello: course.o catalog.o uni.o driver.o
	clang++ course.o catalog.o uni.o driver.o
course.o: course.cpp
	clang++ -c course.cpp
catalog.o: catalog.cpp
	clang++ -c catalog.cpp
uni.o: uni.cpp
	clang++ -c uni.cpp
driver.o: driver.cpp
	clang++ -c driver.cpp
clean:
	rm -f *.out *.o
