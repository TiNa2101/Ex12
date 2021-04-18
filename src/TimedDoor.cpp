// Copyright 2021 Ex12 TiNa
#include "TimedDoor.h"
#include <iostream>
#include <string>
#include <ctime>

void DoorTimerAdapter::Timeout() { door.DoorTimeOut(); }

bool TimedDoor::isDoorOpened() { return opened; }

void TimedDoor::unlock() {
  opened = true;
  Timer cnt;
  cnt.tregister(iTimeout, adapter);
}

void TimedDoor::lock() { opened = false; }

void TimedDoor::DoorTimeOut() { throw std::string("Close the door please!"); }

void TimedDoor::throwState() {
  if (opened) {
    throw std::string("The door is opened!");
  } else {
    throw std::string("The door is closed!");
  }
}

void Timer::sleep(int timeIn) {
  time_t tm = clock();
  while (clock() < timeIn + tm / CLOCKS_PER_SEC) {}
}

void Timer::tregister(int timeIn, TimerClient* clientIn) {
  client = clientIn;
  sleep(timeIn);
}
