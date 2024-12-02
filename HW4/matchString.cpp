#include <iostream>
#include "matchString.h"
#include <unordered_map>
#include <functional>

using namespace std;

std::vector<int> stringMatch_naive(std::string const& text,std::string const& pattern){
    int p_size=pattern.size();
    std::vector<int> ret;
    for (int i=0;i<text.size();i++) {
        if (i+p_size>text.size()) break;
        else {
            string sub=text.substr(i,p_size);
            if (sub==pattern) {
                ret.push_back(i);
            }
        }
    }
    return ret;
}

std::vector<int> stringMatch_RabinKarp(std::string const& text,std::string const& pattern){
    // Implemente aqui el algoritmo de Rabin-Karp para resolver el problema
    // de string matching.
    std::vector<int> ret;
    if (pattern.size()>text.size()) return ret;
    int p_size =pattern.size();
    hash<string> hasher;
    size_t pattern_value=hasher(pattern);
    int inicio;

    for (int i=0;i<text.size()-p_size;i++) {
        string window=text.substr(i,p_size);
        size_t window_value=hasher(window);
        if (window_value==pattern_value) ret.push_back(i);
        inicio++;
    }
    return ret;
}

std::vector<int> stringMatch_KnuthMorrisPratt(std::string const& text,
                                              std::string const& pattern)
{
    // Implemente aqui el algoritmo de Knuth-Morris-Pratt para resolver el
    // problema de string matching.

    std::vector<int> ret;
    vector<int> lps;
    int indice=0;
    for (int i = 1; i < pattern.size(); ) {
        if (pattern[i] == pattern[indice]) {
            lps[i++] = indice++;
        } else if (indice > 0) {
            indice = lps[indice - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return ret;
}

