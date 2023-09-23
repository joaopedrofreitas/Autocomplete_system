#ifndef AVLTREE_H 
#define AVLTREE_H

#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second 
#define pb push_back
#define K 20

class AVLTree{
private:
	pair<wstring,int> item;
	AVLTree *left, *right;
	int weight;
public:
AVLTree();
void insertTree(AVLTree **t, pair<wstring,int> item);
void preordem(AVLTree *t,ofstream& outputFile);
void central(AVLTree *t,ofstream& outputFile);
void posordem(AVLTree *t,ofstream& outputFile);

int getWeight(AVLTree **t);
int getMaxWeight(int left, int right);

void rotacaoSimplesDireita(AVLTree **t);
void rotacaoSimplesEsquerda(AVLTree **t);
void rotacaoDuplaDireita(AVLTree **t);
void rotacaoDuplaEsquerda(AVLTree **t);
void Clear_AVL(AVLTree *t);

};
#endif