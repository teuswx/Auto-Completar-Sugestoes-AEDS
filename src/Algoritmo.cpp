#include "Algoritmo.hpp"

Algoritmo::Algoritmo() {
    pacote.resize(15);
    separaStopwords();
    separaPontuacao();
}

void Algoritmo::separaPontuacao() {
    ifstream pont("dataset/pontuacao.txt");

    if (pont.is_open()) {
        string pontuacao;
        while (pont >> pontuacao) {
            this->pontuacao_v.push_back(pontuacao);
        }
        pont.close();
    } else {
        cout << "Não foi possível abrir o arquivo." << endl;
    }

    pont.close();
}

void Algoritmo::lerArquivo() {

    string word;
    string word_aux;
    string word_pesquisa;
    int i = 0, k2 = 1, cont_pesquisa = 0, tam = 0;
    Heap h;
    // Tree_2 arvore_b;

    if (std::remove("dataset/output.txt") != 0) {
    }

    ifstream arquivo("dataset/pesquisa.txt");

    while (arquivo >> word) {
        tam++;
    }
    arquivo.close();

    word = "";

    ifstream arquivo_pesquisa("dataset/pesquisa.txt");
    while (tam != 0) {
        ofstream arquivo_saida;

        arquivo_saida.open("dataset/output.txt", ios::app);
        arquivo_saida << "----------------------------------------------";
        arquivo_saida.close();

        arquivo_pesquisa >> word_pesquisa;
        for (int k = 1;k <= N;k++) {

            ifstream arquivo_entrada("dataset/input" + to_string(k) + ".txt");
            if (!arquivo_entrada) {
                throw "../main.cpp::lerTxt ---> Não foi possível abrir o arquivo de entrada";
            }

            while (arquivo_entrada >> word) {

                transform(word.begin(), word.end(), word.begin(), [](unsigned char c) { return tolower(c); });
                if (stopwords(word) != true) {
                    while (i < word.length()) {
                        char caractere = word[i];
                        // cout << caractere << " ";
                        string s(1, caractere);
                        // cout << s << endl;
                        // cout << to_string(caractere) << endl;
                        if (removePontuacao(s) != true) {
                            word_aux += caractere;
                        }
                        i++;
                    }
                    i = 0;

                    if (word_aux != "") {
                        h.insert(word_aux);
                        // h.insert(word);
                        // cout << word << endl;
                    }
                    if (word_aux == word_pesquisa) {
                        // if (word == word_pesquisa) {
                        cont_pesquisa++;
                    }

                    word_aux = "";
                }
            }

            word_aux = "";
            i = 0;
            arquivo_entrada.close();
            h.iniciandoHeap();
            h.comparaTopItens();
            ofstream arquivo_saida;
            arquivo_saida.open("dataset/output.txt", ios::app);
            arquivo_saida << "\n\nINPUT " << k;
            arquivo_saida.close();
            h.criando_saida(word_pesquisa, cont_pesquisa);
            // cout << "\nheap\n";
            // h.printHeap();
            // cout << "\n";
            h.limparHeap();


            cont_pesquisa = 0;
        }
        // k = 1;
        tam--;

    }
    arquivo_pesquisa.close();
}

bool Algoritmo::stopwords(string palavra) {

    auto it = find(this->stopwords_v.begin(), this->stopwords_v.end(), palavra);

    return (it != this->stopwords_v.end());
}
// função para separar as stopwords
void Algoritmo::separaStopwords() {

    ifstream arq("dataset/stopwords.txt");
    string stopword;

    if (arq.is_open()) {

        while (arq >> stopword) {
            this->stopwords_v.push_back(stopword);
            // cout << stopword << endl;
        }
        arq.close();
    } else {
        cout << "Não foi possível abrir o arquivo." << endl;
    }
}

bool Algoritmo::removePontuacao(string caractere) {
    // ifstream pont("dataset/pontuacao.txt");

    // char ctemp;

    // while (pont >> ctemp) {
    //     if (ctemp == caractere) {
    //         return true;
    //     }
    // }
    // pont.close();
    auto it = find(this->pontuacao_v.begin(), this->pontuacao_v.end(), caractere);
    return (it != this->pontuacao_v.end());
    // return false;
    // return false;
}