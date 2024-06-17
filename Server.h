#pragma once

#include "Request.h"

class Server {
public:
    int serverId;
    int cyclesLeft;
    bool isUsed; // New member to indicate if the server is used
    Request currentRequest;

    Server(int serverId);
};
