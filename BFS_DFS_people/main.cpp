#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <random>
#include <queue>
#include <stack>
#include <chrono>

using namespace std;

struct Person {
    string nombre;
    string direccion;
    string telefono;
    string codigoAdn;
};

class Graph {
private:
    vector<Person> people;
    vector<vector<int>> adjMatrix;
public:
    Graph(int size) : adjMatrix(size, vector<int>(size, 0)) {}

    void addPerson(const Person& person) {
        people.push_back(person);
    }

    void addRandomConnections(int connectionsPerNode) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(1, 10);
        uniform_int_distribution<> nodeDist(0, people.size() - 1);

        for (int i = 0; i < people.size(); ++i) {
            for (int j = 0; j < connectionsPerNode; ++j) {
                int targetNode = nodeDist(gen);
                if (targetNode != i) {
                    int weight = dist(gen);
                    adjMatrix[i][targetNode] = weight;
                    adjMatrix[targetNode][i] = weight;
                }
            }
        }
    }

    int BFS(const string& target_dna) {
        vector<bool> visited(people.size(), false);
        queue<int> q;

        auto start_time = chrono::high_resolution_clock::now();
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (people[node].codigoAdn == target_dna) {
                auto end_time = chrono::high_resolution_clock::now();
                chrono::duration<double> duration = end_time - start_time;
                cout << "BFS: Persona encontrada - Nombre: " << people[node].nombre
                          << ", ADN: " << people[node].codigoAdn
                          << ", Tiempo: " << duration.count() << " segundos\n";
                return node;
            }

            for (int i = 0; i < adjMatrix.size(); ++i) {
                if (adjMatrix[node][i] != 0 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end_time - start_time;
        cout << "BFS: No se encontró una persona con el ADN especificado, Tiempo: " << duration.count() << " segundos\n";
        return -1;
    }

    int DFS(const string& target_dna) {
        vector<bool> visited(people.size(), false);
        stack<int> s;

        auto start_time = chrono::high_resolution_clock::now();
        s.push(0);

        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (!visited[node]) {
                visited[node] = true;

                if (people[node].codigoAdn == target_dna) {
                    auto end_time = chrono::high_resolution_clock::now();
                    chrono::duration<double> duration = end_time - start_time;
                    cout << "DFS: Persona encontrada - Nombre: " << people[node].nombre
                              << ", ADN: " << people[node].codigoAdn
                              << ", Tiempo: " << duration.count() << " segundos\n";
                    return node;
                }

                for (int i = 0; i < adjMatrix.size(); ++i) {
                    if (adjMatrix[node][i] != 0 && !visited[i]) {
                        s.push(i);
                    }
                }
            }
        }

        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end_time - start_time;
        cout << "DFS: No se encontró una persona con el ADN especificado, Tiempo: " << duration.count() << " segundos\n";
        return -1;
    }
};

int main() {
    Graph graph(10000);

    ifstream file("people.txt");
    string line;
    while (getline(file, line)) {
        Person person;
        istringstream iss(line);
        getline(iss, person.nombre, ',');
        getline(iss, person.direccion, ',');
        getline(iss, person.telefono, ',');
        getline(iss, person.codigoAdn, ',');

        graph.addPerson(person);
    }

    graph.addRandomConnections(10);

    string target_dna = "TRRPDJPICX";

    int bfs_result = graph.BFS(target_dna);
    int dfs_result = graph.DFS(target_dna);

    if (bfs_result != -1 && dfs_result != -1) {
        cout << "Ambos algoritmos encontraron la persona con el ADN especificado.\n";
    } else if (bfs_result != -1) {
        cout << "BFS fue el único que encontró la persona con el ADN especificado.\n";
    } else if (dfs_result != -1) {
        cout << "DFS fue el único que encontró la persona con el ADN especificado.\n";
    } else {
        cout << "Ninguno de los algoritmos encontró la persona con el ADN especificado.\n";
    }

    return 0;
}