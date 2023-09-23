#ifndef BINARYTREE_H 
#define BINARYTREE_H
#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second 
#define pb push_back
#define K 20

class BINARYTree{

private:
    pair<wstring,int> item;
    BINARYTree *left;
    BINARYTree *right;

public:
    BINARYTree();
    bool TVazia(BINARYTree **t);
    void insertTree(BINARYTree **t, pair<wstring,int> word);
    void preordem(BINARYTree *t,ofstream& outputFile);
    void central(BINARYTree *t,ofstream& outputFile);
    void posordem(BINARYTree *t,ofstream& outputFile);
    void Clear_BI(BINARYTree *t);
};
#endif