.PHONY: build
build:
	CC=clang CXX=clang++ cmake -B ./build -G Ninja -S .
	ninja -C ./build

run: build
	./build/chess

clean:
	rm -rf ./build
