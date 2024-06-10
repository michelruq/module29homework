#include <iostream>
#include "linkedlist/linkedlist.h"

FineGrainedList oFineGrainedList;

int arrayTestPush_Back[] = {0, 2, 1, 4, 3, 6, 5, 8, 7, 9};
int arrayTestRemove[] = { 6, 2, 5, 9, 4, 7, 3, 0, 1, 8, 10};

int main (int argc, char* argv[])
{
    for (int i = 0; i < sizeof(arrayTestPush_Back)/sizeof(int); ++i)
	{
		oFineGrainedList.push_back(arrayTestPush_Back[i]);
	}

	oFineGrainedList.insertIntoMiddle(10, 3);
	oFineGrainedList.show();
	
	for (int i = 0; i < sizeof(arrayTestRemove)/sizeof(int); ++i)
	{
	   oFineGrainedList.remove(arrayTestRemove[i]);
	   oFineGrainedList.show();
	   std::cout << std::endl;
	}
	return 0;
}