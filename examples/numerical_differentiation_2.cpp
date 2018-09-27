#include #include <iostream>
#include <armadillo>
#include <math.h>

using namespace std;
using namespace arma;

//first we will differentiate standard c++
//meaning we will have to write the procedure for differentiating a vector of values ourselves
vector<double> differentiate_hard(vector<double> values, double inc) {

    //vector<double> acts as a container for decimal values, and comes with the standard library
    //the 'values' variable will be the input to the function, and stores values
    //  of the function in question at different values of x
    //'inc' is the difference in x value of each value in the 'values' vector.

    vector<double> derivative;
    //starting from the second value, we can compute the derivative by using
    //  the slope formula with each previous value
    for (int i = 1; i < values.size(); i++) {
        //compute derivative at this point
        double der = ( values[i] - values[i-1] ) / inc;
        //push derivative to derivative vector
        derivative.push_back(der);
    }

    return derivative;
}

//second, we can use armadillo's functionality for differentiation
//***this is much quicker and easier to do, so this is how you should compute derivatives in your own projects
vec differentiate_arma(vector<double> values) {
    //we need to convert the vector<double> object into an armadillo-style vector
    vec vals = values;
    vec derivative = diff(vals);
    return derivative;
}

//By A. Darius Barbano