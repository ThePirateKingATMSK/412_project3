#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "LoadBalancer.h"

using namespace std;

/**
 * @brief Main function to run the load balancer simulation.
 * @return Exit status of the program.
 */
int main() {
    int numServers;    ///< Number of servers
    int clockCycles;   ///< Total number of clock cycles for the simulation

    cout << "How many servers: ";
    cin >> numServers;

    cout << "Enter the total number of clock cycles: ";
    cin >> clockCycles;

    LoadBalancer lb = LoadBalancer(numServers, clockCycles);

    lb.RunSimulation();

    return 0;
}
