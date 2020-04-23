#ifndef HTTPGETREQUEST_H
#define HTTPGETREQUEST_H

#include <string>
#include <Poco/Exception.h>
#include <Poco/StreamCopier.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPClientSession.h>
#include <iostream>
#include <string>

class HGR {
    public:
        HTTPGETRequest();
        HTTPGETRequest(std::string uri);
        Poco::Net::HTTPResponse send_request();
    private:
        std::string uri;
};

#endif