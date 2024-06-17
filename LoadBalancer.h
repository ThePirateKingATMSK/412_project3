#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include "Server.h"
#include "Request.h"

using namespace std;

/**
 * @class LoadBalancer
 * @brief Simulates a load balancer for handling web requests.
 */
class LoadBalancer {
public:
    queue<Request> requestQueue;     ///< Queue of incoming requests
    vector<Server> serverList;       ///< List of servers
    int cyclesLeft;                  ///< Number of cycles left for the simulation
    int numServers;                  ///< Number of servers
    int queueCapacity;               ///< Maximum capacity of the request queue
    int numRejections;               ///< Number of rejected requests
    int serverIdCounter;             ///< Counter for assigning server IDs
    int requestsProcessed;           ///< Number of processed requests
    set<string> blockedIpRanges;     ///< Set of blocked IP ranges

    /**
     * @brief Constructor for the LoadBalancer class.
     * @param numServers The number of servers in the load balancer.
     * @param timeLeft The total number of cycles for the simulation.
     */
    LoadBalancer(int numServers, int timeLeft);

    /**
     * @brief Logs a message to the log file.
     * @param message The message to log.
     */
    void logMessage(const string& message);

    /**
     * @brief Runs the load balancer simulation.
     */
    void RunSimulation();

    /**
     * @brief Blocks a specific IP range.
     * @param ipRange The IP range to block.
     */
    void BlockIpRange(const string& ipRange);

    /**
     * @brief Checks if an IP address is blocked.
     * @param ip The IP address to check.
     * @return True if the IP is blocked, false otherwise.
     */
    bool IsBlocked(const string& ip);

    /**
     * @brief Processes incoming requests.
     */
    void ProcessRequests();

    /**
     * @brief Assigns requests to available servers.
     */
    void AssignRequestsToServers();
};
