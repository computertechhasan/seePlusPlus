#ifndef BOAFACTORY_H
#define BOAFACTORY_H

#include <string>
#include "bidorask.h"

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