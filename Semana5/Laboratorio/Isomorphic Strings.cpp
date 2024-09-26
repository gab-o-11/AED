#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }
    map<char,char> ms;
    map<char,char> mt;
    for (int i=0;i<s.size();i++){
        if(ms.find(s[i])!=ms.end()){
            if(ms[s[i]]!=t[i]){
                return false;
            }
        }
        else ms[s[i]]=t[i];
        if(mt.find(t[i])!=mt.end()){
            if(mt[t[i]]!=s[i]){
                return false;
            }
        }
        else mt[t[i]]=s[i];
    }
    return true;

}

int main() {
    string s="bar";
    string t="foo";
    isIsomorphic(s,t);
}