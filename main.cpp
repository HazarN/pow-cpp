#include <iostream>
#include <vector>
#include <chrono>
#include <math.h>
#include <time.h>

using namespace std;

double pow(double, int);
void test_pow(vector<double>&, vector<int>&);
void initialize_testValues(vector<double>&, vector<int>&);

int main() {
    srand(time(NULL));

    vector<double> bases;
    vector<int> exps;
    test_pow(bases, exps);
    
    return 0;
}

double myPow(double a, int n) {
    if (n == 0) return 1;
    if (n == 1) return a;

    if (n & 1) return a * myPow(a * a, (n - 1) / 2);
    else return myPow(a * a, n / 2);
}

void initialize_testValues(vector<double>& bases, vector<int>& exps) {
    for (int i = 0; i < 35; i++) {
        bases.push_back(0.0 + 20.0 * (static_cast<double>(rand()) / RAND_MAX));
        exps.push_back(rand() % 100);
    }
}
void test_pow(vector<double>& bases, vector<int>& exps) { 
    initialize_testValues(bases, exps);

    auto lib_start = chrono::high_resolution_clock::now();

    for (int i = 0; i < bases.size(); i++) 
        pow(bases[i], (double) exps[i]);

    auto lib_end = chrono::high_resolution_clock::now();

    auto lib_duration = chrono::duration_cast<chrono::microseconds>(lib_end - lib_start);

    auto my_start = chrono::high_resolution_clock::now();

    for (int i = 0; i < bases.size(); i++) 
        myPow(bases[i], exps[i]);

    auto my_end = chrono::high_resolution_clock::now();

    auto my_duration = chrono::duration_cast<chrono::microseconds>(my_end - my_start);

    cout << "Library pow() took -> " << lib_duration.count() << " ms" << endl;
    cout << "My pow() took      -> " << my_duration.count() << " ms" << endl;

    bool passed = true;
    for (int i = 0; i < bases.size(); i++) {
        double l = pow(bases[i], (double) exps[i]);
        double m = myPow(bases[i], exps[i]);

        // How many errors in 10 quadrillion
        double err = (abs(l - m) / l) * 10000000000000000.0;

        if (err > 100) {
            passed = false;
        }
    }

    if (passed) cout << "All tests are passed!" << endl;
}