#include <iostream>

#include "linkedlist.h"

FineGrainedList::FineGrainedList(void) : head(nullptr)
{
   
}

void FineGrainedList::insertIntoMiddle(int value, int pos)
{
    Node* newNode = new Node(value); 

    int currPos = 0;
    
    queue_mutex.lock();
    Node* current = head;
    
    while ((currPos < (pos - 1)) && (current->next != nullptr))
    {
        current = current->next;        
        currPos++;       
    }
    Node* next = current->next;

    current->node_mutex.lock(); // it doesn't matter because queue is blocked
    newNode->node_mutex.lock(); // it doesn't matter because queue is blocked
    current->next = newNode;
    newNode->next = next;
    queue_mutex.unlock();
    current->node_mutex.unlock();
    newNode->node_mutex.unlock();
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

    queue_mutex.lock();
    prev = this-> head;
    cur = this-> head->next;

    prev->node_mutex.lock(); 
    queue_mutex.unlock();

    cur->node_mutex.lock();

    while(cur)
    {
        if(cur->value == value)
        {
            prev->next = cur->next;
            prev->node_mutex.unlock();
            cur->node_mutex.unlock();
            delete cur;
            return;
        }
        
        Node* old_prev = prev;
        prev = cur;
        cur = cur->next;

        old_prev->node_mutex.unlock(); 
        cur->node_mutex.lock();
    }
    prev->node_mutex.unlock();
}