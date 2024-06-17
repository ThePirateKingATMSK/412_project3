#define _CRT_SECURE_NO_WARNINGS


#include <fstream>
#include <string>
#include "Request.cpp"

class Logger {
public:
    Logger(const std::string& filename) {
        logFile.open(filename, std::ios::out | std::ios::app);
        if (!logFile.is_open()) {
            throw std::runtime_error("Unable to open log file");
        }
    }
    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }
    void logRequest(const Request& request, bool rejected) {
        if (rejected) {
            logFile << "Request discarded: IP in = " << request.ipIn << ", IP out = " << request.ipOut << ", Time = " << request.requestTime << "\n";
        }
        else {
            logFile << "Request added: IP in = " << request.ipIn << ", IP out = " << request.ipOut << ", Time = " << request.requestTime << "\n";
        }
    }
    void logAssignment(const Request& request, int serverId) {
        logFile << "Assigned Request: IP in = " << request.ipIn
            << " to Server ID = " << serverId
            << ", Request Length = " << request.requestTime << "\n";
    }

    void logServerStatus(int serverId, bool status) {
        logFile << "Server ID = " << serverId << " is " << (status ? "available" : "unavailable") << "\n";
    }
    void logSummary(int activeServers, int requestsInQueue, int discardedRequests, int totalProcessedRequests) {
        logFile << "\n\n====== SUMMARY =========\n";
        logFile << "Active web servers: " << activeServers << "\n";
        logFile << "Requests still in queue: " << requestsInQueue << "\n";
        logFile << "Rejected Requests: " << discardedRequests << "\n";
        logFile << "Total Finished Requests: " << totalProcessedRequests << "\n";
    }

private:
    std::ofstream logFile;
};

