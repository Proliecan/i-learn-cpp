

hello-world: ./hello-world.cpp 
	g++ ./hello-world.cpp -o ./hello-world

args: ./args.cpp
	g++ ./args.cpp	-o ./args

file-reading: ./file-system/file-reading.cpp
	g++ ./file-system/file-reading.cpp -o ./file-system/file-reading

file-writing: file-writing.o print.o
	g++ ./file-system/file-writing.o ./file-system/print.o -o ./file-system/file-writing

file-writing.o: ./file-system/file-writing.cpp
	g++ -c ./file-system/file-writing.cpp -o ./file-system/file-writing.o

print.o: ./file-system/print.o ./file-system/print.h
	g++ -c ./file-system/print.cpp -o ./file-system/print.o
