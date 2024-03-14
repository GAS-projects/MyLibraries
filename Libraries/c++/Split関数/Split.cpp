#include <iostream>
#include <vector>
#include "Split.h"

using namespace std;

vector<string> Split(const string &str, char splitChar){

  vector<string> strArray;
  string word;

  for(size_t i = 0; i < str.length(); i++){

    if(str[i] != splitChar && i == str.length() - 1){
      word += str[i];
      strArray.push_back(word);
    }
      
    else if(str[i] != splitChar) word += str[i];
      
    else{
      if(word != "") strArray.push_back(word);
      word = "";
    }

  }

  return strArray;
}
