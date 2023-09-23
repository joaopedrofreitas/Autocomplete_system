#ifndef HUFFMANTREE_HPP
#define HUFFMANTREE_HPP
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second 
#define pb push_back
#define K 20

class HUFFMANTree
{
private:
    pair<wstring, int> item;
    int prob;
    HUFFMANTree *right;
    HUFFMANTree *left;    

    struct comp
    {
        constexpr bool operator()(HUFFMANTree* const& a, HUFFMANTree* const& b) const noexcept
        {
            return a->prob >= b->prob;
        }
    };


public:
    HUFFMANTree();
    void insertH(HUFFMANTree*& t,vector<pair<wstring,int>>& Heap);
    void preorder(HUFFMANTree* t, ofstream& outputFile, string code);
    void inorder(HUFFMANTree* t, ofstream& outputFile, string code);
    void posorder(HUFFMANTree* t, ofstream& outputFile, string code);
    void Clear_HF(HUFFMANTree* t);
};
#endif