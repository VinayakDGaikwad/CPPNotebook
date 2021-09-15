#include<iostream>

using namespace std;

class numbers {

public:
    void even_odd(int num) {
        if (num % 2 != 0) 
            cout << "This is odd";
        else 
            cout << "This is even";
    }

    void print_prime_no()
    {
        bool isPrime;

        int i;
        for (i = 0; i <= 20; i++) {
            // Skip 0 and 1 as they are
            // neither prime nor composite
            if (i == 1 || i == 0)
                continue;
            // flag variable to tell
            // if i is prime or not
            isPrime = true;

            for (int j = 2; j <= i / 2; ++j) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
        }

        // flag = 1 means i is prime
        // and flag = 0 means i is not prime
        if (isPrime == 1)
            cout << i << "\n";
    }


};

//int main() {
//
//    numbers n1;
//    n1.even_odd(23);
//    return 0;
//};