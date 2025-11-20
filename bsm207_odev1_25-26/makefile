hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Shape.o -c ./src/Shape.cpp
	g++ -I ./include/ -o ./lib/Triangle.o -c ./src/Triangle.cpp
	g++ -I ./include/ -o ./lib/Rectangle.o -c ./src/Rectangle.cpp
	g++ -I ./include/ -o ./lib/Star.o -c ./src/Star.cpp
	g++ -I ./include/ -o ./lib/ShapeList.o -c ./src/ShapeList.cpp
	g++ -I ./include/ -o ./lib/Box.o -c ./src/Box.cpp
	g++ -I ./include/ -o ./lib/BoxList.o -c ./src/BoxList.cpp
	g++ -I ./include/ -o ./lib/Renderer.o -c ./src/Renderer.cpp
	g++ -I ./include/ -o ./lib/FileManager.o -c ./src/FileManager.cpp
	g++ -I ./include/ -o ./lib/InputHandler.o -c ./src/InputHandler.cpp
	g++ -I ./include/ -o ./lib/MenuManager.o -c ./src/MenuManager.cpp
	g++ -I ./include/ -o ./bin/app ./lib/Shape.o ./lib/Triangle.o ./lib/Rectangle.o ./lib/Star.o ./lib/ShapeList.o ./lib/Box.o ./lib/BoxList.o ./lib/Renderer.o ./lib/FileManager.o ./lib/InputHandler.o ./lib/MenuManager.o ./src/main.cpp

calistir:
	./bin/app