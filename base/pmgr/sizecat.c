/* This file is in the public domain. */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

#define BUFMAX 65536
static char buf[BUFMAX];

void logout(FILE *f, int pos, int size, int nosize)
{
	char bar[51];
	int i, percent, size2 = size / 100;
	
	if (size2 < 10000)
	{
		percent = pos * 100 / size;
	}
	else
	{
		percent = pos / size2;
	}
	if (percent > 100) percent = 100;
	
	for (i = 0; i < 50; i++)
	{
		bar[i] = i * 2 < percent ? '#' : '-';
	}
	bar[50] = '\0';
	if (nosize == 0)
	{
		fprintf(f, "\r%3d%% [%s] %d/%d KB", percent, bar, pos / 1024, size / 1024);
	}
	else
	{
		fprintf(f, "\r%3d%% [%s]", percent, bar);
	}
}

int usage(const char *argv0)
{
	fprintf(stderr, "usage: %s [-nosize] file [...]\n", argv0);
	return 1;
}

int getbufsize(int size)
{
	int sz = size / 50, a = 16, ret = 16;
	if (sz <= 16) return 16;
	if (sz >= BUFMAX) return BUFMAX;
	for (; a < sz; a <<= 1) ret = a;
	return ret;
}

int main(int argc, char *argv[])
{
	int i, size = 0, sizekb, nosize = 0, pos = 0, bufsize;

	if (argc < 2) return usage(argv[0]);

	if (!strcmp(argv[1], "-nosize"))
	{
		if (argc < 3) return usage(argv[0]);
		nosize = 1;
	}
	
	for (i = nosize + 1; i < argc; i++)
	{
		struct stat st;
		if (stat(argv[i], &st) != 0)
		{
			fprintf(stderr, "ERROR: can not get state: %s\n", argv[i]);
			return errno;
		}
		size += st.st_size;
	}
	sizekb = size / 1024;
	bufsize = getbufsize(size);

	for (i = nosize + 1; i < argc; i++)
	{
		logout(stderr, pos, size, nosize);
		FILE *f = fopen(argv[i], "rb");
		if (f == NULL)
		{
			fprintf(stderr, "\nERROR: can not open: %s\n", argv[i]);
			return errno;
		}
		while (!feof(f))
		{
			int len = fread(buf, 1, bufsize, f);
			fwrite(buf, 1, len, stdout);
			pos += len;
			logout(stderr, pos, size, nosize);
		}
		fclose(f);
	}

	fprintf(stderr, "\n");
	return 0;
}
