#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	double y = ((6 * pow(sin(fabs(2 * 1.478)), log10(9.26))) + sqrt(0.68*cosh(-2.24))); //answer is 2.968644
	printf("%f", y);

	getchar();
	return 0;
}