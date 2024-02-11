#ifndef _SPLIT_H_
#define _SPLIT_H_

#include <iostream>
#include <vector>

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

#endif

/*関数のプロトタイプ宣言と定義を行う。*/
