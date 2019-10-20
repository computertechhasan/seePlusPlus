#include <iostream>
#include "BOA.h"
#include "boa_factory.h"
#include "OrderBook.h"
#include <chrono>

#include "include/rapidjson/document.h"
#include "include/rapidjson/writer.h"
#include "include/rapidjson/stringbuffer.h"

int main() {
    srand(time(NULL));
    BOAFactory my_boa_factory = BOAFactory(0.5, 200, 0.5, 200);
    std::string PRODUCT_ID = "BTC-USD";
    std::string current_message_type = "l2update";
    std::chrono::high_resolution_clock::time_point start_time;
    std::chrono::high_resolution_clock::time_point end_time;

    std::vector<double> average_updates;
    std::vector<double> average_variances;

    std::vector<double> json_parse_times;

    std::string generated_boa_json;
    rapidjson::Document curr_boa_json;
    
    int DEPTH = 5;
    int jMAX = 100;
    int iMAX = 9999;
    BOA change;

    for (int j = 0; j < jMAX; ++j) {
        auto my_order_book = OrderBook(PRODUCT_ID, DEPTH);
        for (int i = 0; i < iMAX; ++i) {
            generated_boa_json = my_boa_factory.create_boa_json();
            // std::cout << generated_boa_json << std::endl;
            start_time = std::chrono::high_resolution_clock::now();
            curr_boa_json.Parse(generated_boa_json.c_str());
            if (curr_boa_json["type"].GetString() == "l2update") {
                if (curr_boa_json["side"] == "sell") {
                    my_order_book.add_ask(BOA(atof(curr_boa_json["price"].GetString()), atof(curr_boa_json["volume"].GetString()), curr_boa_json["side"].GetString()));
                }
            }
            end_time = std::chrono::high_resolution_clock::now();
            json_parse_times.push_back((std::chrono::duration_cast<std::chrono::nanoseconds>(end_time-start_time)).count());
            // std::cout << "curr parse took" << (std::chrono::duration_cast<std::chrono::nanoseconds>(end_time-start_time)).count() << "ns" << std::endl;
        }
    }
    double curr_json_update_sum = 0.0;
    for (auto it = json_parse_times.begin(); it != json_parse_times.end(); ++it) {
        curr_json_update_sum += *it;
    }
    double curr_json_parse_avg = curr_json_update_sum / json_parse_times.size();
    std::cout << "Parsing " << iMAX*jMAX << " jsons took an average of " << curr_json_parse_avg << "ns" << std::endl;

    // /*
    for (int j = 0; j < jMAX; ++j) {
        auto my_order_book = OrderBook(PRODUCT_ID, DEPTH);
        
        for (int i = 0; i < iMAX; ++i) {
            change = my_boa_factory.create_boa();
            start_time = std::chrono::high_resolution_clock::now();

            if (current_message_type == "l2update") {
                if (change.side == "sell") {
                    my_order_book.add_ask(change);
                }
                else if (change.side == "buy") {
                    my_order_book.add_bid(change);
                }
            }
            end_time = std::chrono::high_resolution_clock::now();
            my_order_book.update_times.push_back((std::chrono::duration_cast<std::chrono::nanoseconds>(end_time-start_time)).count());
            if (i == iMAX - 1) {
                average_updates.push_back(my_order_book.get_update_average());
                average_variances.push_back(my_order_book.get_update_variance());
            }
        }
    }
    double curr_sum = 0.0;
    for (auto it = average_updates.begin(); it != average_updates.end(); ++it) {
        //std::cout << *it << std::endl;
        curr_sum += *it;
    }
    double curr_var_sum = 0.0;
    for (auto it = average_variances.begin(); it != average_variances.end(); ++it) {
        curr_var_sum += *it;
    }
    double curr_avg = curr_sum / double(average_updates.size());
    double curr_variance_avg = curr_var_sum / double(average_variances.size()); 
    std::cout << "Across " << jMAX << " passes of " << iMAX << " max depth, the avg update was " << curr_avg << " micros & avg var was " << curr_variance_avg << std::endl;
    // */
    return 0;
}

rapidjson::Document parse_boa_json(std::string &) {

}


