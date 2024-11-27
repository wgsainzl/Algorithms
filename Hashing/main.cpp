// main.cpp
#include "HashTable.h"

using namespace std;

int main() {
    // Tamaño de la tabla hash
    int tableSize = 10;
    HashTable hashTable(tableSize);

    // Insertar elementos
    hashTable.insert(4);
    hashTable.insert(14);
    hashTable.insert(29);

    hashTable.insert(3);
    hashTable.insert(11);

    // Mostrar la tabla hash
    cout << "Tabla Hash:\n";
    hashTable.display();

    // Buscar elementos
    cout << "\nBuscar 14: " << (hashTable.search(14) ? "Encontrado" : "No encontrado") << "\n";
    cout << "Buscar 6: " << (hashTable.search(6) ? "Encontrado" : "No encontrado") << "\n";

    // Eliminar un elemento
    hashTable.remove(15);
    cout << "\nDespues de eliminar 15:\n";
    hashTable.display();

    return 0;
}