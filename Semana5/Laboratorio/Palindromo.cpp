#include <iostream>
#include <unordered_map>

using namespace std;

bool es_palindromo(string palabra) {
    unordered_map<char,int> letras;
    int cont=0;
    for (auto i:palabra) {
        letras[i]++;
    }
    int x=letras.size();
    for (const auto& par:letras) {
        if (x==1) return true;
        if (par.second%2==0) {
            cont++;
        }
    }
    if(cont==x-1||cont==x) {
        return true;
    }
    return false;
}



int main() {
    string palabra;
    cin>>palabra;
    if(es_palindromo(palabra)) {
        cout<<"si"<<endl;
    }
    else cout<<"no"<<endl;
}