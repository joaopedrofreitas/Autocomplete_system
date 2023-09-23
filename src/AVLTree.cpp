#include "AVLTree.hpp"

AVLTree::AVLTree(){
}

void AVLTree::insertTree(AVLTree **t, pair<wstring,int> word){

  if(*t == NULL){
    *t = new AVLTree;
    (*t)->left   = nullptr; 
    (*t)->right  = nullptr; 
    (*t)->weight = 0;
    (*t)->item   = word; 

  } else {
    
    if(word.s < (*t)->item.s){
      insertTree(&(*t)->left, word);
      if ((getWeight(&(*t)->left) - getWeight(&(*t)->right)) == 2){
      	if(word.s < (*t)->left->item.s)
      		rotacaoSimplesDireita(t);
      	else
      		rotacaoDuplaDireita(t);
      }
    }
    
    if(word.s > (*t)->item.s){
      insertTree(&(*t)->right, word);
      if ((getWeight(&(*t)->right) - getWeight(&(*t)->left)) == 2){
      	if(word.s > (*t)->right->item.s)
      		rotacaoSimplesEsquerda(t);
      	else
      		rotacaoDuplaEsquerda(t);
      }
    }
  
  }

  (*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
}


void AVLTree::preordem(AVLTree *t,ofstream& outputFile)
{
  if(!(t == nullptr)){
    wstring_convert<codecvt_utf8<wchar_t>> change;
    outputFile<<change.to_bytes(t->item.f)<<" -> "<<t->item.s<<endl;
    preordem(t->left,outputFile); 
    preordem(t->right,outputFile); 
  }
}


void AVLTree::central(AVLTree *t,ofstream& outputFile)
{
  if(!(t == nullptr)){
    central(t->left,outputFile); 
    wstring_convert<codecvt_utf8<wchar_t>> change;
    outputFile<<change.to_bytes(t->item.f)<<" -> "<<t->item.s<<endl;
    central(t->right,outputFile); 
  }
}

void AVLTree::posordem(AVLTree *t,ofstream& outputFile)
{
  if(!(t == nullptr)){
    posordem(t->left,outputFile); 
    posordem(t->right,outputFile); 
    wstring_convert<codecvt_utf8<wchar_t>> change;
    outputFile<<change.to_bytes(t->item.f)<<" -> "<<t->item.s<<endl;
  }
}


int AVLTree::getWeight(AVLTree **t){
	if(*t == nullptr)
		return -1;
	return (*t)->weight;
}

int AVLTree::getMaxWeight(int left, int right){
	if(left > right)
		return left;
	return right;
}

void AVLTree::rotacaoSimplesDireita(AVLTree **t){
	AVLTree *aux;
	aux = (*t)->left;
	(*t)->left = aux->right;
	aux->right = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
	aux->weight  = getMaxWeight(getWeight(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void AVLTree::rotacaoSimplesEsquerda(AVLTree **t){
	AVLTree *aux;
	aux = (*t)->right;
	(*t)->right = aux->left;
	aux->left = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
	aux->weight  = getMaxWeight(getWeight(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void AVLTree::rotacaoDuplaDireita(AVLTree **t){
	rotacaoSimplesEsquerda(&(*t)->left);
	rotacaoSimplesDireita(t);
}

void AVLTree::rotacaoDuplaEsquerda(AVLTree **t){
	rotacaoSimplesDireita(&(*t)->right);
	rotacaoSimplesEsquerda(t);
}

void AVLTree::Clear_AVL(AVLTree *t){
    if(t != nullptr){
        Clear_AVL(t->left);
        Clear_AVL(t->right);
        delete t;
    }
}