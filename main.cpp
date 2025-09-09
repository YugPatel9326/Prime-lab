#include <iostream>
#include <vector>
using namespace std;

class Factorizer {
public:
    vector<int> primeFactors(int n) {
        vector<int> factors;

        if (n <= 1) {
            return factors;
        }

        for (int i = 2; i <= n; i++) {
            while (n % i == 0) {
                factors.push_back(i);
                n = n / i;
            }
        }

        return factors;
    }

    bool primeCheck(int n) {
        vector<int> factors = primeFactors(n);

        if (factors.size() == 1) {
            return true;
        }
        return false;
    }

    bool compositeCheck(int n) {
        
        if (n > 1 && !primeCheck(n)) {
            return true;
        }
        return false;
    }
};

int main() {
    Factorizer factorizer;

    int testNums[] = {0, 2, 3, 19, 14028};
    int size = 5;

    for (int i = 0; i < size; i++) {
        int num = testNums[i];
        vector<int> factors = factorizer.primeFactors(num);

        cout << "Factors of " << num << ": ";
        for (int f : factors) {
            cout << f << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "Prime Tests" << endl;
    int primeTests[] = {77, 56, 3, 7, 99};
    int primeSize = 5;

    for (int i = 0; i < primeSize; i++) {
        int num = primeTests[i];
        cout << "Is it Prime(" << num << "): ";
        if (factorizer.primeCheck(num)) cout << "true";
        else cout << "false";
        cout << endl;
    }

    cout << endl;

    
    cout << "Composite Tests" << endl;
    int compTests[] = {1, 0 , 47, 3, 100};
    int compSize = 5;

    for (int i = 0; i < compSize; i++) {
        int num = compTests[i];
        cout << "Is it Composite(" << num << "): ";
        if (factorizer.compositeCheck(num)) cout << "true";
        else cout << "false";
        cout << endl;
    }

    return 0;
}