#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char encrypt_Char(char character,int key);
char in_San(char *args[], char *key, int *key_Len, char *message, int *mes_Len);

int main(int argc, char *args[]) {
//gcc polyalphabetic_Cipher.c && ./a.out abc "Hello World"
//char b/c it uses less memory
	char low_Off = 96;
	char up_Off  = 64;
	char *key;
	int key_Len;
	char *message;
	int mes_Len;
	if(argc == 3) {
		if(strlen(args[1]) <= 32) {
			key = args[1];
			key_Len = strlen(key);
		}
		else {
			puts("Sorry but your key is too long");
			return -1;
		}
		if(strlen(args[2]) <= 64) {
			message = args[2];
			mes_Len = strlen(message);
		}
		else {
			puts("Sorry but your message is too long");
			return -1;
		}
		
		int i = 0;
		for(;i < key_Len; i++) {
			if(key[i] >= 'a' && key[i] <= 'z') {
				key[i] -= low_Off;
			}
			else if(key[i] >= 'A' && key[i] <= 'Z') {
				key[i] -= up_Off;
			}
		}
		i = 0;
		int j = 0;
		for(;i < mes_Len;i++) {
			if(message[i] != '\0') {
				message[i] = encrypt_Char(message[i],key[j]);
			}
			else {
				i = mes_Len;
			}
			j++;
			if(j==key_Len) {
				j = 0;
			}
		}
		puts(message);
	}
	else {
		puts("You input wrong inputs!\nPlease try again.");
	}
	return 0;
}
char encrypt_Char(char character, int key)
{
	int characters_Alphabet = 26;
	if(isalpha(character))
	{
		if(tolower(character) + key > 'z')
		{
			return ((character + key) - characters_Alphabet);
		}
		else
		{
			return character + key;
		}
	}
	else
	{
		return character;
	}
}

