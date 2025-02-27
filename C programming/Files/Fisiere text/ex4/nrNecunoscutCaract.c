#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define LINE_CHUNK 10
#define TEXT_CHUNK 10

char *readLine(FILE *f)
{
	char* line = NULL;
	char ch = 0;
	int index = 0, current_size = 0;
	while ((ch = fgetc(f)) != EOF)
	{
		if (index == current_size)
		{
			current_size += LINE_CHUNK;
			if ((line = (char*)realloc(line, current_size * sizeof(char))) == NULL)
			{
				perror(NULL);
				exit(-1);
			}
		}
		if (ch == '\n')
			break;
		line[index] = ch;
		index++;
	}
	if (line == NULL)
		return NULL;
	if (index == current_size)
	{
		current_size++;
		if ((line = (char*)realloc(line, current_size * sizeof(char))) == NULL)
		{
			perror(NULL);
			exit(-1);
		}
	}
	if (index > 0 && line[index - 1] == '\n') //e o porcarie da fara asta nu merge sortarea!!
		line[index - 1] = '\0';
	else
		line[index] = '\0';
	return line;
}

char** readLines(FILE *f)
{
	char** lines = NULL;
	char* line = NULL;
	int index = 0, current_size = 0;
	while ((line = readLine(f)) != NULL)
	{
		if (index == current_size)
		{
			current_size += TEXT_CHUNK;
			if ((lines = (char**)realloc(lines, current_size * sizeof(char*))) == NULL)
			{
				perror(NULL);
				exit(-1);
			}
		}
		lines[index] = line;
		index++;
	}
	if (lines == NULL)
		return NULL;
	if (index == current_size)
	{
		current_size++;
		if ((lines = (char**)realloc(lines, current_size * sizeof(char*))) == NULL)
		{
			perror(NULL);
			exit(-1);
		}
	}
	lines[index] = NULL;
	return lines;
}

void printLines(char** lines)
{
	int index = 0;
	while (lines[index] != NULL)
	{
		printf("%s\n", lines[index]);
		index++;
	}
}

void freeLines(char** lines)
{
	int index = 0;
	while (lines[index] != NULL)
	{
		free(lines[index]);
		index++;
	}
}

void compareLines(char **lines)
{
	if (lines == NULL)
		return;
	int i = 0, j = 0;
	char* aux;
	for (i = 0; lines[i] != NULL; i++)
	{
		for (j = i + 1; lines[j] != NULL; j++)
		{
			if (strcmp(lines[i], lines[j]) > 0)
			{
				aux = lines[i];
				lines[i] = lines[j];
				lines[j] = aux;
			}
		}
	}
}

void write_sort(char** lines, char* filepath)
{
	compareLines(lines);
	int index = 0;
	while (lines[index] != NULL)
	{
		fprintf(filepath, "%s\n", lines[index]);
		index++;
	}
}

uint32_t find_word(char** lines, char* word)
{
	uint32_t count = 0;
	for (int i = 0; lines[i] != NULL; i++)
	{
		char* copy = strdup(lines[i]); //copiaza sirul lines[i] in copy, copy fiind un pointer=>ii dam free la final!!
		strcpy(copy, lines[i]);
		char* p = strtok(copy, " ,.!?:;\n\t");
		while (p != NULL)
		{
			if (strcmp(p, word) == 0)
				count++;
			p = strtok(NULL, " ,.!?:;\n\t");
		}
		free(copy);
	}
	return count;
}


int main()
{
	FILE* f = NULL;
	if ((f = fopen("scrisoare.txt", "r")) == NULL)
	{
		printf("Error opening!");
		return -1;
	}

	char** lines = NULL;
	if ((lines = readLines(f)) == NULL)
	{
		printf("EROAREEEEE");
		return -2;
	}

	//printLines(lines);

	FILE* out1 = NULL;
	if ((out1 = fopen("out1.txt", "w")) == NULL)
	{
		printf("Error opening!");
		return -1;
	}


	write_sort(lines, out1);
	char word[] = "sultan";
	printf("Cuvantul %s apare in text de %d ori.", word, find_word(lines, word));
	freeLines(lines);
	free(lines);

	if (fclose(out1) != 0)
	{
		printf("Error closing!");
		return -1;
	}
	if (fclose(f) != 0)
	{
		printf("Error closing!");
		return -1;
	}
	return 0;
}