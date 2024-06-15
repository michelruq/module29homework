#include <iostream>
#include <array>
#include "linkedlist/linkedlist.h"
#include <thread>

FineGrainedList oFineGrainedList;

std::array<int, 10> arrayForRemoving = { 6, 2, 5, 9, 4, 7, 3, 1, 8, 15};
std::array<int, 10> arrayTestPush_Back = { 0, 2, 1, 4, 3, 6, 5, 8, 7, 9};

typedef struct pair
{
   int value;
   int position;
}Pair;

using arrayPair = std::array<Pair, 3>;

arrayPair arrayForPutting = {{ {11, 3}, {12, 7}, {13, 9} }};
arrayPair arrayForPutting1 = {{ {14, 3}, {15, 7}, {16, 9} }};
arrayPair arrayForPutting2 = {{ {17, 3}, {18, 7}, {19, 9} }};
arrayPair arrayForPutting3 = {{ {20, 3}, {21, 7}, {22, 9} }};
arrayPair arrayForPutting4 = {{ {23, 3}, {24, 7}, {25, 9} }};
arrayPair arrayForPutting5 = {{ {26, 3}, {27, 7}, {28, 100} }};

template < typename T, typename T1>
class Task
{
   T& outgoingArray;
   T1& linkedList;
   public:
      Task(T& incomingArray, T1& incomingLinkedList) : outgoingArray(incomingArray), linkedList(incomingLinkedList){}
      void operator() ()
	  {
		 for (const auto& it : outgoingArray)
		 {
              linkedList.insertIntoMiddle(it.value, it.position);
		 }
	  }
};

template < typename T, typename T1>
class Task1
{
    T& outgoingArray;
	T1& linkedList;
   public:
      Task1(T& incomingArray, T1& incomingLinkedList) : outgoingArray(incomingArray), linkedList(incomingLinkedList){}
      void operator() ()
	  {
		 for (const auto& it : outgoingArray)
		 {
              linkedList.remove(it);
			  linkedList.show();
		 }
	  }
};

int main (int argc, char* argv[])
{
    for (const auto& it : arrayTestPush_Back)
	{
		oFineGrainedList.push_back(it);
	}

	Task<arrayPair, FineGrainedList> task(arrayForPutting, oFineGrainedList);
	Task<arrayPair, FineGrainedList> task1(arrayForPutting1, oFineGrainedList);
	Task<arrayPair, FineGrainedList> task2(arrayForPutting2, oFineGrainedList);
	Task<arrayPair, FineGrainedList> task3(arrayForPutting3, oFineGrainedList);
	Task<arrayPair, FineGrainedList> task4(arrayForPutting4, oFineGrainedList);
	Task<arrayPair, FineGrainedList> task5(arrayForPutting5, oFineGrainedList);
	Task1<std::array<int, 10>, FineGrainedList> task6(arrayForRemoving, oFineGrainedList);
	
    std::thread t(task);
	std::thread t6(task6);
	std::thread t1(task1);
	std::thread t2(task2);
	std::thread t3(task3);
	std::thread t4(task4);
	std::thread t5(task5);

	t.join();
	t6.join();
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();

	return 0;
}