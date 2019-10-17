#include "bidorask.h"
#include <iostream>
#include "boa_factory.h"

int main() {
    BOAFactory my_boa_factory = BOAFactory(0.5, 200, 0.5, 200);
    for (int i = 0; i < 5; i++) {
        auto curr_boa = my_boa_factory.create_boa();
        std::cout << "price: " << curr_boa.get_price() << " volume: " << curr_boa.get_volume() << std::endl;
    }
}
