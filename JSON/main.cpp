#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include <chrono>

int main() {
    std::chrono::high_resolution_clock::time_point start_time;
    std::chrono::high_resolution_clock::time_point end_time;
    int64_t curr_time;
    double price = 25.02;
    double volume = 13.22;
    const char* side = "sell";
    std::string new_boa = "{\"type\":\"l2update\",\"price\":\"" + std::to_string(price) + "\",\"volume\":\"" + std::to_string(volume) + "\",\"side\":\"" + side + "\"}";
    std::cout << new_boa << std::endl;

    rapidjson::Document my_json_doc;
    start_time = std::chrono::high_resolution_clock::now();
    my_json_doc.Parse(new_boa.c_str());
    end_time = std::chrono::high_resolution_clock::now();
    curr_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time-start_time).count();

    std::cout << "curr time is " << curr_time << "ns" << std::endl;

    double curr_price = atof(my_json_doc["price"].GetString());
    double curr_vol = atof(my_json_doc["volume"].GetString());
    std::string curr_side = my_json_doc["side"].GetString();
    std::string curr_type = my_json_doc["type"].GetString();

    std::cout << "Price is " << curr_price << " vol is " << curr_vol << " side is " << curr_side << " type is " << curr_type << std::endl;

    return 0;
}