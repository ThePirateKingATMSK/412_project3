#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * @class Request
 * @brief Represents a request in the load balancer system.
 */
class Request {
public:
    string ip;         ///< IP address of the request
    int requestTime;   ///< Time required to complete the request

    /**
     * @brief Constructor for the Request class.
     */
    Request();

    /**
     * @brief Generates a random IP address.
     * @return A string representing the generated IP address.
     */
    string GenerateRandomIp();
};
