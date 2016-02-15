#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>

using namespace std;

//each input array cosists of the two real numbers: the real part and the imaginary part of the complex number
double* addNumbers (double* firstNumber, double* secondNumber)
{
	double result[2];
	result[0] = firstNumber[0] + secondNumber[0];
	result[1] = firstNumber[1] + secondNumber[1];
	return result;
}

double* substractNumbers(double* firstNumber, double* secondNumber)
{
	double result[2];
	result[0] = firstNumber[0] - secondNumber[0];
	result[1] = firstNumber[1] - secondNumber[1];
	return result;
}

double* multiplyNumbers(double* firstNumber, double* secondNumber)
{
	double result[2];
	result[0] = firstNumber[0]*secondNumber[0] - firstNumber[1]*secondNumber[1];
	result[1] = firstNumber[0]*secondNumber[1] + firstNumber[1]*secondNumber[0];
	return result;
}

double* divideNumbers(double* firstNumber, double* secondNumber)
{
	double result[2];
	result[0] = (firstNumber[0]*secondNumber[0] + firstNumber[1]*secondNumber[1])/(pow(secondNumber[0],2) + pow(secondNumber[1],2));
	result[1] = (firstNumber[1]*secondNumber[0] - firstNumber[0]*secondNumber[1])/(pow(secondNumber[0], 2) + pow(secondNumber[1], 2));
	return result;
}

string getInput() {
	string numLine;
	printf("Enter 6 real number separeted by space\n");
	getline(cin, numLine);

	return numLine;
}

double* parseString(string inputString) {
	double numbers[6];
	if (inputString.size() == 0) {
		return numbers;
	}

	size_t posStart = 0;
	size_t posEnd = inputString.find_first_of(" ");
	int index = 0;

	while (posStart != string::npos && index < 6) {
		string val = inputString.substr(posStart, posEnd - posStart);
		if (val.size() == 0) {
		continue;
		}
		try {
			numbers[index] = stod(val);
			index++;
		}
		catch (invalid_argument exc) {
		}

		posStart = posEnd;
		posEnd = inputString.find_first_of(" ", posStart + 1);
	}
	return numbers;
}

void printResult(double* result)
{
	cout << "Computed complex number is: " << result[0] << " + " << result[1] << "i";

}

int main()
{
	string input = getInput();
	double *numbers = parseString(input);
	
	double u[2] = { numbers[0], numbers[1] };
	double v[2] = { numbers[2], numbers[3] };
	double w[2] = { numbers[4], numbers[5] };

	//next arrays are for formula computation
	double two[2] = { 2, 0 };
	double three[2] = { 3, 0 };
	double four[2] = { 4, 0 };
	double five[2] = { 5, 0 };
	double* helper = multiplyNumbers(three, u);
	double threeU[2] = { helper[0], helper[1] };
	helper = multiplyNumbers(threeU, v);
	double threeUV[2] = { helper[0], helper[1] };
	helper = multiplyNumbers(two, w);
	double twoW[2] = { helper[0], helper[1] };
	helper = addNumbers(four, twoW);
	double fourPlusTwoW[2] = { helper[0], helper[1] };
	helper = substractNumbers(fourPlusTwoW, v);
	double fourPlusTwoWminusV[2] = { helper[0], helper[1] };
	helper = divideNumbers(threeUV, fourPlusTwoWminusV);
	double division[2] = { helper[0], helper[1] };
	helper = addNumbers(threeU, division);
	double threeUplusDivision[2] = { helper[0], helper[1] };
	helper = substractNumbers(threeUplusDivision, five);
	double result[2] = { helper[0], helper[1] };
	
	printResult(result);

	getchar();
	return 0;
}