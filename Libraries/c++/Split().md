# 初めに
このc++ライブラリは、特定の文字列を指定した文字で区切り、それをリスト(vector)に入れるというものです。

たとえば、`"Hello, my name is Kenta."`の文字列を`' '`で区切ると、

- `"Hello,"`
- `"my"`
- `"name"`
- `"is"`
- `"Kenta."`

で分けることができるのです。 ざっとサンプルコードを載せておきます。

・ヘッダファイル(Split.h)

```
#ifndef _SPLIT_H_
#define _SPLIT_H_

#include <iostream>
#include <vector>

using namespace std;

void Split(string str, vector<string> *strArray, char splitChar);

#endif
```

・ソースファイル(Split.cpp)

```
#include <iostream>
#include <vector>
#include "Split.h"

using namespace std;

void Split(string str, vector<string> *strArray, char splitChar){
  string word;

  str += splitChar; //最後の語句もしっかりと区切るために着けている。

  for(int i = 0; i <= str.length(); i++){

    if(str[i] == splitChar){

      strArray -> push_back(word);
      word = "";
      continue; //区切り文字をリストの要素に入れさせないため、一文字飛ばしている。

    }
    word += str[i];

  }

  return;
}
```

こんな感じになっています。ファイルをインポートしてSplit.hをインクルードすれば、ライブラリが使えると思います。

文字列を区切るためにSplit()を使います。 そのサンプルコードを添付します。

・main.cpp

```
#include <iostream>
#include <vector>
#include "Split.h"

using namespace std;

int main() {
  string str = "Hello, that is the real person. That's so cool and beautiful!";
  vector<string> strArray;

  Split(str, &strArray, ' ');

  for(int i = 0; i < strArray.size(); i++) cout << strArray[i] << endl;

  return 0;
}
```

以上のコードを実行すると、出力は、

```
Hello,
that
is
the
real
person.
That's
so
cool
and
beautiful!
```

となります。strArrayリストに、区切られた文字列たちが格納されて、それが出力されています。

では、Split()の詳しい使い方を説明します。

まず、Split()には三つの引数があります。

-第一引数(std::string str)・・・区切られるの文字列を格納。

-第二引数(vector<std::string> *strArray)・・・区切られた文字列が格納されるリストのアドレス。ここに区切られた文字列が入る。

-第三引数(char splitChar)・・・区切る文字。
