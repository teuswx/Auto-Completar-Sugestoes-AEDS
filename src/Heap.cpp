#include "Heap.hpp"

void Heap::limparHeap() {
    map.clear(); // Limpa o mapa
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> emptyHeap;
    swap(heap, emptyHeap); // Substitui a heap pela heap vazia
}

// Insere uma string para contar sua ocorrência
void Heap::insert(const string &value) {
    // cout << value << endl;
    map[value]++;
}

// Constrói a min heap baseada nas contagens das strings
void Heap::iniciandoHeap() {
    int cont = 0;
    for (auto pair = map.begin(); pair != map.end();) {
        heap.push({ pair->second, pair->first });
        auto aux = pair;
        pair++;
        map.erase(aux);
        cont++;
        if (cont == 20) {
            break;
        }
    }
}

void Heap::comparaTopItens() {

    for (auto &pair : map) {
        auto temp = heap.top();
        if (pair.second > heap.top().first) {

            heap.pop();
            heap.push({ pair.second, pair.first });
        }
    }
}

void Heap::printHeap() {

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> tempHeap = heap;

    while (!tempHeap.empty()) {
        cout << " " << tempHeap.top().second << " (" << tempHeap.top().first << " occorrencias)" << std::endl;
        tempHeap.pop();
    }
    cout << endl;
}

void Heap::criando_saida(string palavra_pesquisa, int cont_pesquisa) {
    if (cont_pesquisa != 0) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> tempHeap = heap;
        ofstream arquivo_saida;
        arquivo_saida.open("dataset/output.txt", ios::app);
        arquivo_saida << "\nPalavra pesquisada: " << palavra_pesquisa << endl;
        arquivo_saida << "Frequencia da palavra pesquisada: " << cont_pesquisa << endl;
        arquivo_saida << "Palavras mais relevates: [";
        while (!tempHeap.empty()) {
            // cout << tempHeap.top().second << endl;
            arquivo_saida << tempHeap.top().second << ", ";
            tempHeap.pop();
        }
        arquivo_saida << "]\nPre Ordem\nBinaria: " << endl;

        Tree_3 binaryTree;
        Record_3 bRec;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> tempbHeap = heap;
        vector<char *> teste;
        while (!tempbHeap.empty()) {
            bRec.value = { tempbHeap.top().second };
            bRec.key = tempbHeap.top().first;
            binaryTree.insert(bRec);
            tempbHeap.pop();
        }

        binaryTree.preOrdem();


        arquivo_saida << "\nÁrvore de huffman: " << endl;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> temphfHeap = heap;
        auto raiz_huffman = std::make_shared<Huffman_Tree>();

        while (!temphfHeap.empty()) {
            raiz_huffman->insere(std::make_shared<NO_Huffman>(temphfHeap.top().second, temphfHeap.top().first));
            temphfHeap.pop();
        }

        raiz_huffman->constroi();
        raiz_huffman->imprime();


        arquivo_saida << "\nAVL: " << endl;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> tempavlHeap = heap;
        Tree_AVL *tree = createTree_AVL();
        // TreeAvl tree;
        Record_AVL rec1;
        rec1.value = (char *)malloc(sizeof(char) * 100);

        while (!tempavlHeap.empty()) {
            rec1.key = tempavlHeap.top().first;
            strcpy(rec1.value, tempavlHeap.top().second.c_str());
            insertItem_AVL(&tree, rec1);
            tempavlHeap.pop();
        }
        preordem_AVL(tree);
        arquivo_saida.close();

    } else {
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> tempHeap = heap;
        ofstream arquivo_saida;
        arquivo_saida.open("dataset/output.txt", ios::app);
        arquivo_saida << "\nPalavra pesquisada: " << palavra_pesquisa << endl;
        arquivo_saida << "Frequencia da palavra pesquisada: " << cont_pesquisa << endl;
        arquivo_saida.close();
    }
}

