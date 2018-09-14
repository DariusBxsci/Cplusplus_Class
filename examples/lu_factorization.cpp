#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;


int main() {
	
	//Armadillo allows us to decompose a matrix into LU form
	mat A = { { 1, 2, 3 }, { 1, 2, 3 }, { 1, 2, 3 } };
	mat L, U;

	//generate matrix factors L and U such that L*U = A
	lu(L, U, A);

	//If factorization succeeded, B should be equal to A
	mat B = L*U;

	//print B so we can see if LU factorization worked
	cout << endl << B << endl;

	return 0;
}

//By Darius B.

