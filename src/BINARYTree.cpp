#include "BINARYTree.hpp"

BINARYTree::BINARYTree(){}

bool BINARYTree::TVazia(BINARYTree **t){
  return *t == nullptr;
}


void BINARYTree::insertTree(BINARYTree **t, pair<wstring,int> word){

  if(TVazia(t)){
    *t = new BINARYTree;
    (*t)->left = nullptr; 
    (*t)->right = nullptr; 
    (*t)->item = word; 
  
  } 
  else{
    if(word.s >= (*t)->item.s){
      insertTree(&(*t)->right, word);
    }
    else{
      insertTree(&(*t)->left, word);
    }
  }

}

void BINARYTree::preordem(BINARYTree *t,ofstream& outputFile)
{
  if(!(t == nullptr)){
    wstring_convert<codecvt_utf8<wchar_t>> change;
    outputFile<<change.to_bytes(t->item.f)<<" -> "<<t->item.s<<endl;
    preordem(t->left,outputFile); 
    preordem(t->right,outputFile); 
  }
}


void BINARYTree::central(BINARYTree *t,ofstream& outputFile)
{
  if(!(t == nullptr)){
    central(t->left,outputFile); 
    wstring_convert<codecvt_utf8<wchar_t>> change;
    outputFile<<change.to_bytes(t->item.f)<<" -> "<<t->item.s<<endl;
    central(t->right,outputFile); 
  }
}

void BINARYTree::posordem(BINARYTree *t,ofstream& outputFile)
{
  if(!(t == nullptr)){
    posordem(t->left,outputFile); 
    posordem(t->right,outputFile); 
    wstring_convert<codecvt_utf8<wchar_t>> change;
    outputFile<<change.to_bytes(t->item.f)<<" -> "<<t->item.s<<endl;
  }
}

void BINARYTree::Clear_BI(BINARYTree *t){
  if(t != nullptr){
    Clear_BI(t->left);
    Clear_BI(t->right);
    delete t;
  }
}

