.PHONY: build
build:
	CC=clang CXX=clang++ cmake -B ./build -G Ninja -S .
	ninja -C ./build

run: build
	./build/main

clean:
	rm -rf ./build

clean-clion:
	rm -rf ./.idea
	rm -rf cmake-build-debug
