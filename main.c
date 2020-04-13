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
#include <string.h>

#define MAX_LENGTH 50

int *random_array(int count) {
    int *array = calloc(count, sizeof(int));
    if(array == NULL) {
        printf("\ncalloc error!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        int random = rand() % count;
        array[i] = random;
        for (int j = 0; j < i; j++) {
            if (array[i] == array[j]) {
                i--;
                break;
            }
        }
    }
    return array;
}

int main(int argc, char *argv[]) {
	char *line= calloc(1, sizeof(char));
	char c;
	int counter = 0;

	printf("Scrivi la frase da randomizzare:  ");

	while ((c=getchar()) != '\n') {
		line[counter] = c;
		counter++;
		line = realloc(line, (counter+1) * sizeof(char));
	}

    char separatori[] = " ";
    char *token;
    char *new_line[MAX_LENGTH];
    token = strtok(line, separatori);
    new_line[0] = token;
    int count = 0;
    while (token != NULL) {
        token = strtok(NULL, separatori);
        count++;
        new_line[count] = token;
    }

    printf("Il numero di parole rilevate nella frase inserita sono: %d\n\n", count);

    int *random_order = random_array(count);
    for (int i = 0; i < count; i++) {
        int index = random_order[i];
        printf("%s ", new_line[index]);
    }

    free(random_order);

    return 0;
}