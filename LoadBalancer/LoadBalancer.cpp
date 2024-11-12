#include "LoadBalancer.h"

using namespace std;

LoadBalancer::LoadBalancer(int n, const vector<vector<int> > &matrix, const std::vector<int>& max)
: numServers(n), adjMatrix(matrix), requestsPerServer(n, 0), maxRequests(max){};


int LoadBalancer::distributeRequest(int startServer) {
    int minCost = INF;
    int selectedServer = -1 ;

    for (int i = 0; i < numServers; ++i) {
        if (i != startServer && adjMatrix[startServer][i] != INF) {
            if (requestsPerServer[i] < maxRequests[i] &&
                (selectedServer == -1 || requestsPerServer[i] < requestsPerServer[selectedServer] ||
                 (requestsPerServer[i] == requestsPerServer[selectedServer] && adjMatrix[startServer][i] < minCost))) {
                minCost = adjMatrix[startServer][i];
                selectedServer = i;
            }
        }
    }

    if (selectedServer != -1) {
        requestsPerServer[selectedServer]++;
        cout << "Se asigno la solicitud al Servidor " << selectedServer+1
                  << " desde Servidor " << startServer+1 << ", Carga actual: "
                  << requestsPerServer[selectedServer] << "\n";
    } else {
        cout << "No hay servidores disponibles desde el Servidor " << startServer+1 << "\n";
    }
    return selectedServer;

}

void LoadBalancer::completeRequest(int serverId) {
    // Se valida que el servidor exista y que exista dentro de los servidores inicializados
    // o que el servidor tenga al menos 1 solicitud
    if(serverId < 0 || serverId >= numServers || requestsPerServer[serverId] == 0) {
        cout << "Error: no hay solicitudes activas en el Servidor " << serverId+1 << "\n";
        return;
    }

    requestsPerServer[serverId]--;
    std::cout << "Solicitud completada en el Servidor " << serverId+1
             << ", Carga actual: " << requestsPerServer[serverId] << "\n";
}

void LoadBalancer::displayServerLoads() {
    std::cout << "Cargas actuales de los servidores:\n";
    for (int i = 0; i < numServers; ++i) {
        std::string status = (requestsPerServer[i]==maxRequests[i])? "lleno":"disponible";
        std::cout << "Servidor " << i+1 << ": " << requestsPerServer[i] << " solicitudes\n Estado: "<<status<<std::endl;
    }
}

