#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "LoadBalancer.h"

using namespace std;

int main() {
    int numServers;
    int clockCycles;

    cout << "How many servers: ";
    cin >> numServers;

    cout << "Enter the total number of clock cycles: ";
    cin >> clockCycles;

    LoadBalancer lb = LoadBalancer(numServers, clockCycles);


    lb.RunSimulation();

    return 0;
}
