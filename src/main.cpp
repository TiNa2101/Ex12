// Copyright 2021 Ex12 TiNa
#include "TimedDoor.h"
#include <iostream>
#include <string>

int main() {
  TimedDoor tDoor(5);
  tDoor.lock();
  tDoor.unlock();

  return 0;
}
