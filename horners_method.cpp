/*
 * This program evaluates a general polynomial using Horner's Method.
 */

#include <iostream>
#include <cmath>
using namespace std;

double horners_method(int d, double c[], double x) {
    /*
     * This function evaluates a polynomial using nested multiplication.
     *
     * Inputs:
     *        d - Degree of polynomial.
     *        c - Array of polynomial coefficients.
     *        x - Coordinate at which to evaluate polynomial.
     */

    double solution;
    for (int i=0; i<d+1; i++) {
        solution = solution * x + c[i];
    }
    return solution;
}

void problem_one() {
    /*
     * Use the function to evaluate P(x) = 1 + x + ... + x^50 at x = 1.00001.
     * Find the error of the computation by comparing with the equivalent
     * expression Q(x) = (x^51 - 1) / (x - 1).
     */

    // Variable definitions.
    int degree = 50;
    double coefficients[degree+1];
    double variable = 1.00001;

    // Fill array with ones.
    for (int i=0; i<degree+1; i++) {
        coefficients[i] = 1;
    }

    // Solution definitions.
    long double exact_solution = (pow(variable, 51) - 1) / (variable - 1);
    long double horners_solution = horners_method(degree, coefficients, variable);
    long double percent_error = abs(exact_solution - horners_solution) / exact_solution;

    // Print solutions.
    cout << "Problem 1:" << endl;
    cout << "Exact Expression: " << exact_solution << endl;
    cout << "Horner's Method: " << horners_solution << endl;
    cout << "Percent Error: " << percent_error << endl << endl;
}

void problem_two() {
    /*
     * Use the function to evaluate P(x) = 1 - x + x^2 - x^3 + ... + x^98 - x^99
     * at x = 1.00001. Find a simpler, equivalent expression, and use it to
     * estimate the error of the nest multiplication.
     */

     // Variable definitions.
    int degree = 99;
    double coefficients[degree+1];
    double variable = 1.00001;

    // Fill array with ones.
    for (int i=0; i<degree+1; i++) {
        if (i%2 == 0) {
            coefficients[i] = -1;
        }
        else {
            coefficients[i] = 1;
        }
    }

    // Solution definitions.
    long double exact_solution = (1 - pow(variable, 100)) / (1 + variable);
    long double horners_solution = horners_method(degree, coefficients, variable);
    long double percent_error = abs(exact_solution - horners_solution) / exact_solution;

    // Print solutions.
    cout << "Problem 2:" << endl;
    cout << "Exact Expression: " << exact_solution << endl;
    cout << "Horner's Method: " << horners_solution << endl;
    cout << "Percent Error: " << percent_error << endl << endl;
}

int main() {
    problem_one();
    problem_two();
    return 0;
}
