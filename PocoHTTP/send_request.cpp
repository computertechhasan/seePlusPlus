#include <Poco/Exception.h>
#include <Poco/StreamCopier.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPClientSession.h>
#include <iostream>
#include <string>


int main(int argc, char **argv) {
  try {
    int cat = 5;
    // prepare session
    Poco::URI uri("http://google.com/");
    Poco::Net::HTTPClientSession session(uri.getHost(), uri.getPort());

    // prepare path
    std::string path(uri.getPathAndQuery());
    if (path.empty()) path = "/";

    // send request
    Poco::Net::HTTPRequest req(Poco::Net::HTTPRequest::HTTP_GET, path, Poco::Net::HTTPMessage::HTTP_1_1);
    session.sendRequest(req);

    // get response
    Poco::Net::HTTPResponse res;

    // print response
    std::istream &is = session.receiveResponse(res);
    std::cout << res.getStatus() << " " << res.getReason() << std::endl;
    Poco::StreamCopier::copyStream(is, std::cout);
  }
  catch (int x) {
    return -1;
  }
  return 0;
}
