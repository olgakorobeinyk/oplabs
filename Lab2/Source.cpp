//#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	//Request for an entering of real numbers
	char array[30];
	printf("Enter N real numbers separeted by space\n");

	//Get entered numbers as char's array
	gets_s(array);

	//Find out the length of the future real numbers' array
	int length = strlen(array);
	int numLength = 1;
	for (int j = 0; j < length; j++) 
	{
		if (array[j] == ' ') 
			numLength++;
	}

	//Make real numbers array from a char array
	double* numbers = new double[numLength];
	char* number = new char[length];
	int j = 0;
	int k = 0;

	for (int i = 0; i < length; i++)
	{
		if (array[i] != ' ')
		{
			number[j++] = array[i];
		}
		else
		{
			numbers[k++] = atof(number);
			number = new char[length];
			j = 0;
		}
	}

	numbers[k] = atof(number); // k is a length of an array

	//Get the product of the numbers that are a multiple of 3
	double product = 1; 
	for (int s = 0; s <= k; s++) 
	{
		 if ((int)numbers[s] == numbers[s] && (int)numbers[s] % 3 == 0)
		{
			product *= numbers[s];
		}
	}
	
	//Get the sum and count of the numbers on [3,7] segment
	int index = 2;
	double summ = 0;
	double count = 0;

	do
	{
		if (index > k) 
		{
			break;
		}
		summ += numbers[index];
		count++;
		index++;
	} while (index < 7);

	if (product == 1) 
	{
		cout << "There is no number that is multiple of 3 " << '\n';
	}
	else 
	{
		cout << "The product of the numbers that are multiple of 3 is " << product << '\n';
	}
	cout << "There are " << count << " numbers on [3,7] segment" << '\n';
	cout << "The summ of the numbers on [3,7] segment is " << summ << '\n';

	std::getchar();
	return 0;
}