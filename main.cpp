#include <iostream>
#include <vector>
using namespace std;

class Factorizer {
public:
    vector<int> primeFactors(int n) {
        vector<int> factors;

        // return empty if n <= 1
        if (n <= 1) {
            return factors;
        }

        // try every number from 2 up to n
        for (int i = 2; i <= n; i++) {
            while (n % i == 0) {
                factors.push_back(i);
                n = n / i;
            }
        }

        return factors;
    }
};
int main() {
    Factorizer factorizer;

    // List of test numbers
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

    return 0;
}

