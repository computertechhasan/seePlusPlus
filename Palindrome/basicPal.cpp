#include <iostream>

bool checkPalindrome(std::string testString) {
    if (testString.length() < 2) {
        return true;
    }
    for (int i = 0; i < testString.length(); ++i) {
        if (testString[i] == testString[testString.length() - i - 1]) {
            continue;
        }
        return false;
    }
    return true;
}

int main() {
    std::string test = "noon";
    double start_time = std::
    if (checkPalindrome(test)) {
        std::cout << "Yup" << std::endl;
    }
    std::cout << "running" << std::endl;
    return 0;
}