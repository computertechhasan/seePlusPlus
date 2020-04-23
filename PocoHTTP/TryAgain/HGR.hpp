#ifndef HGR_H
#define HGR_H

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
        HGR() {

        };
        HGR(std::string uri) {
            this->uri = uri;
        };
        Poco::Net::HTTPResponse send_request() {
            Poco::URI curr_uri(this->uri);
            Poco::Net::HTTPClientSession session(curr_uri.getHost(), curr_uri.getPort());
            std::string path(curr_uri.getPathAndQuery());
            if (path.empty()) path = "/";
            Poco::Net::HTTPRequest req(Poco::Net::HTTPRequest::HTTP_GET, path, Poco::Net::HTTPMessage::HTTP_1_1);
            session.sendRequest(req);
            Poco::Net::HTTPResponse res;
            std::istream &is = session.receiveResponse(res);
            return res;
        };
    private:
        std::string uri;
};

#endif