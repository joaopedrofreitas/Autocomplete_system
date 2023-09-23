#include "HUFFMANTree.hpp"

HUFFMANTree::HUFFMANTree(){}

void HUFFMANTree::insertH(HUFFMANTree*& t,vector<pair<wstring,int>>& Heap){
    priority_queue<HUFFMANTree*, vector<HUFFMANTree*>, comp> pq;
    pair<wstring,int> aux;
    for(auto& word : Heap){//PALAVRA POR PALAVRA NO HEAP
        HUFFMANTree *node = new HUFFMANTree;
        aux.f=word.f;
        aux.s=word.s;
        node->prob=word.s;
        node->item=aux;
        node->left=nullptr;
        node->right=nullptr;
        pq.push(node);
    }
    while(pq.size()>1){
        HUFFMANTree* esq = pq.top(); pq.pop();
        HUFFMANTree* dir = pq.top(); pq.pop();
        HUFFMANTree *aux1=new HUFFMANTree;
        aux1->prob = esq->prob + dir->prob;
        aux1->left=esq;
        aux1->right=dir;
        pq.push(aux1);

    }
    t=pq.top();
}

void HUFFMANTree::Clear_HF(HUFFMANTree* t){
    if(t !=nullptr){
        Clear_HF(t->left);
        Clear_HF(t->right);
        delete t;
    }
}

void HUFFMANTree::inorder(HUFFMANTree* t, ofstream& outputFile, string code){
    wstring_convert<codecvt_utf8<wchar_t>> change;
    if (t == nullptr)
    {
        return;
    }
    inorder(t->left, outputFile, code + "0");
    if(!t->item.f.empty()){
        outputFile<<change.to_bytes(t->item.f)<<" -> "<<t->item.s<<" : "<< code <<endl;
    }
    inorder(t->right, outputFile, code + "1");
}
void HUFFMANTree::posorder(HUFFMANTree* t, ofstream& outputFile, string code){
    if (t == nullptr)
    {
        return;
    }
    wstring_convert<codecvt_utf8<wchar_t>> change;
    posorder(t->left, outputFile, code + "0");
    posorder(t->right, outputFile, code + "1");
    if(!t->item.f.empty()){
        outputFile<<change.to_bytes(t->item.f)<<" -> "<<t->item.s<<" : "<< code <<endl;
    }
}
void HUFFMANTree::preorder(HUFFMANTree* t, ofstream& outputFile, string code){
    wstring_convert<codecvt_utf8<wchar_t>> change;
    if (t == nullptr)
    {
        return;
    }
    if(!t->item.f.empty()){
        outputFile<<change.to_bytes(t->item.f)<<" -> "<<t->item.s<<" : "<< code <<endl;
    }
    preorder(t->left, outputFile, code + "0");
    preorder(t->right, outputFile, code + "1");
}