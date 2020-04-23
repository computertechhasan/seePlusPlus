#include "HGR.hpp"
#include <string.h>


int main() {
    int cat = 5;
    std::string uri = "http://google.com/";
    HGR my_req = HGR(uri);
    auto response = my_req.send_request();
    std::cout << response.getContentType() << std::endl;
}