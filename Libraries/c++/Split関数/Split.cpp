#include <iostream>
#include <vector>
#include "Split.h"

using namespace std;

void Split(const string &str, vector<string> &strArray, char splitChar){

  string word;

  for(int i = 0; i < str.length(); i++){

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

  return;
}
