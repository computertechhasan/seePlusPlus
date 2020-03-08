#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <chrono>

int main() {
    
    std::chrono::high_resolution_clock::time_point start_time;
    std::chrono::high_resolution_clock::time_point end_time;
    std::vector<std::string> curr_message_holder;
    std::stringstream curr_fix_message("55=MST");
    std::string tmp;
    int star = 1;
    int64_t curr_time;

    start_time = std::chrono::high_resolution_clock::now();
    while(std::getline(curr_fix_message, tmp, '=')) {
        curr_message_holder.push_back(tmp);
    }
    if (curr_message_holder[0] == "55") {
        star++;
    }
    end_time = std::chrono::high_resolution_clock::now();
    curr_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time-start_time).count();

    std::cout << "curr time is " << curr_time << "ns" << std::endl;

    return 0;
}