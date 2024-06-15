#pragma once

#include <mutex>

struct Node
{
  Node(int data) : value(data), next(nullptr) {} 
  int value;
  Node* next;
  std::mutex node_mutex;
};

class FineGrainedList
{
  Node* head;
  std::mutex queue_mutex;

  public: 
      FineGrainedList(void);
      void insertIntoMiddle(int value, int pos);
      void push_back(int value);
      void remove(int value);
      void show();
};