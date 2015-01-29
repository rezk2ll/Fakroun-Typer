#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define error "ma7abbech"
#define BuffSize 101
#define border Fakroun("\t\t-----------------------------------\n\n");

char *GetText(char *fname);
void Fakroun(char *text);

void main() {
	char *file = malloc(10);
	Fakroun("\n\n\t\t Welcome to Fakroun Typer :p \n");
	puts("\n");
	start : Fakroun("\t\t please provide a Filename : ");
	fgets(file , 10 , stdin);
	file[strlen(file)-1] = '\0';
	if( strcmp(GetText(file),error) == 0) {
		Fakroun(" \t\t Something is wrong with that file ! let's try again \n\n");
		goto start;
	}
	border;
	Fakroun(GetText(file));
	border;
}

void Fakroun(char *text) {
	int i=0;
	for( ; i < strlen(text) ; i++) {
		printf("%c",*(text+i));
		usleep(90000);
		fflush(stdout);
	}
}

char *GetText(char *fname) {
	FILE *fd 		= fopen(fname , "r");
	char *value 	= malloc(500000);
	char *buffer 	= malloc(BuffSize);
	if ( fd == NULL) {
	free(value);
	return error;
	}
	
	while ( fgets(buffer , BuffSize , fd ) ) {
		strcat(value , buffer);
	}
	
	free(buffer);
	strcat(value , "\0"); // just to make sure , allright !
	return value;
}
