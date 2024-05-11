#include <iostream>
#include <unordered_map>

using namespace std;

double power(double, int);

int main() {
    double a; int n;

    cout << "Enter a: "; cin >> a;
    cout << "Enter n: "; cin >> n;
    cout << a << " raised to the power of " << n << " is: " << power(a, n) << endl;

    return 0;
}

double power(double a, int n) {
    if (n == 0) return 1;
    if (n == 1) return a;

    if (n < 0)  return 1 / power(a, -n);
    
    if (n & 1)  return a * power(a * a, (n - 1) / 2);
    else        return power(a * a, n / 2);
}