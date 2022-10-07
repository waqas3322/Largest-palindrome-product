#include <iostream>
#include <time.h>
bool is_palindrome(int &num) { // Determine if a given number is a palindrome or not
    int reverse=0, copy=num, digit;
    do {
        digit = copy % 10;
        reverse = reverse*10 + digit;
        copy /= 10;
    } while (copy != 0);
    return (reverse == num);
}
int main(void) {
    double time_spent = 0.0;
    clock_t begin = clock();

    int largest_palindrome = 0;
    for (int i=999; i>99; i--) {
        for (int j=999; j>99; j--) {
            if (i < largest_palindrome/1000) { // Optimalization
                // std::cout << "Any value lower than " << i << " will, when multiplied by 999, never exceed the largest palindrome (" << largest_palindrome << ")."<< '\n';
                std::cout << "No larger palindromes possible." << '\n';
                i = 0;
                j = 0;
            } else {
                int product = i*j;
                if (is_palindrome(product) && product>largest_palindrome) {
                    std::cout << "Found palindrome! " << i << " * " << j << " == " << product << '\n';
                    largest_palindrome = product;

                    // More optimalization (no product of the current iteration of i can be larger than the current palindrome, so skip to next iteration)
                    j = 0;
                }
            }
        }
    }

    // Program execution time
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    std::cout << "Elapsed time is " << time_spent << " seconds." << std::endl;
    return 0;
}
