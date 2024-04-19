#include <iostream>
#include <unistd.h>
#include "Timer.h"

void Timer::StartTimer(){
  nowTime = 0;
  DoNotRunTimer = false;
  while(!DoNotRunTimer){
    usleep(10000);
    nowTime += 0.01;
  }
  return;
}

double Timer::StopTimer(){
  DoNotRunTimer = true;
  return nowTime;
}

double Timer::GetTime(){
  return nowTime;
}
