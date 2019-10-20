#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <string>
#include "BOA.h"
#include <map>
#include <vector>

class OrderBook {
    public:
        OrderBook(std::string product_id, int depth);
        void add_bid(BOA new_bid);
        void add_ask(BOA new_ask);
        BOA get_best_bid();
        BOA get_best_ask();
        void print_book();
        std::vector<double> update_times;
        double get_update_average();
        double get_update_variance();
        void print_update_stats();
    private:
        std::string product_id;
        int print_depth;
        int depth;
        std::map<double, double> bids;
        std::map<double, double> asks;
};

#endif