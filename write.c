#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include "journal.h"


void make_entry(void) 
{
	char entry[2048];
	char date[11];
	char id[9];	
	int length;

	printf("Enter date for entry: ");
	scanf("%s", &date); 
	read_id(date, id);

	printf("Enter an entry: ");
	getchar();	
	length = read_line(entry); 

	file_entry(id, entry, length);
	master_entry(id);
	
}

void file_entry(char id[], char entry[], int length)
{
	char path[strlen("logs")+1];
	strcpy(path, "logs");
	
	struct stat st = {0}; 
	if (stat(path, &st) == -1) {
		mkdir(path, 0755);
	}

	char endPath[NAME_MAX+1];	
	snprintf(endPath, NAME_MAX+1, "%s/%s.txt", path, id);
	FILE *fp = fopen(endPath, "w");
	if (fp == NULL) { 
		printf("NULL pointer, not open\n");
		perror("fopen");
		return;
	}
	fputs(entry, fp);
	fclose(fp);
}

void master_entry(char id[]) 
{
	FILE *fp = fopen("master", "a");
	char *s = " ";
	if (fp == NULL) { 
		perror("master entry: ");
		return;
	}
	fputs(id, fp);
	fputc(*s, fp); 
	fclose(fp);
}
void print_entries(char entries[], int count)
{
	int i = 0;
	while (entries[i++] != '\n') {
		if (entries[i] == ' ') 
			printf("\n");
		printf("%c", entries[i]);	
	}
}
