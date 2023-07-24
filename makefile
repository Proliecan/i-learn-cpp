

hello-world:
	g++ ./hello-world.cpp -o ./hello-world

args:
	g++ ./args.cpp	-o ./args

file-reading:
	g++ ./file-system/file-reading.cpp -o ./file-system/file-reading

file-writing:
	g++ ./file-system/file-writing.cpp ./file-system/print.cpp -o ./file-system/file-writing