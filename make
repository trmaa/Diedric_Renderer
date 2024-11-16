#!/bin/bash

SRC="./src"
INCLUDE="./include"
LIB="./lib"
BIN="./bin"

FLAGS="-lsfml-graphics -lsfml-window -lsfml-system -ltbb"

compile() {
	g++ -c $SRC/*.cpp -I$INCLUDE -o $BIN/%.o
    g++ $BIN/*.o -o ./app -L$LIB $FLAGS
}

run() {
	./app
}

commit() {
	git add .
	git commit -m $1
	git push
}

main() {
	for callback in "$@"; do
		if declare -f "$callback" > /dev/null; then
			"$callback"
		else
			error "Error: Function '$callback' not found."
		fi
	done
}

main "$@"
