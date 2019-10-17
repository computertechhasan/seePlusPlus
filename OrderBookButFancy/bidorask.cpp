#include "bidorask.h"
#include <string>

BOA::BOA(double price, double volume, std::string side) {
    this->price = price;
    this->volume = volume;
    this->side = side;
}

double BOA::get_price() {
    return this->price;
}
double BOA::get_volume() {
    return this->volume;
}
void BOA::set_price(double price) {
    this->price = price;
}
void BOA::set_volume(double volume) {
    this->volume = volume;
}