#ifndef _TIMER_H_
#define _TIMER_H_

class Timer{
public:
  void StartTimer();
  double StopTimer();
  double GetTime();
private:
  double nowTime;
  bool DoNotRunTimer;
};

#endif
