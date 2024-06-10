#include <iostream>

#include "linkedlist.h"

FineGrainedList::FineGrainedList(void) : head(nullptr)
{
   
}

void FineGrainedList::insertIntoMiddle(int value, int pos)
{
    Node* newNode = new Node(value); 

    int currPos = 0;
    
    Node* current = head;
    while ((currPos < (pos - 1)) && (current->next != nullptr))
    {
        current = current->next;        
        currPos++;       
    }
    Node* next = current->next;
    current->next = newNode;
    newNode->next = next;
}

void FineGrainedList::push_back(int value)
{
   Node* node = new Node(value); 
   
   if (head == nullptr)   
   {   
      head = node;   
      return;   
   }

   Node* last = head;  
   while (last->next != nullptr)
   {
      last = last->next;   
   }

   last->next = node;   
   return;   

}

void FineGrainedList::show()
{
    Node* last = head;  
    int i = 0;
    std::cout << "{ ";
    while (last!= nullptr)
    {
       std::cout << last->value << ", ";
       ++i;
       last = last->next;   
    }
    std::cout << "}";
    std::cout << std::endl;
}

void FineGrainedList::remove(int value)
{
    Node *prev, *cur; 

    prev = this-> head;
    cur = this-> head->next;

    while(cur)
    {
        if(cur->value == value)
        {
            prev->next = cur->next;
            delete cur;
            return;
        }

        prev = cur;
        cur = cur->next;
    }
}