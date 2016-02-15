#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>


using namespace std;

char* initChar(int length) {
	char *len = new char[length];
	for (int i = 0; i < length; i++) {
		len[i] = NULL;
	}
	return len;
}

int main() {

	FILE* fileText = fopen("File.txt", "r");

	FILE* stringLIst = fopen("FileStrings.txt", "r");

	char buffer[1000];
	char* text = new char[1000];
	char* textTmp;
	text[0] = NULL;
	char endWordCharacters[] = " ,.?!";
	while (fgets(buffer, 1000, fileText) != NULL) {
		textTmp = new char[strlen(text) + strlen(buffer)];
		textTmp[0] = NULL;
		strcat(textTmp, text);
		strcat(textTmp, buffer);
		text = textTmp;
	}

	while (fgets(buffer, 1000, stringLIst) != NULL)
	{
		char* searchString = strtok(buffer, ",");
		char* replaceString = strtok(NULL, ",");
		if (replaceString[strlen(replaceString) - 1] == '\n') {
			replaceString[strlen(replaceString) - 1] = NULL;
		}
		
		char* ptrFirstOccurance = text;
		while ((ptrFirstOccurance = strstr(ptrFirstOccurance, searchString)) != NULL) {
			int replaceTextLength = strlen(replaceString);
			int searchStringLength = strlen(searchString);

			char* occOne = strchr(endWordCharacters, *(ptrFirstOccurance - 1));
			char* occTwo = strchr(
				endWordCharacters,
				*(ptrFirstOccurance + searchStringLength)
				);


			int newLength = strlen(text) + replaceTextLength
				- searchStringLength;

			int lengthOfFirstPart = (int)(ptrFirstOccurance - text);

			if (occOne == NULL || occTwo == NULL) {
				continue;
			}

			ptrFirstOccurance += searchStringLength;
			char* tmptext = initChar(newLength);
			strncpy(tmptext, text, lengthOfFirstPart);
			strcat(tmptext, replaceString);
			strcat(tmptext, text + lengthOfFirstPart + searchStringLength);
			text = tmptext;
		}
	}
	FILE* resultFile = fopen("Result.txt", "wt");
	fputs(text, resultFile);
	return 0;
}