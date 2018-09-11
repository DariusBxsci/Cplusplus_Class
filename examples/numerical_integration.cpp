#include <iostream>
#include <math.h>
#include <armadillo>

using namespace std;
using namespace arma;


int main() {

	//define 'a' as a vector of 10 values evenly spaced between 0 and 9 (inclusive)
	vec a = linspace<vec>(0,9,10);

	//compute the trapezoidal integral of vector 'a'
	double b = ((vec)trapz(a))[0];
	//the trapz function returns an Armadillo vector type (vec) of just one element so we
	// cast the result to the vector type then access the first element to get a numerical value

	// the resulting integral should be the size of the trapezoid formed by the line
	cout << "Numerical Integral: " << endl << b << endl;


	//let's now define our own function to integrate

	//To start, create a vector of values corresponding to values of sin(x/(2pi))
	vec sin_vec = Col<double>(180);
	for (int i = 0; i < 180; i++)
		sin_vec[i] = sin(i/(2*M_PI));
	
	//now find the trapezoidal approximation of the integral
	double sin_vec_int = ((vec)trapz(sin_vec))[0];

	//to confirm that this worked correctly, let's compare the computed integral
	// with the mathematical definite integral of the function, -2pi*cos(1/(2pi))
	double real_sin_int = (-2*M_PI*cos(179/(2*M_PI))) - (-2*M_PI*cos(0/(2*M_PI)));
	
	//let's compare by printing the two values
	cout << "Computed Integral: " << endl << sin_vec_int << endl;
	cout << "Mathematical Integral: " << endl << real_sin_int << endl;

	return 0;
}
