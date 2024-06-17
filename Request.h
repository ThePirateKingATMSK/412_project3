#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Request {
public:
    string ip;
    int requestTime;

    Request();
    string GenerateRandomIp();
};
