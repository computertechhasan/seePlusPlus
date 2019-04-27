/* 
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
#include <vector>
#include <iostream>

std::vector<int> twoSum(std::vector<int>& inputNums, int desiredSum) {
    int currSum = 0;
    std::vector<int> answer;
    for (int i = 0; i < inputNums.size(); ++i) {
        for (int j = i+1; j < inputNums.size() - 1; ++j) {
            if (inputNums[i] + inputNums[j] == desiredSum) {
                answer.push_back(i);
                answer.push_back(j);
                return answer;
            }
        }
    }
}

int main() {
    std::vector<int> input = {2,7,11,15};
    std::vector<int> checkAnswer = twoSum(input, 9);
    for (int i = 0; i < checkAnswer.size(); ++i) {
        std::cout << checkAnswer[i] << std::endl;
    }
}