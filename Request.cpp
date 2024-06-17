#include "Request.h"

Request::Request() {
    this->ip = this->GenerateRandomIp();
    this->requestTime = (30 + rand()) % 50;
    if (this->requestTime > 150) {
        this->requestTime = 150;
    }
}

string Request::GenerateRandomIp() {
    int octet1 = rand() % 255;
    int octet2 = rand() % 255;
    int octet3 = rand() % 255;
    int octet4 = rand() % 255;

    return to_string(octet1) + "." + to_string(octet2) + "." + to_string(octet3) + "." + to_string(octet4);
}
