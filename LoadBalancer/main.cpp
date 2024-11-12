#include <iostream>
#include <vector>
#include <limits>
#include "LoadBalancer.h"

int main() {
    int numServers;
    std::vector<std::vector<int>> matrix;
    std::vector<int> maxRequests;

    std::cout << "Ingrese el numero de servidores: ";
    std::cin >> numServers;
    std::cout << std::endl;

    matrix.resize(numServers, std::vector<int>(numServers, INF));
    maxRequests.resize(numServers);

    for (int i = 0; i < numServers; i++) {
        for (int j = 0; j < numServers; j++) {
             if (i == j) {
                matrix[i][j] = 0;
            } else if (j > i) {
                std::cout << "Ingrese el valor [" << i + 1 << "," << j + 1 << "] (INF si no hay conexion): ";
                std::string input;
                std::cin >> input;
                if (input == "INF") {
                    matrix[i][j] = INF;
                } else {
                    matrix[i][j] = std::stoi(input);
                }
                std::cout << std::endl;

                matrix[j][i] = matrix[i][j];
            }
        }
    }


    for (int i = 0; i < numServers; i++) {
        std::cout << "Ingrese la carga maxima del servidor " << i + 1 << ": ";
        std::cin >> maxRequests[i];
        std::cout << std::endl;
    }

    LoadBalancer lb(numServers, matrix, maxRequests);

    lb.distributeRequest(0);
    lb.distributeRequest(0);
    lb.distributeRequest(1);
    lb.completeRequest(2);
    lb.distributeRequest(1);

    lb.displayServerLoads();

    return 0;
}