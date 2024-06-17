#pragma once

#include "Request.h"

/**
 * @class Server
 * @brief Represents a server in the load balancer system.
 */
class Server {
public:
    int serverId;       ///< Unique identifier for the server
    int cyclesLeft;     ///< Number of cycles left for the server to complete the current request
    bool isUsed;        ///< Flag indicating if the server is currently in use
    Request currentRequest; ///< The current request being processed by the server

    /**
     * @brief Constructor for the Server class.
     * @param serverId The unique identifier for the server.
     */
    Server(int serverId);
};
