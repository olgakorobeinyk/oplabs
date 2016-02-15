#include <stdio.h>
#include <string.h>
using namespace std;

const int TAB_SIZE = 8;

int main()
{
	char words[80];
	gets_s(words);
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
	return 0;
}