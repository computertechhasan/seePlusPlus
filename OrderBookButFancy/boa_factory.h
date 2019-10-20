#ifndef BOAFACTORY_H
#define BOAFACTORY_H

#include <string>
#include "BOA.h"

class BOAFactory {
    public:
        BOAFactory(double min_price, double max_price, double min_volume, double max_volume);
        BOA create_boa();
        std::string create_boa_json();
    private:
        double min_price;
        double max_price;
        double min_volume;
        double max_volume;
        double random_price();
        double random_volume();
};

#endif