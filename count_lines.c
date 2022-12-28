#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 1000

FILE *read_file(char *filename);
int total_lines(FILE *ptr);
int main(int argc, char *argv[])
{
	char loc[20];

	if (argv[1] == NULL)
	{
		printf("no args found\n");
		exit(1);
	}
	printf("working with file %s\n", argv[1]);

	strcpy(loc, argv[1]);

	if (strlen(loc) != 0)
	{
		FILE *ptr = read_file(loc);
		
		if(ptr == NULL){
			printf("cannot open the file %s\n",loc);
			exit(1);
		}

		int res = total_lines(ptr);

		printf("%d\n", res);

		fclose(ptr);
	}

	return 0;
}

int total_lines(FILE *ptr)
{
	int cnt = 0;
	char str[BUFSIZE];

	while (fscanf(ptr, "%s", str) != EOF)
	{
		cnt++;
	}

	return cnt;
}

FILE *read_file(char *filename)
{
	FILE *file_ptr = NULL;

	file_ptr = fopen(filename, "r+");

	if (file_ptr == NULL)
	{
		return NULL;
	}

	return file_ptr;
}
