#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> mapa;
    int begin=0,current=1,final=0;
    mapa[s[begin]]++;
    while (begin < s.size()) {
        if (current < s.size()) {
            if (s[begin] != s[current] && mapa.find(s[current]) != mapa.end()) {
                mapa[s[current]]++;
                current++;
            }
            else {
                if (final < mapa.size()) final = mapa.size();
                mapa.clear();
                begin++;
                current = begin + 1;
            }
        }
         else {
            break;
        }
    }
    return final;
}

int main() {
    string hola="pwwkew";
    cout<<lengthOfLongestSubstring(hola);

}