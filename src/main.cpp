#include <iostream>
#include "binary_tree.hpp"
#include "Algoritmo.hpp"
#include "Heap.hpp"
#include "avl.hpp"
#include <string.h>
using namespace std;
#include "HuffmanTree.hpp"

int main() {

	// cout << "Arvore de Huffman" << endl << endl;

	// auto raiz_huffman = std::make_shared<Huffman_Tree>();

	// raiz_huffman->insere(std::make_shared<NO_Huffman>("fa", 9));
	// raiz_huffman->insere(std::make_shared<NO_Huffman>("aaa", 9));
	// raiz_huffman->insere(std::make_shared<NO_Huffman>("css", 12));
	// raiz_huffman->insere(std::make_shared<NO_Huffman>("bdd", 13));
	// raiz_huffman->insere(std::make_shared<NO_Huffman>("dww", 16));
	// raiz_huffman->insere(std::make_shared<NO_Huffman>("avv", 45));

	// raiz_huffman->constroi();
	// raiz_huffman->imprime();

	// cout << "\n\n======================" << endl << endl;

	// Tree_3 tree;
	// Record_3 rec1;
	// rec1.key = 103;
	// rec1.value = { "agsa" };
	// tree.insert(rec1);
	// rec1.key = 323;
	// rec1.value = { "eu" };
	// tree.insert(rec1);
	// rec1.key = 232;
	// rec1.value = { "ola" };
	// tree.insert(rec1);
	// rec1.key = 34;
	// rec1.value = { "bdia" };
	// tree.insert(rec1);
	// rec1.key = 34;
	// rec1.value = { "ro" };
	// tree.insert(rec1);

	// tree.preOrdem();

	Algoritmo a;
	a.lerArquivo();
	// Tree_AVL *tree = createTree_AVL();
	// // TreeAvl tree;
	// Record_AVL rec1;
	// rec1.value = (char *)malloc(sizeof(char) * 100);
	// strcpy(rec1.value, "blabla");
	// rec1.key = 10;
	// insertItem_AVL(&tree, rec1);
	// strcpy(rec1.value, "oooo");
	// // rec1.value = { "agsa" };
	// // tree.insert(rec1);
	// rec1.key = 20;
	// insertItem_AVL(&tree, rec1);
	// strcpy(rec1.value, "oooo");
	// // rec1.value = { "eu" };
	// // tree.insert(rec1);
	// rec1.key = 20;
	// insertItem_AVL(&tree, rec1);
	// strcpy(rec1.value, "baaaa");
	// // rec1.value = { "ola" };
	// // tree.insert(rec1);
	// rec1.key = 40;
	// insertItem_AVL(&tree, rec1);
	// strcpy(rec1.value, "claaa");
	// // rec1.value = { "ola" };
	// // tree.insert(rec1);
	// rec1.key = 50;
	// insertItem_AVL(&tree, rec1);
	// strcpy(rec1.value, "osoaos");
	// // rec1.value = { "ola" };
	// // tree.insert(rec1);
	// rec1.key = 34;
	// insertItem_AVL(&tree, rec1);
	// strcpy(rec1.value, "sasasas");
	// // rec1.value = { "bdia" };
	// // tree.insert(rec1);
	// // rec1.key = 34;
	// // rec1.value = { "ro" };
	// // tree.insert(rec1);

	// preordem_AVL(tree);

	// AVL_2 *root = createTree_AVL();

	// Record_AVL rec1;
	// rec1.key = 10;
	// // rec1.value = { "agsa" };
	// insertItem_AVL(&root, rec1);
	// rec1.key = 20;
	// // rec1.value = { "eu" };
	// insertItem_AVL(&root, rec1);
	// rec1.key = 30;
	// // rec1.value = { "ola" };
	// insertItem_AVL(&root, rec1);
	// rec1.key = 40;
	// // rec1.value = { "ola" };
	// insertItem_AVL(&root, rec1);
	// rec1.key = 50;
	// // rec1.value = { "ola" };
	// insertItem_AVL(&root, rec1);
	// rec1.key = 34;
	// // rec1.value = { "bdia" };
	// insertItem_AVL(&root, rec1);
	// rec1.key = 34;
	// // rec1.value = { "ro" };
	// insertItem_AVL(&root, rec1);

	// preordem_AVL(root);
	// cout << endl;


	return 0;
}