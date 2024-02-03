#ifndef _SHUFFLE_H_
#define _SHUFFLE_H_

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void Shuffle(vector<T> &deck){
  srand((unsigned long)time(nullptr));

  T temp;
  T *temp2 = (T *)malloc(sizeof(T));

  for(int i = 0; i < deck.size(); i++){
    temp = deck[i];
    temp2 = &deck[rand() % deck.size()];

    deck[i] = *temp2;
    *temp2 = temp;
  }

  return;
}

#endif
