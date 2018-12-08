#include <string>
#include <iostream>



int check_divis(int upper_check) {
    int curr_check = upper_check * upper_check;
    bool found = false;
    while (!found) {
        for (int i = 1; i <= upper_check; ++i) {
            if (curr_check % i == 0) {
                if (i < upper_check) {
                    continue;
                }
                found = true;
            }
            break;
        }
        curr_check++;
    }
    return curr_check;
}
int main() {
    std::cout << check_divis(20) << std::endl;
}