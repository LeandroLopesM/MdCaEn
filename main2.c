#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/*
  USED UP
  i
  j
  klen
*/

void encryption(char* buffer){
  char encrypt[50] = {0};
  int key1 = 0, keysave[50] = {0}, klen = 0, i = 0, j = 0;
  memcpy(encrypt, buffer, sizeof(encrypt));

  while(i != strlen(encrypt)){
    key1 = rand() % 10;
    
    if(encrypt[i] >= 97 && encrypt[i] <= 122){
      encrypt[i] = (encrypt[i] - 10) + key1;
    }else {
      encrypt[i] = encrypt[i] + key1;
    }
    keysave[i] = key1;

    klen++;
    i++;
  }

  printf("MsgOut:  %s\n KeyOut:  ", encrypt);
  while(j != klen){
    printf("%d", keysave[j]);
    j++;
  }
}

void decrypt(int keybuff, char* secbuffer){
  char decrypt[50] = {0};
  memcpy(decrypt, secbuffer, strlen(secbuffer));

  int deckey = 0, keysave[50] = {0}, x = 0;

  while(x != strlen(decrypt)){
    decrypt[x] = (decrypt[x] + 10) - keybuff;
  }
  printf("MsgDecOut:  %s", decrypt);
}

int main(void){
  srand(time(NULL));
  int choice = 0, key = 0;
  char userin[50];

  printf("1-Crypt\n2-Encrypt\n> ");
  choice = getchar();
  getchar();

  if(choice == 49){
    printf("Msg:  ");
    fgets(userin, strlen(userin), stdin);

    encryption(userin);
  }else if(choice == 2){
    printf("Msg:  ");
    fgets(userin, strlen(userin), stdin);

    printf("Key:  ");
    scanf("%d", &key);

    decrypt(key, userin);
  }
}