
pswdGenBuild: main.o generation.o interface.o
	g++ -Wall interface.o main.o generation.o -o pswdGenBuild

main.o: main.cpp
	g++ -c -Wall main.cpp

interface.o: interface.cpp
	g++ -c -Wall interface.cpp

generation.o: generation.cpp
	g++ -c -Wall generation.cpp

run: pswdGenBuild
	./pswdGenBuild
clean:
	rm -f *.o pswdgen

