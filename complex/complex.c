#include <stdio.h>
#include <assert.h>
#include "complex.h"

/* Creation */ 
//Add your code here
COMPLEX CreateComplex(double real, double imaginary)
{
	COMPLEX res={real,imaginary}; 
	return res;
}
// End of your code 

/* Destruction */ 
//Add your code here
void DestroyComplex(CPTR complex)
{
	
}
// End of your code 


/* Addition */ 
//Add your code here
COMPLEX AddComplex(CPTR first, CPTR second)
{
		COMPLEX res;
		res.real= (first->real)+(second->real);
		res.imaginary= (first->imaginary)+(second->imaginary);
		return res;
}
// End of your code 

/* Subtraction */ 
//Add your code here
COMPLEX SubtractComplex(CPTR first, CPTR second)
{
		COMPLEX res;
		res.real= (first->real)-(second->real);
		res.imaginary= (first->imaginary)-(second->imaginary);
		return res;
}

// End of your code 

/* Multiplication */ 
//Add your code here
COMPLEX MultiplyComplex(CPTR first, CPTR second)
{
	COMPLEX res;
		res.real= ((first->real)*(second->real))-((first->imaginary)*(second->imaginary));
		res.imaginary= ((first->imaginary)*(second->real))+((first->real)*(second->imaginary));
		return res;
}
// End of your code 

/* Conjugate */ 
//Add your code here
COMPLEX ConjugateComplex(CPTR complex)
{
	COMPLEX res;
		res.real= complex->real;
		res.imaginary=complex->imaginary!=0? (complex->imaginary)*(-1):0;
		return res;
}
// End of your code 

/* Division */ 
//Add your code here
COMPLEX DivideComplex(CPTR first, CPTR second)
{
	double a= first->real,b=first->imaginary,c=second->real,d=second->imaginary;
	COMPLEX res;
	res.real=(a*c + b*d) / ((c*c) + (d*d));
	res.imaginary=((b*c - a*d) / ((c*c) + (d*d)));
	return res;
}
// End of your code 

/* Printing */ 
//Add your code here
void PrintComplex(CPTR complex)
{
	printf("real = %.3f \t imaginary=%.3f ",complex->real,complex->imaginary);
}
// End of your code 
