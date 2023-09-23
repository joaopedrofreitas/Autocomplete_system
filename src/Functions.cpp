#include "Functions.hpp"


void Utils::init_Stopwords(const locale loc){//OK
    wstring word;
    wifstream file("./dataset/stopwords.txt");
    if(!file.is_open()){
        cerr << "PROBLEMA NA ABERTURA DO ARQUIVO" << endl;
        exit(1);
    }
    file.imbue(loc);
    while (file >> word){this->Hash_stopwords.insert(word);}
    file.close();
}

void Utils::ADD_Main_Hash(wstring word){//OK
    if(Hash_stopwords.find(word) == Hash_stopwords.end()){
        this->Main_Hash[word]++;   
    }
}

void Utils::print_Main_Hash(){//OK
    for (auto const &pair: Main_Hash) {
        wcout << "{" << pair.f << ": " << pair.s << "}\n";
    }
}

void Utils::print_stopwords(){//OK
    for (auto itr = Hash_stopwords.begin(); itr != Hash_stopwords.end();itr++){
        wcout << (*itr) << endl;
    }
}

void Utils::init_Heap(){//OK
    for (auto const &pair: Main_Hash){
        if(Heap.size() < K){
            this->Heap.pb(make_pair(pair.f,pair.s));
            if(Heap.size() == K){
                make_heap(Heap.begin(),Heap.end(),greater1());
            }
        }
        else{
            pop_heap(Heap.begin(), Heap.end());
            Heap.pop_back();
            if(pair.s > Heap[0].s){
                pop_heap(Heap.begin(), Heap.end());
                Heap.pop_back();
                Heap.pb(make_pair(pair.f,pair.s));
                push_heap(Heap.begin(),Heap.end());
            }
        }
    }

}

void Utils::set_Hash_stopwords(unordered_set<wstring> Hash_stopwords){//OK
    this->Hash_stopwords=Hash_stopwords;
} 
unordered_set<wstring> Utils::get_Hash_stopwords(){//OK
    return this->Hash_stopwords;
}

void Utils::set_Main_Hash(unordered_map<wstring,int> Main_Hash){//OK
    this->Main_Hash=Main_Hash;
}

unordered_map<wstring,int> Utils::get_Main_Hash(){//OK
    return this->Main_Hash;
}

void Utils::set_Heap(vector<pair<wstring,int>> Heap){//OK
    this->Heap=Heap;
}

vector<pair<wstring,int>>  Utils::get_Heap(){//OK
    return this->Heap;    
}


void Utils::Print_Heap(){//OK
    for (auto const &pair: Heap) {
        wcout << "{" << pair.f << ": " << pair.s << "}\n";
    }
    cout<<"\n======================================================"<<endl;
}

wchar_t* Utils::getText(const locale loc, string name)//OK
{
  wifstream txt(name, ios::binary);

  if(!txt.is_open())
  {
    cerr << "PROBLEMA NA ABERTURA DO ARQUIVO " << name << endl;
    exit(1);
  }

  txt.imbue(loc);
  txt.seekg(0, ios::end);
  streampos tamanho = txt.tellg();
  txt.seekg(0, ios::beg);
  wchar_t* buffer = new wchar_t[tamanho];
  txt.read(buffer, tamanho);
  txt.close();

  return buffer;
}

void Utils::Clear_Text_Data(){
    this->Main_Hash.clear();
    this->Heap.clear();
}

void Utils::init_Words(const locale loc){
    wstring word;
    wifstream file("./dataset/words.txt");
    if(!file.is_open()){
        cerr << "PROBLEMA NA ABERTURA DO ARQUIVO" << endl;
        exit(1);
    }
    file.imbue(loc);
    while (file >> word){
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        this->Words.insert(word);
    }
    file.close();
}

void Utils::Check_Words(ofstream& outputFile){
    int qt=0;
        for(auto itr = Words.begin(); itr != Words.end();itr++){
            if(Main_Hash.find((*itr)) != Main_Hash.end()){//SE ESTIVER NO TEXTO
                for (auto const &pair: Heap){//SE ESTIVER NO HEAP
                    if(pair.f == (*itr)){
                        qt++;
                    }
                }
                if(qt!=0){//A PALAVRA ESTÁ NO HEAP
                    ADD_Kplus1_Item((*itr));
                }
                outputFile<<"===================================="<<endl;
                wstring ws((*itr));
                string palavra(ws.begin(),ws.end());
                outputFile<<"PALAVRA: "<<palavra<<endl;
                insertBinaryT(outputFile);
                insertAVL(outputFile);
                insertHuffman(outputFile);
                
            }
        }    
}

void Utils::ADD_Kplus1_Item(wstring itr){
    Main_Hash.erase(itr);
    this->Heap.clear();
    init_Heap();
    /*cout<<"=========DURANTE============"<<endl;
    Print_Heap();*/
}

void Utils::insertBinaryT(ofstream& outputFile){//OK
    BINARYTree Bt;
    BINARYTree *B_root=nullptr;
    for(auto const &pair: Heap){
        Bt.insertTree(&B_root,pair);
    }
    outputFile<<"-----------ÁRVORE BINÁRIA-----------"<<endl;
    outputFile<<"=============IN======================="<<endl;
    Bt.central(B_root,outputFile);
    outputFile<<"==============POS========================="<<endl;
    Bt.posordem(B_root,outputFile);
    outputFile<<"===============PRE========================"<<endl;
    Bt.preordem(B_root,outputFile);
    outputFile<<"========================================="<<endl;
    Bt.Clear_BI(B_root);
}

void Utils::insertAVL(ofstream& outputFile){
    AVLTree At;
    AVLTree *A_root=nullptr;
    for(auto const &pair: Heap){
        At.insertTree(&A_root, pair);
    }
    outputFile<<"-----------ÁRVORE AVL-----------"<<endl;
    outputFile<<"=============IN======================="<<endl;
    At.central(A_root,outputFile);
    outputFile<<"==============POS========================="<<endl;
    At.posordem(A_root,outputFile);
    outputFile<<"===============PRE========================"<<endl;
    At.preordem(A_root,outputFile);
    outputFile<<"========================================="<<endl;
    At.Clear_AVL(A_root);
}

void Utils::insertHuffman(ofstream& outputFile){
    HUFFMANTree Ht;
    HUFFMANTree *H_root=nullptr;
    Ht.insertH(H_root,Heap);
    outputFile<<"-----------CODIFICAÇÃO HUFFMAN-----------"<<endl;
    outputFile<<"=============IN======================="<<endl;
    Ht.inorder(H_root,outputFile,"");
    outputFile<<"==============POS========================="<<endl;
    Ht.posorder(H_root,outputFile,"");
    outputFile<<"===============PRE========================"<<endl;
    Ht.preorder(H_root,outputFile,"");
    outputFile<<"========================================="<<endl;
    Ht.Clear_HF(H_root);

}