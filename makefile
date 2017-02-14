E:/documents/code/c/tank-battle/sources/intro/effect.o: E:/documents/code/c/tank-battle/effect.c E:/documents/code/c/tank-battle/effect.h
	gcc -c effect.c
E:/documents/code/c/tank-battle/sources/intro/intro.o: intro.c intro.h
	gcc -c intro.c
E:/documents/code/c/tank-battle/sources/intro/printfLetter.o: printfLetter.c printfLetter.h
	gcc -c printfLetter.c
main: E:/documents/code/c/tank-battle/sources/intro/effect.o E:/documents/code/c/tank-battle/sources/intro/printfLetter.o E:/documents/code/c/tank-battle/sources/intro/intro.o main.c
	gcc main.c sources/intro/*.o -o main