#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main() {

	//calculating the determinant of a matrix is extremely easy with Armadillo
	mat M = { { 1, 3, 4 }, { 5, 2, 1 }, { 9, 2, 5 } };
	
	double determinant = det(M);

	cout << "Determinant: " << determinant << endl;

	return 0;
}

//By Darius B.
