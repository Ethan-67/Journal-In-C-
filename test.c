#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <limits.h>
#include <dirent.h>

void main(void) 
{
	FILE *fp = fopen("logs/11012001.txt", "r");
	char *save;

	for (int i = 0; (fgets(save, sizeof(save), fp) != EOF); i++)
		;
	printf("%s", *save);

	fclose(fp);

}
