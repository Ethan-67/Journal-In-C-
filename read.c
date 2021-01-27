#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "journal.h"

#define MAX_CHAR 1000

void read_id(char date[], char id[])
{
	char ch;
	int i = 0, j = 0;
	while (date[i] != '\0') {
		if (date[i] != '/')
			id[j++] = date[i];
		i++;
	}
	id[j] = '\0';	
}

int read_line(char entry[])
{
	char ch;
	int i = 0;
	while ((ch = getchar()) != '\n') {
		entry[i++] = ch; 
	}
	entry[i] = '\0';
	return i; 
}

void read_entries(void)
{
	char ch, entries[1024];
	int i = 0, count = 0;	
	FILE *fp = fopen("master", "r"); 

	while ((ch = getc(fp)) != EOF) {
		if (ch == ' ') 
			count++;
		entries[i++] = ch;
	}
	entries[i] = '\0';

	print_entries(entries, count);
	char input[9];
	printf("Select entry you wish to print: ");
	scanf("%s", &input);

	char *ida = search_entries(entries, input); 
	read_file(entries, ida);
}

void read_file(char entries[], char *p)
{
	char str[MAX_CHAR+1];
	char *s = str;
	char temp[9], path[256];
	for (int i = 0; i < 9; i++, p++) {
		temp[i] = *p;
	}
	snprintf(path, 256, "%s/%s.txt", "logs", temp);

	FILE *fp = fopen(path, "r");
	if (fp == NULL) {
		perror("file pointer: ");
		return;
	}

	while (fgets(s, MAX_CHAR, fp) != NULL)
		s++; 
		
	printf("%s\n", str);
	fclose(fp);
}

char *search_entries(char entry[], char input[])
{
	char stra[9], ch;
	char *str = stra;	
	int i = -1, count = 0, j = 0;
	
	while (entry[i++] != EOF) {
		while (entry[i] != ' ') {
			if (entry[i] == input[j]) {
				count++;
				stra[j] = entry[i];
				j++;
			}
			if (count == 8) {	
				stra[9] = '\0';
				return str;
			}
			i++;
		}
		count = 0;
		j = 0;
	}
}



