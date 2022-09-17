make: kompiliere_Algorithmus ausfuehren_des_Algorithmus

ausfuehren_des_Algorithmus:
	./Algorithmus.elf

kompiliere_Algorithmus: kompiliere_static_Algorithmus
	gcc Algorithmus.c -lAlgorithmus_static -o Algorithmus.elf -lm

kompiliere_static_Algorithmus:
	gcc Algorithmus_static.c -c
	ar -crs libAlgorithmus_static.a Algorithmus_static.o
	sudo cp Algorithmus_static.h /usr/include
	sudo cp libAlgorithmus_static.a /usr/lib
