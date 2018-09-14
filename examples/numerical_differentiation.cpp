#include <iostream>
#include <armadillo>
#include <math.h>

using namespace std;
using namespace arma;

int main() {

	//define 'a' as a vector of 10 values evenly spaced between 0 and 9 (inclusive)
	vec a = linspace<vec>(0,9,10);

	//compute the derivative of the vector 'a'
	vec b = diff(a);

	// the resulting derivative should always be 1
	cout << "Numerical Derivative: " << endl << b << endl;


	//let's now define our own function to find the derivative of

	//To start, create a vector of values corresponding to values of sin(x/(2pi))
	vec sin_vec = Col<double>(180);
	for (int i = 0; i < 180; i++)
		sin_vec[i] = sin(i/(2*M_PI));
	
	//now get the derivative of the sin value vector
	vec sin_vec_der = diff(sin_vec);

	//to confirm that this worked correctly, let's compare the derivative vector with the function's mathematical
	//	derivative, cos(x/(2pi))*1/(2pi)
	vec real_sin_der = Col<double>(180);
	for (int i = 0; i < 180; i++)
		real_sin_der[i] = cos(i/(2*M_PI))*1/(2*M_PI);
	
	//let's compare by printing the two vectors
	cout << "Computed Derivative: " << endl << sin_vec_der << endl;
	cout << "Mathematical Derivative: " << endl << real_sin_der << endl;
		

	//In reality, the computer derivative and mathematical derivative are not equal.
	//This is because the computed derivative uses numerical differentiation,
	//which only approximates the derivative of a function.

	return 0;
}

//By Darius B.
