// This software is in the public domain.
// There are no restrictions on any sort of usage of this software.

#include <stdio.h>
#include "ffchttp.h"

void logout(int pos, int size)
{
	if (size == 0)
	{
		printf("\r%d KB", pos / 1024);
		return;
	}
	
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
	if (size < 1024)
	{
		printf("\r%3d%% [%s] %d/%d Bytes", percent, bar, pos, size);
	}
	else
	{
		printf("\r%3d%% [%s] %d/%d KB", percent, bar, pos / 1024, size / 1024);
	}
}

int usage(const char* argv0)
{
	printf("usage: %s [-proxy proxy.somewhere:8080] URL\n", argv0);
	return 1;
}

int main(int argc, char* argv[])
{
	if (argc < 2) return usage(argv[0]);
	
	int opt = 0;
	FFCHTTP http;
	if (!strcmp(argv[1], "-proxy"))
	{
		if (argc < 4) return usage(argv[0]);
		http.setProxy(argv[2]);
		opt = 2;
	}
	
	FFCURL url = argv[opt + 1];
	printf("=> %s\n", argv[opt + 1]);
	printf("connecting: %s\n", url.getAddress().data());
	if (!http.get(url) || !http.readHeader())
	{
		printf("connection error!\n");
		return 1;
	}
	printf("%s\n", http.getResultText().data());
	if (http.getResult() != 200) return 1;
	
	if (!http.save(url.getFile(), &logout))
	{
		printf("\nsocket error!\n");
		return 1;
	}
	printf("\ndone.\n");
	
	return 0;
}
