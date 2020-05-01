/*
At a time, try only one example
How ?
Uncomment 2 lines.
1. Header file having the name of your interested example
2. Method call to example written in the header file you uncommented in the above step.
*/
#include"stdafx.h"
#include "ConsoleApplication1.h"
//#include "StandardThreadMutexExample.h" // i. Uncomment for StdThreadExample
//#include "WinMutexExample.h" //ii. Uncomment for WindowsMutexExample
//#include "WinSemaphoreExample.h"
#include "WinEventExample.h"
int main()
{

	//StdThreadExample(); // i. Uncomment for StdThreadExample
	//WindowsMutexExample(); //ii. Uncomment for WindowsMutexExample
	//WindowsSemaphoreExample();
	WindowsEventsExample();

	system("PAUSE");
	return 0;
}

