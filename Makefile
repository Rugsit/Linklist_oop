run: main.exe
	./main.exe
main.exe: clean
	g++ main.cc Linklist.cc Node.cc Sort.cc -o main.exe
clean:
	rm -f *.o main.exe main.a