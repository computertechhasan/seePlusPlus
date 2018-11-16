#include <string>
#include <iostream>

bool checkPalindrome(int testInt) {
    std::string testString = std::to_string(testInt);
    for (int i = 0; i < testString.length()/2; ++i) {
        if (testString[i] == testString[testString.length()-(i+1)]) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}

int findLargestPal() {
    
}

int main() {
    //std::cout << checkPalindrome(42) << std::endl;
    std::cout << findLargestPal() << std::endl;
}