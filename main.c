//***randomizzare le parole***
//
//è data una stringa di caratteri contenente parole separate dal carattere spazio
//
//randomizzare le parole per produrre una nuova stringa di caratteri
//vanno riutilizzate tutte le singole parole (una sola volta ciascuna)
//
//[generatore di numeri casuali:
//aggiungerò a breve un esempio in exOpSys che utilizza la funzione rand()
//http://man7.org/linux/man-pages/man3/rand.3.html ]
//
//esempio:
//
//è data la stringa di caratteri:
//"hello world mi chiamo pino sono date delle stringhe"
//
//
//output:
//"mi stringhe chiamo pino sono date world delle hello"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

typedef struct{
	char *word;
} phrase;

int random_positioning(int max);
void swap_word(phrase *phrase, int *position);

int main(int argc, char *argv[]) {
	phrase *line;
	scanf("Inserire la frase da randomizzare", &line);		//ERRORE NEL SALVATAGGIO DELLA FRASE LETTA
	int length = sizeof(phrase)/sizeof(char);
	for(int i=0; i<length; i++){
		swap_word(line, random_positioning(random_positioning));
	}

	return 0;
}

int random_positioning(int max){
	time_t t = time(NULL);
	srand(t);
	int size = 2;
	int *random_number = calloc(size, sizeof(int));
	random_number[0] = rand() % max;
	random_number[1] = rand() % max;
	return random_number;
}

void swap_word(phrase *line, int *position) {
	char *word = line[position[0]].word;
	line[position[0]].word = line[position[1]].word;
	line[position[1]].word = word;
}