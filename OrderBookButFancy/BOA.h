#ifndef BIDORASK_H
#define BIDORASK_H

#include <string>

class BOA {
    public:
        BOA();
        BOA(double price, double volume, std::string side);
        double get_price();
        double get_volume();
        void set_price(double price);
        void set_volume(double volume);
        std::string side;
    private:
        double price;
        double volume;
};

#endif