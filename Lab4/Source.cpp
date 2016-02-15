#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <string>
using namespace std;

int main()
{
	int input;
	char buffer[255] ;
	FILE* f = fopen("input.txt", "r");
	FILE* fOutput = fopen("output.txt", "w");
	while (fgets(buffer,255, f) != NULL) {
		input = atoi(buffer);
		if (input % 3 == 0 && input % 7 != 0) {
			fputs(buffer, fOutput);
		}
	}
	fclose(f);
	fclose(fOutput);
	return 0;
}