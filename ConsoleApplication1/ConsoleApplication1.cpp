// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include"stdafx.h"
#include "ConsoleApplication1.h"
//#include "WinMutexExample.h" //Uncomment for WindowsMutexExample
//#include "StandardThreadMutexExample.h" // Uncomment for StdThreadExample
#include "WinSemaphoreExample.h"
int main()
{

	//StdThreadExample();
	//WindowsMutexExample();
	WindowsSemaphoreExample();

	system("PAUSE");
	return 0;
}

