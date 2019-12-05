clear && gcc -Wall $1 -o compiled -lm && ./compiled ${@:2}
