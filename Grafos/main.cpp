#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

const float INFINITO = std::numeric_limits<float>::infinity();

struct Vertice {
    float distancia;
    int indice;
    bool operator>(const Vertice &otro) const {
        return distancia > otro.distancia;
    }
};

std::pair<float, std::vector<int>> dijkstra(int num_vertices, int origen, int destino, const std::vector<std::vector<std::pair<int, float>>> &grafo) {
    std::vector<float> distancias(num_vertices, INFINITO);
    std::vector<int> predecesores(num_vertices, -1);
    distancias[origen] = 0;

    std::priority_queue<Vertice, std::vector<Vertice>, std::greater<Vertice>> cola_prioridad;
    cola_prioridad.push({0, origen});

    while (!cola_prioridad.empty()) {
        float distancia_minima = cola_prioridad.top().distancia;
        int vertice_actual = cola_prioridad.top().indice;
        cola_prioridad.pop();

        if (vertice_actual == destino) break;

        if (distancia_minima > distancias[vertice_actual]) continue;

        for (const auto &arista : grafo[vertice_actual]) {
            int vecino = arista.first;
            float peso = arista.second;

            if (distancias[vertice_actual] + peso < distancias[vecino]) {
                distancias[vecino] = distancias[vertice_actual] + peso;
                predecesores[vecino] = vertice_actual;
                cola_prioridad.push({distancias[vecino], vecino});
            }
        }
    }

    std::vector<int> ruta;
    for (int v = destino; v != -1; v = predecesores[v]) {
        ruta.push_back(v);
    }
    std::reverse(ruta.begin(), ruta.end());

    return {distancias[destino], ruta};
}

int main() {
    int n = 17;
    std::vector<std::vector<std::pair<int, float>>> grafo(n);

    grafo[0].push_back({1, 0.1f});
    grafo[1].push_back({0, 0.1f});

    grafo[1].push_back({2, 0.2f});
    grafo[2].push_back({1, 0.2f});

    grafo[2].push_back({3, 0.4f});
    grafo[3].push_back({2, 0.4f});

    grafo[3].push_back({4, 1.0f});
    grafo[4].push_back({3, 1.0f});

    grafo[4].push_back({5, 1.5f});
    grafo[5].push_back({4, 1.5f});

    grafo[5].push_back({6, 0.3f});
    grafo[6].push_back({5, 0.3f});

    grafo[6].push_back({7, 0.39f});
    grafo[7].push_back({4, 0.39f});

    grafo[3].push_back({8, 0.2f});
    grafo[8].push_back({3, 0.2f});

    grafo[8].push_back({9, 1.0f});
    grafo[9].push_back({8, 1.0f});

    grafo[9].push_back({10, 1.0f});
    grafo[10].push_back({9, 1.0f});

    grafo[10].push_back({9, 0.5f});
    grafo[11].push_back({8, 0.5f});

    grafo[11].push_back({12, 0.5f});
    grafo[12].push_back({11, 0.5f});

    grafo[12].push_back({7, 0.29f});
    grafo[7].push_back({12, 0.29f});

    grafo[0].push_back({13, 0.1f});
    grafo[13].push_back({0, 0.1f});

    grafo[13].push_back({14, 0.4f});
    grafo[14].push_back({13, 0.4f});

    grafo[14].push_back({15, 1.0f});
    grafo[15].push_back({14, 1.0f});

    grafo[15].push_back({16, 1.5f});
    grafo[16].push_back({15, 1.5f});

    grafo[16].push_back({7, 2.58f});
    grafo[7].push_back({16, 2.58f});

    int origen = 2;
    int destino = 13;

    auto resultado = dijkstra(n, origen, destino, grafo);
    float distancia_total = resultado.first;
    std::vector<int> camino = resultado.second;

    if (distancia_total == INFINITO) {
        std::cout << "No hay un camino desde el nodo " << origen << " al nodo " << destino << ".\n";
    } else {
        std::cout << "Camino más corto desde el nodo " << origen << " al nodo " << destino << ":\n";
        for (int i = 0; i < camino.size(); ++i) {
            std::cout << camino[i];
            if (i < camino.size() - 1) std::cout << " -> ";
        }
        std::cout << "\nDistancia total: " << distancia_total << "\n";
    }

    return 0;
}
