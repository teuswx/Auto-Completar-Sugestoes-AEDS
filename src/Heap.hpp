#ifndef HEAP_HPP
#define HEAP_HPP
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <fstream>
#include "binary_tree.hpp"
#include "avl.hpp"
#include "HuffmanTree.hpp"
#include<string>

using namespace std;
class Heap {
private:
    unordered_map<string, int> map;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> heap;
    // Record_1 rec_1;
    //vector<pair<int,string>> heap;
public:
    auto getMap() { return map; }

    void insert(const std::string &value);
    void iniciandoHeap();
    string getMostFrequent();
    void comparaTopItens();
    void printHeap();
    void limparHeap();
    void criando_saida(string palavra_pesquisa, int cont_pesquisa);
    void criandoArvores();
};

#endif

