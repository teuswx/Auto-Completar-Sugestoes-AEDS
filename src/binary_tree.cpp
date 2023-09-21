#include "binary_tree.hpp"
NO::NO(Record_3 reg) {
	this->esq = nullptr;
	this->dir = nullptr;
	this->reg = reg;
}
NO::~NO() {
	delete this->esq;
	delete this->dir;
}
Tree_3::Tree_3() {
	this->root = nullptr;
}
Tree_3::~Tree_3() {
	delete this->root;
}
void Tree_3::insert(Record_3 reg) {
	root = this->insertRecord(this->root, reg);
}

NO *Tree_3::insertRecord(NO *atual, Record_3 reg) {
	if (atual == nullptr) return new NO(reg);

	if (reg.key < atual->reg.key)
		atual->esq = insertRecord(atual->esq, reg);
	else if (reg.key > atual->reg.key)
		atual->dir = insertRecord(atual->dir, reg);
	else
		atual->reg.value.push_back(reg.value.front());

	return atual;
}

void Tree_3::preOrdemRecorsive(NO *atual) {

	ofstream arquivo_saida;
	arquivo_saida.open("dataset/output.txt", ios::app);

	if (atual != nullptr) {
		arquivo_saida << "[frequência: " << atual->reg.key << ", valor: ";
		for (auto value : atual->reg.value) {
			arquivo_saida << value << " ";
		}
		arquivo_saida << "] ";

		preOrdemRecorsive(atual->esq);
		preOrdemRecorsive(atual->dir);
	}
	arquivo_saida.close();
}

void Tree_3::centralRecorsive(NO *atual) {
	if (atual != nullptr) {
		centralRecorsive(atual->esq);
		cout << atual->reg.key << " ";
		centralRecorsive(atual->dir);
	}
}

void Tree_3::posOrdemRecorsive(NO *atual) {
	if (atual != nullptr) {
		posOrdemRecorsive(atual->esq);
		posOrdemRecorsive(atual->dir);
		cout << atual->reg.key << " ";
	}
}

void Tree_3::preOrdem() {
	preOrdemRecorsive(root);
}

void Tree_3::central() {
	cout << "Central   { ";
	centralRecorsive(root);
	cout << "}" << endl;
}

void Tree_3::posOrdem() {
	cout << "Recursive { ";
	posOrdemRecorsive(root);
	cout << "}" << endl;
}
void Tree_3::deleteTree(NO *atual) {
	if (atual == nullptr) {
		return;
	}

	// Primeiro, apaga os nós filhos (recursivamente)
	deleteTree(atual->esq);
	deleteTree(atual->dir);

	// Depois, apaga o próprio nó
	delete atual;
}

// Método público para deletar a árvore
void Tree_3::deleteTree() {
	deleteTree(root);
	root = nullptr; // Define a raiz como nullptr após a exclusão da árvore
}