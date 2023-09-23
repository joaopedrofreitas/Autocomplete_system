#ifndef __FUNCTIONS_HPP
#define __FUNCTIONS_HPP
#include<bits/stdc++.h>
#include "BINARYTree.hpp"
#include "AVLTree.hpp"
#include "HUFFMANTree.hpp"
using namespace std;
#define f first
#define s second 
#define pb push_back
#define K 20

typedef struct{
  bool operator()(const pair<wstring,int>& a,const pair<wstring,int>& b) const{
    return a.s>b.s;
  }
} greater1;


class Utils{
    private:
        unordered_set<wstring> Hash_stopwords;
        unordered_set<wstring> Words;
        unordered_map<wstring,int> Main_Hash;
        vector<pair<wstring,int>> Heap;
    public:
        void set_Hash_stopwords(unordered_set<wstring> Hash_stopwords);
        unordered_set<wstring> get_Hash_stopwords();
        void set_Main_Hash(unordered_map<wstring,int> Main_Hash);
        unordered_map<wstring,int> get_Main_Hash();    
        void set_Heap(vector<pair<wstring,int>> Heap);
        vector<pair<wstring,int>> get_Heap();

        void Print_Heap();
        void init_Heap();
        void init_Stopwords(const locale loc);
        void init_Words(const locale loc);
        void ADD_Main_Hash(wstring word);
        void Check_Words(ofstream& outputFile);
        void ADD_Kplus1_Item(wstring word);
        void insertBinaryT(ofstream& outputFile);
        void insertAVL(ofstream& outputFile);
        void insertHuffman(ofstream& outputFile);
        wchar_t* getText(const locale loc, string name);
        
        void print_Main_Hash();
        void print_stopwords();
        void Clear_Text_Data();
};
#endif