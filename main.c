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
void swap_word(phrase *phrase, int position, int i);


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
		words = realloc(words, position * sizeof(phrase));
    token = strtok(NULL, s);
  }

	for(int i=0; i<position; i++){
		swap_word(words, position, i);
	} 

  for(int i=0; i<position; i++){
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

void swap_word(phrase *line, int position, int i) {      
// FUNZIONA MA HO UN PO' IMBROGLIATO, DA MIGLIORARE!!
/*int validate = 0;
  int *verify = calloc(position, sizeof(int));
  int count = 0;

  while(count < position){
    int rand = random_positioning(position);
    if (verify[rand] == 0){
      verify[rand] = 1;
      if(line[rand].word != NULL){
        printf("%s\n", line[rand].word);
      }
    }
    count++;
  }*/
  char *word = calloc(line[i].size, sizeof(char));
  int random = random_positioning(position);
  strcpy(word, line[i].word);
  strcpy(line[i].word, line[random].word);
  strcpy(line[random].word, word); 
}