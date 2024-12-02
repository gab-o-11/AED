//
// Created by gab11 on 25/11/2024.
//

#ifndef MATCHSTRING_H
#define MATCHSTRING_H

#include <vector>
#include <string>

using namespace std;


std::vector<int> stringMatch_naive(std::string const& text,
                                   std::string const& pattern);

std::vector<int> stringMatch_RabinKarp(std::string const& text,
                                           std::string const& pattern);

std::vector<int> stringMatch_KnuthMorrisPratt(std::string const& text,
                                                  std::string const& pattern);




#endif //MATCHSTRING_H
