
#include <stdio.h>


float arredonda(float num) {

	float parteInt = (int)num;
	float parteFrac = num - parteInt;
	float result;

	//printf("%f\n", parteFrac);

	if (num > 0) {
		if (parteFrac >= 0.50) {
			result = ++parteInt;
		} else {
			result = parteInt;
		}
	} else {
	    //printf("%f\n",(parteInt - 1));
	    if ((parteFrac * -1) >= 0.5) {
			result = --parteInt;
		} else {
			result = parteInt;
		}
	}

	//printf("%f", result);
	return result;
}

/*

int main()
{
	float n1 = 0.91;

	arredonda(n1);
}

*/
