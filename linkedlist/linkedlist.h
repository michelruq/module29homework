#pragma once

struct Node
{
  Node(int data) : value(data), next(nullptr) {} 
  int value;
  Node* next;
};

class FineGrainedList
{
  Node* head;

  public: 
      FineGrainedList(void);
      void insertIntoMiddle(int value, int pos);
      void push_back(int value);
      void remove(int value);
      void show();
};