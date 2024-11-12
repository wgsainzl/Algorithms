// LoadBalancer.h
#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <vector>
#include <iostream>
#include <climits>

using namespace std;

const int INF = INT_MAX;

class LoadBalancer {
private:
    int numServers;
    std::vector<std::vector<int>> adjMatrix;
    std::vector<int> requestsPerServer;
    std::vector<int> maxRequests;

public:
    LoadBalancer(int n, const std::vector<std::vector<int>>& matrix, const std::vector<int>& max);
    int distributeRequest(int startServer);
    void completeRequest(int serverId);
    void displayServerLoads();
};

#endif // LOADBALANCER_H