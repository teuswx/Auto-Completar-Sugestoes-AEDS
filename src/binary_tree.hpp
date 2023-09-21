#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>
#include <string.h>
#include<vector>
#include<fstream>
using namespace std;

class Record_3 {
public:
	int key;
	vector<string> value;

	// Record_3() {}
	Record_3(int key) :key(key), value(0) {}
	Record_3(int key, vector<string> value) :key(key), value(value) {}
	Record_3() {}
	// Record_3(int key);
	// Record_3(int key, int value);
	~Record_3() {}
};

class NO {
public:
	NO *esq;
	NO *dir;
	Record_3 reg;

	// NO(Record_3 reg) :esq(nullptr), dir(nullptr), reg(reg) {}
	// ~NO() { delete esq; delete dir; }
	NO(Record_3 reg);
	~NO();
};

class Tree_3 {
private:
	NO *root;
	NO *insertRecord(NO *atual, Record_3 reg);

	void preOrdemRecorsive(NO *atual);
	void centralRecorsive(NO *atual);
	void posOrdemRecorsive(NO *atual);
	void deleteTree(NO *atual);
public:
	Tree_3();
	~Tree_3();
	// Tree_3() { root = nullptr; }
	// ~Tree_3() { delete root; }
	// void insert(Record_3 reg) { root = insertRecord(root, reg); }
	void deleteTree();

	void insert(Record_3 reg);
	void preOrdem();
	void central();
	void posOrdem();
};

#endif