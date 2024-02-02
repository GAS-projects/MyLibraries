# 初めに
このc++ライブラリは、特定の文字列を指定した文字で区切り、それをリスト(vector)に入れるというものです。

たとえば、`"Hello, my name is Kenta."`の文字列を`' '`で区切ると、リストの中身は、

- `"Hello,"`
- `"my"`
- `"name"`
- `"is"`
- `"Kenta."`

となります。文字列を`' '`で分けていることが分かるでしょうか？

文字列を区切る際に、Split()を呼び出します。

# Split()のサンプルコード
・ヘッダファイル(Split.h)

ここで関数のプロトタイプ宣言。

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

ここで定義。

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
# 使い方
文字列を区切るために、以下のステップを踏んでください。

1. ファイルをインポートし、Split.hをインクルードします。
1. `Split()`を呼び出します。

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

では、関数の詳しい使い方を説明します。

まず、`Split()`には三つの引数があります。

- 第一引数(std::string str)・・・区切られる文字列を格納。

- 第二引数(vector<std::string> *strArray)・・・区切られた文字列が格納されるリストのアドレス。ここに区切られた文字列が入る。

- 第三引数(char splitChar)・・・区切る文字。

上記のサンプルコードだと、`str`を`' '`で区切り、`strArray`に、それらを格納するという形になります。

なお、区切る文字(このサンプルコードだと`' '`)は、区切られた文字列には含まれません。

# 最後に
正直、文字列を区切る方法はほかにもたくさんあるので、わざわざ利便性の低いこのライブラリを使う必要はないかなと思います。
