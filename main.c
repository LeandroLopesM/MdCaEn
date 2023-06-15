#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

/******************************

		MODIFIED CAESAR 
          CYPHER
Por KKrainer
********************************
todo:
	- We done
*/

/*int E(int num, int max, int min){
	if(num >= min && num <= max) return 1;
	return 0;
}*/


int save(int* key1, char* into) {
	FILE* out = fopen("out.txt", "w");
	char choice2;
	printf("\n\nDeseja salvar para arquivo? Y/N\n> ");
	scanf("%c", &choice2);
	getchar();
	if (choice2 == 'Y' || choice2 == 'y') {
		fprintf(out, "Chave:  ");
		for (int y = 0; y < sizeof(key1); y++) {
			fprintf(out, "%d", key1[y]);
		}
		fprintf(out, "\nMensagem:  %s", into);
		printf("Salvo");
		getchar();
		fclose(out);
		exit(0);
	}
	else if (choice2 == 'N') {
		printf("Saindo...");
		exit(0);
	}
	else printf("Algo deu errado"); exit(1);
}

/*int asciiflag(char* x){
	char unicodein[150] = {0};
	memcpy(uncodein, x, sizeof(unicodein));
}*/


void crypt(char* rawin) {
	//intialize vars
	char encrypted[150] = { 0 };
	int keygen, klen = 0;
	int keysave[150] = { 0 };
	//copy raw value to new var
	memcpy(encrypted, rawin, strlen(rawin));
	//encrypt
	for (int i = 0; i < strlen(encrypted); i++) {
		//startup keygen
		keygen = rand() % 5 + 1;
		//encrypt
		encrypted[i] = encrypted[i] + keygen;
		//save current key to arr
		keysave[i] = keygen;
		klen++;
	}
//	asciiflag(encrypted);
	//output
	printf("Mensagem criptografada:  %s", encrypted);
	printf("\nChave de criptografia:  ");
	//print keysave
	for (int arr = 0; arr < klen; arr++) {
		printf("%d", keysave[arr]);
	}

	save(keysave, encrypted);
}

void decrypt(char* decrin, char* decrinner) {
	char decrypt[150] = { 0 };
	char keyinput[150] = { 0 };
	int arrayed[150] = { 0 };

	//copy string var
	memcpy(keyinput, decrin, strlen(decrin));
	memcpy(decrypt, decrinner, strlen(decrinner));

	//str to array
	for(int c; c < strlen(keyinput); c++){
		arrayed[c] = keyinput[c];
	}

	//decrypt
	for (int j = 0; j < strlen(decrypt); j++) {
		decrypt[j] = decrypt[j] - arrayed[j];
	}
	printf("\nMensagem descriptografada:  %s", decrypt);
}

int main(void){
	//start keygen
	srand((unsigned)time(NULL));

	//Prompt choice
	int choicemain = 0;
	char raw[150] = "";
	char buff[150] = "";
	printf("1 - Criptografar\n2 - Decriptografar\n> ");
	scanf("%d", &choicemain);
	getchar();


	if (choicemain == 1) {
		//prompt for encrypt
		printf("\nDigite a mensagem a ser criptografada\n> ");
		fgets(raw, 150, stdin);
		crypt(raw);
	}
	else if (choicemain == 2) {
		//prompt for decrypt
		printf("\nEncrypted message\n> ");
		fgets(raw, 150, stdin);

		printf("\nDecryption Key\n> ");
		fgets(buff, 150, stdin);


		//string to array
		//size_t slen = strlen(buff) - 1;
		//int arr[150];
		/*for (size_t i = 0; i < slen; i++) {
			arr[i] = buff[i] - '0';
		}*/

		decrypt(buff, raw);
	}
	else {
		printf("Algo deu errado");
		return 1;
	}
}