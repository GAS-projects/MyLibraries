#include <iostream>
#include <vector>
#include "Split.h"

using namespace std;

void Split(string str, vector<string> *strArray, char splitChar){
  string word;

  str += splitChar; //最後の語句もしっかりと区切るためにつけている。

  for(int i = 0; i <= str.length(); i++){

    if(str[i] == splitChar){

      strArray -> push_back(word);
      word = "";
      continue; //区切り文字をリストの要素中の文字列に入れさせないため、一文字飛ばしている。

    }
    word += str[i];

  }

  return;
}
