#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <string>
#include "bidorask.h"
#include <map>
#include <vector>

class LimitOrderBook {
    public:
    LimitOrderBook(std::string product_id, int depth);
    private:
        std::string product_id;
        int print_depth;
        int depth;
        std::map<double, double> bids;
        std::map<double, double> asks;
        std::vector<double> update_times;
};

class BOAFactory {
    public:
        BOAFactory(double min_price, double max_price, double min_volume, double max_volume);
        BOA create_boa();
    private:
        double min_price;
        double max_price;
        double min_volume;
        double max_volume;
        double random_price();
        double random_volume();
};

#endif