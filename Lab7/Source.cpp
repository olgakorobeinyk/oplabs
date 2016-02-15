#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

const int TAB_SIZE = 8;

int main()
{
	printf("Enter any string to count the spaces in it \n");
	char* words = (char *)malloc(sizeof(char) * 80);
	gets(words);
	int spaces = 0;

	for (int i = 0; i < strlen(words); i++)
	{
		switch (words[i])
		{
		case ' ':
			spaces++;
			break;
		case '\t':
			spaces += TAB_SIZE;
			break;
		default:
			break;
		}
	}
	printf("The number of spaces is %d", spaces);
	getchar();
	free(words);
	return 0;
}