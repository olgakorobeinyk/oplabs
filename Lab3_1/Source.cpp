//#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>

using namespace std;

double getNumber(string number)
{
	char numbChar[10];
	cout << "Enter \'" << number << "\'\n";
	gets_s(numbChar);

	return atof(numbChar);
}

double calculateFunction(double a, double b, double c, double d)
{
	double y = ((6 * pow(sin(fabs(2 * a)), log10(b))) + sqrt(c*cosh(-d)));
	return y;
}

void printResult(double answer)
{
	cout << "Answer is " << answer;
}

int main()
{
	double a = getNumber("a");
	double b = getNumber("b");
	double c = getNumber("c");
	double d = getNumber("d");

	double answer = calculateFunction(a, b, c, d); //answer is 2.968644

	printResult(answer);

	getchar();
	return 0;
}