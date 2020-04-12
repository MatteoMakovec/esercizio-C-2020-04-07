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
  int size;
} phrase;

int random_positioning(int max);
void swap_word(phrase *phrase, int position);


int main(int argc, char *argv[]) {
  char * str= calloc(1, sizeof(char));
	char c;
	int counter = 0;

  printf("Scrivi la frase da randomizzare:  ");

	while ((c=getchar()) != '\n'){
		str[counter] = c;
		counter++;
		str = realloc(str, (counter+1) * sizeof(char));
	}

  char s[] = " .,;";
  char *token;
  int position = 1;
  phrase *words = calloc(position, sizeof(phrase));

  token = strtok(str, s);
  while (token != NULL ) {
    words[position-1].word = token;
    words[position-1].size = sizeof(token) / sizeof(char);
    position++;
		str = realloc(str, (counter+1) * sizeof(char));
    token = strtok(NULL, s);
  }
  
	for(int i=0; i<position; i++){
		swap_word(words, position);
	} 

  for(int i=0; i<position-1; i++){
    printf("%d: %s\n", i, words[i].word);
  }

	return 0;
}


int random_positioning(int max){
	time_t t = time(NULL);
	srand(t);
	int random_number = rand() % max;
	return random_number;
}

void swap_word(phrase *line, int position) {      
// NON FUNZIONA LA RANDOMIZZAZIONE DELL'ORDINE DELLE PAROLE
  for(int i=0; i<position; i++){
    char *word = line[i].word;
    line[i].word = line[random_positioning(position)].word;
    line[random_positioning(position)].word = word;
  }
}