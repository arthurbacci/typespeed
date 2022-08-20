#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LINE_LEN 10

void die(const char *string) {
	perror(string);
	exit(1);
}

int main(int argc, char **argv) {
	FILE *fp;
	long file_size;

	srand(time(NULL));

	if (argc < 2) {
		fprintf(
			stderr,
			"USAGE: %s [file]\n",
			argc == 1 ? argv[0] : "typespeed"
		);
		return 1;
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		die("Couldn't open the file");

	/* Go to the end of the file */
	if (fseek(fp, 0, SEEK_END) < 0)
		die("Couldn't seek the file");
	

	file_size = ftell(fp);
	if (file_size < 0)
		die("Couldn't get the file size");

	while (1) {
		long pos;
		int c;
		char line[LINE_LEN];
		char input[LINE_LEN];
		size_t linelen;

		pos = (((long)rand() << 32) + (long)rand()) % file_size;

		if (fseek(fp, pos, SEEK_SET) < 0)
			die("Couldn't seek the file");

		while ((c = fgetc(fp)) != EOF && c != '\n');

		if (feof(fp) != 0)
			continue;
		
		if (fgets(line, LINE_LEN, fp) == NULL)
			die("Couldn't read a line from the file");
		
		linelen = strlen(line);

		if (line[linelen - 1] != '\n')
			line[linelen - 1] = '\n';

		printf("%s", line);
		
		if (fgets(input, LINE_LEN, stdin) == NULL)
			die("Couldn't read a line from stdin");

		if (strcmp(input, line) != 0)
			break;
	}


	fclose(fp);
	return 0;
}

