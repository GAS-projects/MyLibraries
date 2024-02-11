#include <iostream>
#include <vector>
#include "Split.h"

using namespace std;

void Split(const string &str, vector<string> &strArray, char splitChar){

  string word;

  for(int i = 0; i <= str.length(); i++){

    if(str[i] == splitChar || i == str.length()){

      if(word != "") strArray.push_back(word);
      word = "";
      continue; //区切り文字をリストの要素中の文字列に入れさせないため、一文字飛ばしている。

    }
    else word += str[i];

  }

  return;
}
