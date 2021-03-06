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
    void add_ask(double* price, double* volume) {
        if (*volume != 0) {
            this->asks[*price] = *volume;
        }
        else if (volume == 0) {
            this->asks.erase(*price);
        }
        else {
            std::cout << "Something weird happened adding an ask" << std::endl;
        }  
    }
    void add_bid(double* price, double* volume) {
        if (*volume != 0) {
            this->bids[*price] = *volume;
        }
        else if (volume == 0) {
            this->bids.erase(*price);
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
    double get_update_average() {
        if (this->update_times.size() != 0) {
            double curr_sum = 0;
            for (auto it = this->update_times.begin(); it != this->update_times.end(); ++it) {
                //std::cout << "curr update was " << *it << " ns" << std::endl;
                curr_sum += *it;
            }
            double curr_avg = curr_sum / double(this->update_times.size()) / 1000.0;
            return curr_avg;
        }
        return 0.0;   
    }
    double get_update_variance() {
        double curr_variance = 0.0;
        double curr_average_update = this->get_update_average();
        double t = this->update_times[0];
        double curr_diff = 0.0;
        for (int i = 0; i < this->update_times.size(); ++i) {
            curr_diff += (this->update_times[i] - curr_average_update);
        }
        return (curr_diff * curr_diff) / (this->update_times.size() - 1);
    }
    void print_update_stats() {
        if (this->update_times.size() != 0) {
            double curr_avg = get_update_average();
            double curr_variance = get_update_variance();
            std::cout << "The book is " << this->bids.size() << " bids / " << this->asks.size() << " asks deep " << std::endl;
            std::cout << "THe average update was " << curr_avg << " microseconds for " << this->update_times.size() << " updates" << std::endl << std::endl;
            std::cout << "THe variance for updates was " << curr_variance << " microseconds for " << this->update_times.size() << " updates" << std::endl << std::endl;
    }
    }
};




int main() {
    std::string PRODUCT_ID = "BTC-USD";
    int DEPTH = 5;
    auto my_book = LimitOrderBook(PRODUCT_ID, DEPTH);
    int jMAX = 10000;
    int iMAX = 9999;
    std::string current_message_type = "l2update";
    
    

    double twentythree = 23.00;
    double twentysix = 26.00;
    double twentytwo = 22.00;
    double twentyfive = 25.00;
    double twentyone = 21.00;
    double twentyfour = 24.00;
    double twenty = 20.00;


    /*
    auto start_time = std::chrono::high_resolution_clock::now();
    my_book.add_ask(&twentythree, &twentysix);
    auto end_time = std::chrono::high_resolution_clock::now();
    my_book.update_times.push_back((std::chrono::duration_cast<std::chrono::nanoseconds>(end_time-start_time)).count());
    start_time = std::chrono::high_resolution_clock::now();
    my_book.add_ask(&twentytwo, &twentyfive);
    end_time = std::chrono::high_resolution_clock::now();
    my_book.update_times.push_back((std::chrono::duration_cast<std::chrono::nanoseconds>(end_time-start_time)).count());

    start_time = std::chrono::high_resolution_clllvmock::now();
    my_book.add_bid(&twentyone, &twentyfour);
    end_time = std::chrono::high_resolution_clock::now();
    my_book.update_times.push_back((std::chrono::duration_cast<std::chrono::nanoseconds>(end_time-start_time)).count());
    start_time = std::chrono::high_resolution_clock::now();
    my_book.add_bid(&twenty, &twentythree);
    end_time = std::chrono::high_resolution_clock::now();
    my_book.update_times.push_back((std::chrono::duration_cast<std::chrono::nanoseconds>(end_time-start_time)).count());
    
    my_book.print_book();
    my_book.print_update_stats();
    */

    // /*
    std::vector<double> average_updates;
<<<<<<< HEAD
    int jMax = 500;
    int iMax = 9999;
    for (int j = 0; j < jMax; ++j) {
=======
    std::vector<double> average_variances;

    for (int j = 0; j < jMAX; ++j) {
>>>>>>> 46f7f4a321053433b02d4c0fc746ce91b0dd7b76
        auto my_book = LimitOrderBook(PRODUCT_ID, DEPTH);
        double curr_price = 0;
        double curr_volume = 0;
        std::chrono::high_resolution_clock::time_point start_time;
        std::chrono::high_resolution_clock::time_point end_time;
        BOA change;
        std::vector<BOA> bids;
        std::vector<BOA> asks;
<<<<<<< HEAD
        for (int i = 0; i < iMax; ++i) {
=======
        for (int i = 0; i < iMAX; ++i) {
>>>>>>> 46f7f4a321053433b02d4c0fc746ce91b0dd7b76
            change = BOA();
            start_time = std::chrono::high_resolution_clock::now();

            if (current_message_type == "l2update") {
                if (change.side == "sell") {
                    my_book.add_ask(&change.price, &change.volume);
                }
                else if (change.side == "buy") {
                    my_book.add_bid(&change.price, &change.volume);
                }
            }
            end_time = std::chrono::high_resolution_clock::now();
            //std::cout << "curr time" << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time-start_time).count() << std::endl;
            my_book.update_times.push_back((std::chrono::duration_cast<std::chrono::nanoseconds>(end_time-start_time)).count());
<<<<<<< HEAD
            if (i == iMax-1) {
=======
            if (i == iMAX - 1) {
>>>>>>> 46f7f4a321053433b02d4c0fc746ce91b0dd7b76
                //my_book.print_book();
                //my_book.print_update_stats();
                average_updates.push_back(my_book.get_update_average());
                average_variances.push_back(my_book.get_update_variance());
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
<<<<<<< HEAD
    std::cout << "Across " << jMax << " passes of I max depth " << iMax <<", the average update was " << curr_avg << " microseconds " << std::endl;
=======
    double curr_variance_avg = curr_var_sum / double(average_variances.size()); 
    std::cout << "Across " << jMAX << " passes of " << iMAX << " max depth, the avg update was " << curr_avg << " micros & avg var was " << curr_variance_avg << std::endl;
>>>>>>> 46f7f4a321053433b02d4c0fc746ce91b0dd7b76
    // */
    return 0;
}
