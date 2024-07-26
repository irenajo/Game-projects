all:compile link clean
test:compile link run clean
link:
	g++ *.o -o main -L lib -l sfml-graphics -l sfml-window -l sfml-system -l sfml-audio 
compile:
	g++ -Iinclude -Iheaders -c *.cpp cpp/*.cpp
run:
	./main.exe
clean:
	del *.o