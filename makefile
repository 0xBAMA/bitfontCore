all: exe

exe:
	g++ -std=c++17 -o BasicUsageDemo ./Demo/main.cc ./Libs/lodepng.cc
	g++ -std=c++17 -o GrayscaleConvert ./Utilities/gray.cc ./Libs/lodepng.cc
	g++ -std=c++17 -o BasicLoading ./Utilities/uintLoader.cc
