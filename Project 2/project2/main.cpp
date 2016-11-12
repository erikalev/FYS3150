#include <iostream>
#include <armadillo>
#include <fstream>
#include "time.h"
#include <iomanip>

using namespace std;
using namespace arma;

double find_largest_non_diag(mat A, int n, int& k, int& l) {
    /* Method to find the largest non diagonal value in our symmetric matrix. Since the matrix is symmetric and since it
     * stays symmetris through the transformations we only need to check the values over the main diagonal to find the
     * largest non diagonal value.
     * A = Matrix with diagonal values to find
     * n = size of matrix
     * k = row index for largest value
     * l = column index for largest value
     */
    double largest_non_diag = 0.0;

    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j <= n-1; j++){
            if (fabs(A(i, j)) > largest_non_diag){
                largest_non_diag = fabs(A(i, j));
                k = i;

                l = j;
            }
        }
    }

    return largest_non_diag;
}
void compute_rotation(mat &A, mat &R, int k, int l, int n){
    /* Method to rotate the A matrix to cansel out the largest non diagonal value.
     * A = Matrix to rotate
     * R = Eigenvector matrix (starts as identity matrix nxn)
     * k = row index of largest non diagonal value
     * l = column index of largest non diagonal value
     * n = Matrix size
     */
    double tau, t, c, s;
    tau = (A(l,l)-A(k, k))/(2*A(k, l));

    // Finds tangens(theta) without risking addition error
    if (tau >= 0){
        t = 1.0/(tau + sqrt(1.0 + tau*tau));
    }
    else{
        t = -1.0/(-tau + sqrt(1. + tau*tau));
    }
    c = 1.0/(sqrt(1 + t*t));
    s = t*c;
    double akk, all, aik, ail, rik, ril;

    akk = A(k, k);
    all = A(l, l);
    A(k, k) = akk*c*c - 2*A(k, l)*c*s + all*s*s;
    A(l, l) = akk*s*s + 2*A(k, l)*c*s + all*c*c;
    A(k, l) = 0.0;
    A(l, k) = 0.0;

    for (int i = 0; i<n; i++){
        if (i != k && i != l){
            aik = A(i, k);
            ail = A(i, l);
            A(i, l) = ail*c + aik*s;
            A(l,i)= A(i,l);
            A(i, k) = aik*c - ail*s;
            A(k,i) = A(i,k);
        }
        rik = R(i, k);
        ril = R(i, l);
        R(i, k) = c*rik - s*ril;
        R(i, l) = c*ril + s*rik;
    }
}
bool test_eigenvalues(mat A, mat B, int n){
    /* A test for the eigenvalues
     * If the eigenvalues deviate from the exact solution with more then tol, the function sends an error message and exits
     * the program
     * A = Our final matrix with eigenvalues in the diagonal. All other values are zero (or close to zero)
     * B = Our original matrix
     * n = matrix size
     */

    double tol = 1e-8;
    vec computed_eigenvalues = zeros<vec>(n);
    for (int i = 0; i < n; i++){
        computed_eigenvalues(i) = A(i, i);
    }
    computed_eigenvalues = sort(computed_eigenvalues, "ascend");
    cout << "first eigenvalue is = " << computed_eigenvalues(0) << endl;
    vec exact_eigenvalues;
    mat exact_eigenvectors;
    clock_t start, finish; //include timer
    start = clock();   //start the timetaking

    eig_sym(exact_eigenvalues, exact_eigenvectors, B);
    finish = clock(); //stop timetaking
    double sec = (finish - start);   //calculate clocks_per_sec used
    cout << "the time for eig_sum to find the eigenvalues was " << sec/CLOCKS_PER_SEC << " seconds" << endl; //print seconds used

    vec diff = exact_eigenvalues - computed_eigenvalues;
    for (int i = 0; i < n; i++){
        if (fabs(diff(i)) > tol){
            printf ("Eigenvalue no. %i deviates with more then allowed tolerance \n", i);
            return false;
        }
    }
    return true;
}
bool test_unit_vectors(mat R, int n){
    /* Checking if the orthogonality is preserved after the matrix rotations.
     * If not orthogonality is not preserved, the function sends an error message and exits
     * the program
     * R = Rotated matrix
     * n = Matrix size
     */

    double sum1, tol;
    tol = 1e-10;

    for (int i = 0; i < n; i++){
        sum1 = dot(R(span::all, span(i, i)), R(span::all, span(i+1, i+1)));
        if (fabs(sum1) < tol){
            sum1 = dot(R(span::all, span(i, i)), R(span::all, span(i, i)));
            if (sum1 != 1){
                return false;
            }
        }

        else{
            cout << "Your orthogonality is not presevred! Exiting program" << endl;
            return false;
        }
    }
    return true;
}
bool run_unit_tests(mat A, mat B, mat R, int n){
    if (test_eigenvalues(A, B, n) == false){
        return false;
    }
    if (test_unit_vectors(R, n) == false){
        return false;
    }
    return true;
}
void dump_to_file_e(mat A, mat R, int n, double h){
    /* Dumping n, h and R into 2 text documents.
     * n = matrix size
     * h = step size
     * R = Matrix with the new basis vectors
     */

    vec eigenvalues = zeros<vec>(n);
    for (int i = 0; i < n; i++){
        eigenvalues(i) = A(i, i);
    }

    uword index;
    eigenvalues.min(index);
    ofstream outputFile;    //create new file
    outputFile.open("variables.txt");
    outputFile << setiosflags(ios::showpoint | ios::uppercase);
    outputFile << setprecision(10) << setw(20) << n << " " << h << endl;
    outputFile.close();
    outputFile.open("basisvector.txt");
    for (int j = 0; j < n; j++){
        outputFile << setiosflags(ios::showpoint | ios::uppercase);
        outputFile << setprecision(10) << setw(20) << R(j, index) << endl;
    }
    outputFile.close();
}



int main(){
    /* Setting all initial values for the problem aswell as a while loop do the matrix rotation until non diagonal elements
     * are close to zero
     */
    int n = 4;
    double spin[n][n];
    for (int i = 0; i <n; i++){
    for (int j = 0; j <n; j++){
    spin[i][j] = 1;
    //cout << spin[i][j] << endl;
    }}
    cout << **spin << endl;


        /*

    clock_t start, finish; //include timer
    start = clock();   //start the timetaking

    bool testflag = false; // activate to start unit tests
    bool dump_e = false;    //activate to dump new ground state to file

    int n = 250;
    double p_max = 40;
    double h = p_max/(n);
    double w2r = 5.0;
    double e = -1.0/(h*h);
    mat A = zeros<mat>(n, n);
    A(0, 0) = -2*e + h*h*w2r*w2r + 1.0/h;
    A(n-1, n-1) = -2*e + ((n-1)*h)*((n-1)*h)*w2r*w2r + 1.0/((n-1)*h);
    A(0, 1) = e;
    A(1, 0) = e;
    A(n-1, n-2) = e;
    A(n-2, n-1) = e;

    for (int i = 1; i < n-1; i++){
        double potential = ((i+1)*h)*((i+1)*h)*w2r*w2r + 1.0/((i+1)*h);
        //double potential = ((i+1)*h)*((i+1)*h);
        A(i, i) = -2*e + potential;
        A(i, i+1) = e;
        A(i+1, i) = e;
    }

    mat B = A;  // saving the initial matrix for unit tests
    mat R;      // initial guess for the eigenvectors
    R.eye(n, n);
    double tol = 1e-10;
    int no_iterations = 0;
    int max_iterations = 100000;
    double lnd = 10000; // lnd = largest non diagonal

    while (lnd > tol && no_iterations <= max_iterations){
        // Rotates the matrix A until we have close to zero on all non diagonal values
        int k, l;
        lnd = find_largest_non_diag(A, n, k,  l);
        compute_rotation(A, R, k, l, n);
        no_iterations ++;
    }

    if (testflag == true){
        if (run_unit_tests(A, B, R, n) == false){
            return 1;
        }
    }

    if (dump_e == true){
        dump_to_file_e(A, R, n, h);
    }
    finish = clock(); //stop timetaking
    double sec = (finish - start);   //calculate clocks_per_sec used
    cout << "the time for Jacobi's eigenvalue algorithm to find the eigenvalues was " << sec/CLOCKS_PER_SEC << " seconds" << endl; //print seconds used
    */
    return 0;
}
