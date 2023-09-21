#ifndef _ALGORITMO_HPP
#define _ALGORITMO_HPP
#include "Heap.hpp"
#include "binary_tree.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#define N 6
using namespace std;

class Algoritmo {
private:
    vector<vector<string>> pacote;
    vector<string> stopwords_v;
    vector<string> pontuacao_v;
public:
    Algoritmo();
    void lerArquivo();
    bool stopwords(string palavra);
    void separaStopwords();
    void separaPontuacao();
    bool removePontuacao(string palavra);
};
#endif
