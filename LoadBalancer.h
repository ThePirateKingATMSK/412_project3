#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include "Server.h"
#include "Request.h"

using namespace std;

class LoadBalancer {
public:
    queue<Request> requestQueue;
    vector<Server> serverList;
    int cyclesLeft;
    int numServers;
    int queueCapacity;
    int numRejections;
    int serverIdCounter;
    int requestsProcessed;
    set<string> blockedIpRanges;

    LoadBalancer(int numServers, int timeLeft);
    void logMessage(const string& message);
    void RunSimulation();
    void BlockIpRange(const string& ipRange);
    bool IsBlocked(const string& ip);
    void ProcessRequests();
    void AssignRequestsToServers(); 
};
