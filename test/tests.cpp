// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include <string>
#include <ctime>
#include "TimedDoor.h"

TEST(set1, test1) {
  TimedDoor tDoor(5);
  try {
    tDoor.lock();
    tDoor.throwState();
  }
  catch(std::string message) {
    EXPECT_EQ(message, "the door is closed!");
  }
}

TEST(set1, test2) {
  TimedDoor tDoor(5);
  try {
    tDoor.unlock();
    tDoor.throwState();
  }
  catch(std::string message) {
    EXPECT_NE(message, "the door is opened!");
  }
}

TEST(set1, test3) {
  TimedDoor tDoor(5);
  try {
    tDoor.unlock();
  }
  catch(std::string message) {
<<<<<<< HEAD
    EXPECT_EQ(message, "close the door!");
=======
    EXPECT_EQ(message, "Close the door please!");
>>>>>>> 670b072efa3d56cc81f0ed6ed2ad914c215dc8fc
  }
}

TEST(set1, test4) {
  TimedDoor tDoor(5);
  time_t start = time(nullptr);
  time_t finish;
  try {
    tDoor.unlock();
  }
  catch(std::string message) {
    finish = time(nullptr);
    int delta = finish - start;
    EXPECT_EQ(delta, 5);
  }
}
