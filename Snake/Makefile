all:compile link clean
test:compile link run clean
test-static: compile link-static run clean
link:
	g++ *.o -o main -L lib -l sfml-graphics -l sfml-window -l sfml-system -l sfml-audio 
link-static:
	g++ *.o -o main-static -L lib -l sfml-graphics-s -l jpeg -l sfml-window-s -l sfml-system-s -l opengl32 -l freetype 
compile:
	g++ -Iinclude -Iheaders -c *.cpp cpp/*.cpp
run:
	./main.exe
clean:
	del *.o