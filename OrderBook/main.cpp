#include <iostream>
#include <string>
#include <map>
#include <chrono>
#include <vector>
#include <random>

struct BOA {
    double MAX_PRICE = 9.65;
    double MAX_VOLUME = 1000;
    double MIN_PRICE = 8.39;
    double MIN_VOLUME = 0.0001;
    double price;
    double volume;
    std::string side;

    BOA() {
        this->price = random_price(MIN_PRICE, MAX_PRICE);
        this->volume = random_volume(MIN_VOLUME, MAX_VOLUME);
        this->side = sideOfOrder();
    }
    std::string sideOfOrder() {
        int random = rand() % 2;
        if (random == 0) {
            return "buy";
        }
        return "sell";
    }
    double random_price(double min, double max) {
        return ((double)rand() / RAND_MAX) * (max - min) + min;
    }
    double random_volume(double min, double max) {
        return ((double)rand() / RAND_MAX) * (max - min) + min;
    }
};


struct LimitOrderBook {
    // Stored as price: volume
    std::map<double, double> bids;
    std::map<double, double> asks;
    std::string product_id;
    int print_depth;
    int depth;
    std::vector<double> update_times;
    LimitOrderBook(std::string product_id, int depth) {
        this->product_id = product_id;
        this->depth = depth * 10000;
        this->print_depth = depth;
    }
    void add_ask(double price, double volume) {
        if (volume != 0) {
            this->asks[price] = volume;
        }
        else if (volume == 0) {
            this->asks.erase(price);
        }
        else {
            std::cout << "Something weird happened adding an ask" << std::endl;
        }  
    }
    void add_bid(double price, double volume) {
        if (volume != 0) {
            this->bids[price] = volume;
        }
        else if (volume == 0) {
            this->bids.erase(price);
        }
        else {
            std::cout << "Something weird happened adding an bid" << std::endl;
        }  
    }
    void print_book() {
        std::cout << "Asks:" << std::endl;
        int curr_printed = 0;
        for (auto it = this->asks.begin(); it != asks.end(); ++it) {
            std::cout << "Volume " << it->second << " Price " << it->first << std::endl;
            curr_printed++;
            if (curr_printed == this->print_depth) {
                break;
            }
        }
        std::cout << "Bids:" << std::endl;
        curr_printed = 0;
        for (auto it = this->bids.begin(); it != bids.end(); ++it) {
            std::cout << "Volume " << it->second << " Price " << it->first << std::endl;
            curr_printed++;
            if (curr_printed == this->print_depth) {
                break;
            }
        }
        std::cout << "The book is " << this->bids.size() << " bids / " << this->asks.size() << " asks deep " << std::endl;
    }
    double get_update_stats() {
        if (this->update_times.size() != 0) {
            double curr_sum = 0;
            for (auto it = this->update_times.begin(); it != this->update_times.end(); ++it) {
                //std::cout << "curr update was " << *it << " ns" << std::endl;
                curr_sum += *it;
            }
            double curr_avg = curr_sum / double(this->update_times.size()) / 1000.0;
            return curr_avg;
        }
        
    }
    void print_update_stats() {
        if (this->update_times.size() != 0) {
            double curr_avg = get_update_stats();
            std::cout << "The book is " << this->bids.size() << " bids / " << this->asks.size() << " asks deep " << std::endl;
            std::cout << "THe average update was " << curr_avg << " microseconds for " << this->update_times.size() << " updates" << std::endl << std::endl;
        }
    }
};




int main() {
    std::string PRODUCT_ID = "BTC-USD";
    int DEPTH = 5;

    std::string current_message_type = "l2update";
    
    

    /*
    auto start_time = std::chrono::high_resolution_clock::now();
    my_book.add_ask(23.00, 26.00);
    auto end_time = std::chrono::high_resolution_clock::now();
    my_book.update_times.push_back((std::chrono::duration_cast<std::chrono::nanoseconds>(end_time-start_time)).count());
    start_time = std::chrono::high_resolution_clock::now();
    my_book.add_ask(22.00, 25.00);
    end_time = std::chrono::high_resolution_clock::now();
    my_book.update_times.push_back((std::chrono::duration_cast<std::chrono::nanoseconds>(end_time-start_time)).count());

    start_time = std::chrono::high_resolution_clock::now();
    my_book.add_bid(21.00, 24.00);
    end_time = std::chrono::high_resolution_clock::now();
    my_book.update_times.push_back((std::chrono::duration_cast<std::chrono::nanoseconds>(end_time-start_time)).count());
    start_time = std::chrono::high_resolution_clock::now();
    my_book.add_bid(20.00, 23.00);
    end_time = std::chrono::high_resolution_clock::now();
    my_book.update_times.push_back((std::chrono::duration_cast<std::chrono::nanoseconds>(end_time-start_time)).count());
    
    my_book.print_book();
    my_book.print_update_stats();
    */

    ///*
    std::vector<double> average_updates;

    for (int j = 0; j < 10000; ++j) {
        auto my_book = LimitOrderBook(PRODUCT_ID, DEPTH);
        double curr_price = 0;
        double curr_volume = 0;
        std::chrono::high_resolution_clock::time_point start_time;
        std::chrono::high_resolution_clock::time_point end_time;
        BOA change;
        std::vector<BOA> bids;
        std::vector<BOA> asks;
        for (int i = 0; i < 99999; ++i) {
            change = BOA();
            start_time = std::chrono::high_resolution_clock::now();

            if (current_message_type == "l2update") {
                if (change.side == "sell") {
                    my_book.add_ask(change.price, change.volume);
                }
                else if (change.side == "buy") {
                    my_book.add_bid(change.price, change.volume);
                }
            }
            end_time = std::chrono::high_resolution_clock::now();
            my_book.update_times.push_back((std::chrono::duration_cast<std::chrono::nanoseconds>(end_time-start_time)).count());
            if (i == 99998) {
                //my_book.print_book();
                //my_book.print_update_stats();
                average_updates.push_back(my_book.get_update_stats());
            }
        }
    }
    double curr_sum = 0;
    for (auto it = average_updates.begin(); it != average_updates.end(); ++it) {
        //std::cout << *it << std::endl;
        curr_sum += *it;
    }
    double curr_avg = curr_sum / double(average_updates.size());
    std::cout << "Across J passes of I max depth, the average update was " << curr_avg << " microseconds " << std::endl;
    // */
}
