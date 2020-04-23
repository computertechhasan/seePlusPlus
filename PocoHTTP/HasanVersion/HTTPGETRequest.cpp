#include "HTTPGETRequest.h"
#include <string>

HTTPGETRequest::HTTPGETRequest() {

}

HTTPGETRequest::HTTPGETRequest(std::string uri) {
    this->uri = uri;
}

Poco::Net::HTTPResponse HTTPGETRequest::send_request() {
    Poco::URI curr_uri(this->uri);
    Poco::Net::HTTPClientSession session(curr_uri.getHost(), curr_uri.getPort());
    std::string path(curr_uri.getPathAndQuery());
    if (path.empty()) path = "/";
    Poco::Net::HTTPRequest req(Poco::Net::HTTPRequest::HTTP_GET, path, Poco::Net::HTTPMessage::HTTP_1_1);
    session.sendRequest(req);
    Poco::Net::HTTPResponse res;
    std::istream &is = session.receiveResponse(res);
    return res;
}