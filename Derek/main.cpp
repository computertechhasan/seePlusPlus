#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <sstream>
#include <numeric>
#include <ctime>
#include <cmath>


int global = 0;
const double global_PI = 3.14;

// you can give your func specs up here and put them after so main knows what they are
double add_numbers(double first, double second);

void assign_name();

void assign_age(int age);

void assign_age(int* age);


int main(int argc, char** argv) {
    std::cout << "Hello world!" << std::endl;

    bool my_bool = true; // can also be false
    char my_char = 'a'; // can store chars

    // how to find the min or max of a data type
    std::cout << "min of long double " << std::numeric_limits<long double>::min() << std::endl;
    std::cout << "max of long double " << std::numeric_limits<long double>::max() << std::endl;
    
    // floats lose precision at 7th decimal
    float f1 = 1.1111111;
    float f2 = 1.1111111;
    // print number with 7 decimal places
    printf("Sum = %.7f\n", (f1+f2));

    std::string my_string = "i am a string";
    std::string another_string;
    std::cout << "please enter a number" << std::endl;
    // std::cin >> another_string;
    std::cout << "you entered " << another_string << std::endl;

    if (5 > 4) {
        std::cout << "if statements are a thing" << std::endl;
    } else if (4 > 3) {
        std::cout << "else if are also" << std::endl;
    } else {
        std::cout << "i know this" << std::endl;
    }


    int age = 18;
    // ternary is a thing
    bool can_vote = (age >= 18) ? true : false;
    // give bool string instead of 1 and 0
    std::cout.setf(std::ios::boolalpha);
    std::cout << "can you vote? " << can_vote << std::endl;

    // array is fixed size data of same type
    int int_array[5] = {1};
    int another_array[] = {1, 2, 3};
    // two dim arrays also a thing
    int two_dim[2][2] = {{2, 1}, {1, 2}};
    // and three
    int three_dim[2][2][2] = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};


    // vectors are not fixed size
    std::vector<int> int_vector(2);
    int_vector[0] = 1;
    int_vector[0] = 2;
    int_vector.push_back(3);

    // while loops are a thing
    int while_incr = 0;
    while (while_incr < 20) {
        while_incr += 1;
    }
    
    // while can come from stream
    std::vector<std::string> words;
    std::stringstream ss("Some random words");
    std::string curr_word;
    while(getline(ss, curr_word, ' ')) {
        words.push_back(curr_word);
    }

    // for loops are a thing
    for (int i = 0; i < words.size(); ++i) {
        std::cout << words[i] << std::endl;
    }

    // do while happens atleast once
    int checker = 0;
    do {
        std::cout << "broken" << std::endl;
    } while (checker > 1);

    // strings are mutable!
    std::string first_string = "I'm a string";

    std::cout << "lets add 1 and two " << add_numbers(1, 2) << std::endl;

    // c++ func calls are by value
    int ages = 6;
    assign_age(ages);
    std::cout << "i know what this does lol " << ages << std::endl;
    int* middle_man = NULL;
    middle_man = &ages;
    assign_age(middle_man);
    std::cout << "age is " << ages << std::endl;

    int int_arr[] = {1, 2, 3, 4, 5};
    int* int_pt_array = int_arr;
    std::cout << "this should be be 1: " << *int_pt_array << std::endl;
    int_pt_array++;
    std::cout << "this should be 2: " << *int_pt_array << std::endl;


    return 0;
}

// we can write functions // c++ has default params!
double add_numbers(double first = 0, double second = 0) {
    return first + second;
}


// functions have scope...no duh lol
void assign_name() {
    std::string name = "Hasan";
}
// funcs are copy by value
void assign_age(int age) {
    age = 5;
}
// but we can make them copy by ref!
void assign_age(int* age) {
    *age = 5;
}