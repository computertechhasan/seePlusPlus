#include "boa_factory.h"
#include <random>

BOAFactory::BOAFactory(double min_price, double max_price, double min_volume, double max_volume) {
    this->min_price = min_price;
    this->max_price = max_price;
    this->min_volume = min_volume;
    this->max_volume = max_volume;
}

BOA BOAFactory::create_boa() {
    std::string side;
    int random = rand() % 2;
    if (random == 0) {
        side = "buy";
    }
    else {
        side = "sell";
    }
    return BOA(random_price(), random_volume(), side);
}

std::string BOAFactory::create_boa_json() {
    BOA curr_boa = this->create_boa();
    return "{\"type\":\"l2update\",\"price\":\"" + std::to_string(curr_boa.get_price()) + "\",\"volume\":\"" + std::to_string(curr_boa.get_volume()) + "\",\"side\":\"" + curr_boa.side + "\"}";
}

double BOAFactory::random_price() {
    return ((double)rand() / RAND_MAX) * (this->max_price - this->min_price) + this->min_price;
}

double BOAFactory::random_volume() {
    return ((double)rand() / RAND_MAX) * (this->max_volume - this->min_volume) + this->min_volume;
}