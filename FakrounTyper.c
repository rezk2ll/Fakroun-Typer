#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define error "ma7abbech"
#define BuffSize 101
#define border Fakroun("\t\t-----------------------------------\n\n");
#define MAXFILE 255 //Maximum filename length

char *GetText(char *fname);
void Fakroun(char *text);

int main() {
	char *file = malloc(MAXFILE);
	Fakroun("\n\n\t\t Welcome to Fakroun Typer :p \n");
	puts("\n");
	start : Fakroun("\t\t please provide a Filename : ");
	fgets(file , MAXFILE, stdin);
	file[strlen(file)-1] = '\0';
	if(!strcmp(GetText(file),error)) {
		Fakroun(" \t\t Something is wrong with that file ! let's try again \n\n");
		goto start;
	}
	border;
	Fakroun(GetText(file));
	border;
	
	//Unix systems expect an int return
	return 0;
}

void Fakroun(char *text) {
	while (*text) {
		prutchar(*text++);
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
	
	while ( fgets(buffer , BuffSize , fd ) )
		strcat(value , buffer);
	
	free(buffer);
	strcat(value , ""); // just to make sure , allright !
	return value;
}
