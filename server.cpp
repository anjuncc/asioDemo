#include <boost/asio.hpp>
#include <iostream>

using namespace boost;
int main() {
    //step 1
    std::string raw_ip_address = "127.0.0.1";
    unsigned short port_num = 3333;
    boost::system::error_code ec;
    asio::ip::address ip_address =
            asio::ip::address::from_string(raw_ip_address, ec);
    //step 2
    if (ec.value() != 0) {
        // Provided IP address is invalid. Breaking execution.
        std::cout
        << "Failed to parse the IP address. Error code = "
        << ec.value() << ". Message: " << ec.message();
        return ec.value();
    }
    // Step 3.
    asio::ip::tcp::endpoint ep(ip_address, port_num);
    // Step 4. The endpoint is ready and can be used to specify a
    // particular server in the network the client wants to
    // communicate with.
    return 0;
}