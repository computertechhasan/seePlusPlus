#include "OrderBook.h"
#include <map>
#include <iostream>
#include <vector>

OrderBook::OrderBook(std::string product_id, int depth) {
    this->product_id = product_id;
    this->print_depth = depth;
    this->depth = depth * 10000;
}

void OrderBook::add_bid(BOA new_bid) {
    double curr_vol = new_bid.get_volume();
    if (curr_vol != 0) {
        this->bids[new_bid.get_price()] = new_bid.get_volume();
    }
    else if (curr_vol == 0) {
        this->bids.erase(new_bid.get_price());
    }
    else {
        std::cout << "Something weird happened adding a bid" << std::endl;
    }    
}

void OrderBook::add_ask(BOA new_ask) {
    double curr_vol = new_ask.get_volume();
    if (curr_vol != 0) {
        this->asks[new_ask.get_price()] = curr_vol;
    }
    else if (curr_vol == 0) {
        this->asks.erase(new_ask.get_price());
    }
    else {
        std::cout << "Something weird happened adding an ask" << std::endl;
    }    
}

void OrderBook::print_book() {
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

double OrderBook::get_update_average() {
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

double OrderBook::get_update_variance() {
    double curr_variance = 0.0;
    double curr_average_update = this->get_update_average();
    double t = this->update_times[0];
    double curr_diff = 0.0;
    for (int i = 0; i < this->update_times.size(); ++i) {
        curr_diff += (this->update_times[i] - curr_average_update);
    }
    return (curr_diff * curr_diff) / (this->update_times.size() - 1);
}

void OrderBook::print_update_stats() {
    if (this->update_times.size() != 0) {
            double curr_avg = get_update_average();
            double curr_variance = get_update_variance();
            std::cout << "The book is " << this->bids.size() << " bids / " << this->asks.size() << " asks deep " << std::endl;
            std::cout << "THe average update was " << curr_avg << " microseconds for " << this->update_times.size() << " updates" << std::endl << std::endl;
            std::cout << "THe variance for updates was " << curr_variance << " microseconds for " << this->update_times.size() << " updates" << std::endl << std::endl;
    }
}