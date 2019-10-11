#ifndef BIDORASK_H
#define BIDORASK_H

#include <string>

namespace BOA {
    class BOA {
        public:
            BOA();
            double MAX_PRICE;
            double MAX_VOLUME;
            double MIN_PRICE;
            double MIN_VOLUME;
            double price;
            double volume;
            std::string side;
        private:
            std::string sideOfOrder();
            double random_price();
            double random_volume();
    };
}

#endif