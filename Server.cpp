#include "Server.h"

Server::Server(int serverId) {
    this->serverId = serverId;
    this->cyclesLeft = 0;
    this->isUsed = false; // Initialize isUsed to false
}
