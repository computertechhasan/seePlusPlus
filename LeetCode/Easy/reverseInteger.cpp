/* Given a 32-bit signed integer, reverse digits of an integer. */

#include <string>
#include <iostream>

int reverse(int x) {
    std::string currNum = std::to_string(x);
    std::string reversed = "";
    for (int i = 0; i < currNum.length(); ++i) {
        //std::cout << currNum[currNum.length() - i] << std::endl;
        reversed += currNum[currNum.length() - i - 1];
    }
    return atoi(reversed.c_str());
}


int main() {
    int test = 1002;
    std::cout << reverse(test) << std::endl;
}