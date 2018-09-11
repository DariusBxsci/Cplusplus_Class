
//We need to use pre-written classes and functions, so we include these two libraries
//iostream is part of the C++ standard library, and allows us to print to the console
#include <iostream>
//armadillo is a third-party library that provides classes and functions for linear algebra
#include <armadillo>

//namespaces allow us to organize our code
//the 'using namespace' statement tells the program that we want to use things in a specific namespace
//in this case, we are using the 'std (standard library)' and 'arma (armadillo)' namespaces
using namespace arma;
using namespace std;

int main() {

    mat A = randu<mat>(5,5);
    vec b = randu<vec>(5);

	//solve a linear system with random matrix A and vector b
    vec result = solve(A, b);

	//print the result
	cout << "Result: " << endl << result << endl; 


	//Alternatively, we can construct and solve our own linear system
	mat X = { { 1, 2, 3 }, { 1, 2, 4}, { 4, 5, 1} };
	vec y = { 5, 6, 2 };

	result = solve(X, y);

	cout << "Result: " << endl << result << endl;

    return 0;
}

