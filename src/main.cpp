#include "Functions.hpp"

int main(){
int num;
Utils u;
setlocale(LC_ALL, "pt_BR.UTF-8");
locale loc(locale(), new codecvt_utf8<wchar_t>);
u.init_Stopwords(loc);
u.init_Words(loc);
wstring word;


cout<<"DIGITE A QUANTIDADE DE ARQUIVOS: " <<endl; cin >> num;
ofstream File("output.txt", ios::trunc | ios::out);

for(int i=1;i<=num;i++){
string arquivo = "./dataset/input"+to_string(i)+".data";
wchar_t* txt = u.getText(loc, arquivo), *ch = txt;
    while(*ch){
        switch(*ch){
            case L' ':  case L'!': case L'?': case L'.': 
            case L'\n': case L',': case L'(': case L')': 
            case L';':  case L'/': case L':': case L'—': 
            case L'"':  case L'\'':
            if(!word.empty()){
                u.ADD_Main_Hash(word);
                word.clear();
            }
            break;
            default:
                if(*ch == '-' && word.size() == 0)
                {
                    break;
                }
                word += tolower(*ch);
            break;
        }
        ch++;
    }
    delete[] txt;
    u.init_Heap();
    File<<"\n==================================="<<endl;
    File<<"\nTEXTO "<<i<<endl;
    u.Check_Words(File);
    u.Clear_Text_Data();
}
File.close();
return 0;
}
