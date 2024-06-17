#include "Server.h"

/**
 * @brief Constructor for the Server class.
 * @param serverId The unique identifier for the server.
 */
Server::Server(int serverId) {
    this->serverId = serverId;
    this->cyclesLeft = 0;
    this->isUsed = false; // Initialize isUsed to false
}
