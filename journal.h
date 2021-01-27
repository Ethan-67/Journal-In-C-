#ifndef JOURNAL_H
#define JOURNAL_H

void make_entry(void);
void file_entry(char id[], char entry[], int length);
void master_entry(char id[]);

int read_line(char entry[]);
void read_id(char date[], char id[]);
void read_entries(void);
void print_entries(char entry[], int count);
void read_file(char entries[], char *p);
char *search_entries(char entry[], char input[]);
#endif 
