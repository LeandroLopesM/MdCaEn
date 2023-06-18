#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void save(char* message, int* key){
	FILE *out = fopen("out.txt", "w");
	char saveor = 'p';

	printf("\nWould you like to save? [Y/N]\n>");
	scanf("%c", &saveor);
	getchar();

	if(saveor == 'y' || saveor == 'Y'){

		fprintf(out, "\nMensagem:  %s", message);
		fprintf(out, "\nChave:  ");

		for (int y = 0; y < (int)sizeof(key); y++) {
			fprintf(out, "%d", key[y]);
		}

		printf("Saved");
		fclose(out);

		getchar();

		exit(0);
	} else if(saveor == 'n' || saveor == 'N'){
		printf("Exiting...");
		exit(0);
	} else{
		printf("Algo went errado");
		exit(1);
	}
}

int numPlaces (int n) {
    if (n < 10) return 1;
    if (n < 100) return 2;
    if (n < 1000) return 3;
    if (n < 10000) return 4;
    if (n < 100000) return 5;
    if (n < 1000000) return 6;
    if (n < 10000000) return 7;
    if (n < 100000000) return 8;
    if (n < 1000000000) return 9;
	return 0;
}

void strtoarr(int number, int* array, int numDigits) {
    int temp = number;
    int divisor = 1;

    for (int i = 0; i < numDigits - 1; i++) {
        divisor *= 10;
    }
    
    for (int i = 0; i < numDigits; i++) {
        array[i] = temp / divisor;  
        temp = temp % divisor; 
        divisor = divisor / 10;
    }
}

int keygen(int max){
	int key = rand() % max + 1;
	return key;
}

void encrypt(char* rawmsg){
	int key = 0, keyleng = 0, keyarr[50] = {0};

	for(int i = 0; i < (int)strlen(rawmsg); i++, keyleng++){
		key = keygen(10);

		rawmsg[i] = rawmsg[i] + key;

		keyarr[i] = key;
	}
	printf("Message:  %s\n", rawmsg);
	printf("Key:  ");
	for(int i = 0; i < keyleng; i++){printf("%d", keyarr[i]);}
	save(rawmsg, keyarr);
	exit(0);
}

void decrypt(int* key, char* encrin){
	for(int i = 0; i < (int)strlen(encrin); i++){
		encrin[i] = encrin[i] - key[i];
	}
	printf("Decripted:  %s\n", encrin);
}

int main(void){
	srand(time(NULL));

	int userchoice = 0, keyarr[100], keyin = 0, intlen = 0;
	char userin[50] = "";

	printf("1 - Encrypt\n2 - Decrypt\n> ");
	scanf("%d", &userchoice);
	getchar();

	if(userchoice == 1){
		printf("Message\n> ");
		fgets(userin, 50, stdin);
		encrypt(userin);
	}
	else if(userchoice == 2){
		printf("Mesage\n> ");
		fgets(userin, 50, stdin);
		printf("Key\n> ");
		scanf("%d", &keyin);
		intlen = numPlaces(keyin);
		strtoarr(keyin, keyarr, intlen);

		decrypt(keyarr, userin);

		exit(2);
	}
}