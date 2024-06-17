#define _CRT_SECURE_NO_WARNINGS

#include "LoadBalancer.h"

// FULLY WORKING

LoadBalancer::LoadBalancer(int numServers, int cyclesLeft) {
    freopen("logfile.txt", "w", stdout);

    this->cyclesLeft = cyclesLeft;
    this->numServers = numServers;
    this->queueCapacity = numServers * 5;
    this->numRejections = 0;
    this->serverIdCounter = 0;
    this->requestsProcessed = 0;
    this->requestQueue = queue<Request>();
    this->serverList = vector<Server>();
}

void LoadBalancer::logMessage(const string& message) {
    cout << "[" << cyclesLeft << "] " << message << endl;
}

void LoadBalancer::ProcessRequests() {
    int numNewRequests = rand() % 5 + 1;
    logMessage("Received " + to_string(numNewRequests) + " new requests");
    for (int i = 0; i < numNewRequests; i++) {
        if (this->requestQueue.size() > this->queueCapacity) {
            logMessage("Rejected a request");
            this->numRejections++;
        }
        else {
            Request r = Request();
            this->requestQueue.push(r);
            logMessage("Request added: IP = " + r.ip + ", Time to complete = " + to_string(r.requestTime));
        }
    }
}

void LoadBalancer::AssignRequestsToServers() {
    // Check if each server is active and then add requests to them if possible
    for (int i = 0; i < this->serverList.size(); i++) {
        // Webserver requests another task if its countdown is at 0, meaning that it's free to take on a task
        if (this->serverList.at(i).cyclesLeft == 0 && !this->requestQueue.empty()) {
            this->serverList.at(i).currentRequest = this->requestQueue.front();
            this->serverList.at(i).cyclesLeft = this->serverList.at(i).currentRequest.requestTime;
            logMessage("Assigned Request: IP = " + this->serverList.at(i).currentRequest.ip
                + " to Server ID = " + to_string(this->serverList.at(i).serverId)
                + ", Request Length = " + to_string(this->serverList.at(i).currentRequest.requestTime));
            this->serverList.at(i).isUsed = true;
            this->requestQueue.pop();
        }

        // Mark progress in the webserver as it works through its task
        else {
            if (this->serverList.at(i).cyclesLeft > 0) {
                this->serverList.at(i).cyclesLeft--;
            }
            if (this->serverList.at(i).cyclesLeft == 0 && this->serverList.at(i).currentRequest.ip != "") {
                logMessage("A request from IP " + this->serverList.at(i).currentRequest.ip
                    + " has been processed by server " + to_string(this->serverList.at(i).serverId)
                    + " (in: " + to_string(this->serverList.at(i).currentRequest.requestTime) + " cycles)");
                this->requestsProcessed++;
                this->serverList.at(i).currentRequest = Request();
            }
        }
    }
}

void LoadBalancer::RunSimulation() {
    cout << "<============= BEGIN LOAD BALANCER ================>" << endl;

    // Create servers
    for (int i = 0; i < this->numServers; i++) {
        // Give the server an ID for output to logs
        Server ws = Server(this->serverIdCounter++);
        this->serverList.push_back(ws);
        logMessage("Server " + to_string(ws.serverId) + " has been added.");
    }

    // Iterate through the initial queue capacity and create a bunch of requests
    for (int i = 0; i < this->queueCapacity; i++) {
        Request r = Request();
        this->requestQueue.push(r);
        logMessage("Request added: IP = " + r.ip + ", Time to complete = " + to_string(r.requestTime));
    }

    while (cyclesLeft > 0) {
        // Add servers if we're close to exceeding queue capacity
        if (this->requestQueue.size() > this->queueCapacity - 2) {
            Server ws = Server(this->serverIdCounter++);
            this->serverList.push_back(ws);
            logMessage("Server " + to_string(ws.serverId) + " has been added.");
        }

        // Scale down if we're using less than half of our queue's capacity
        else if (this->requestQueue.size() <= this->queueCapacity / 2 && !this->requestQueue.size() > numServers) {
            logMessage("Server " + to_string(this->serverList.back().serverId) + " has been removed.");
            this->serverList.pop_back();
        }

        // Assign requests to servers
        AssignRequestsToServers();

        cyclesLeft--;

        // Randomly generate new requests at certain intervals
        if (cyclesLeft % 3 == 0) {
            ProcessRequests();
        }
    }

    cout << "<============= SUMMARY ================>" << endl;
    logMessage("Active web servers: " + to_string(this->serverList.size()));
    logMessage("Starting queue size: " + to_string(this->queueCapacity));
    logMessage("Rejected Requests: " + to_string(this->numRejections));
    logMessage("Total Finished Requests: " + to_string(this->requestsProcessed));
    logMessage("Ending queue size: " + to_string(this->requestQueue.size()));
    logMessage("Task Time range: 5 - 150 cycles\n");
}
