#include <string>
#include <iostream>

bool check_palindrome(int test_int) {
    std::string test_string = std::to_string(test_int);
    for (int i = 0; i < test_string.length()/2; ++i) {
        if (test_string[i] == test_string[test_string.length()-(i+1)]) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}

int find_largest_pal() {
    int curr_max = -1;
    for (int i = 999; i > 99; i--) {
        for (int j = 999; j > 99; j--) {
            if (check_palindrome(i*j) && i * j > curr_max) {
                curr_max = i*j;
            }
        }
    }
    return curr_max;
}

int main() {
    //std::cout << checkPalindrome(42) << std::endl;
    //std::cout << checkPalindrome(424) << std::endl;
    std::cout << find_largest_pal() << std::endl;
}