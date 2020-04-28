#include "stdafx.h"
#include "WinMutexExample.h"

HANDLE hMutex = NULL;
//Global variable
int gCount = 1;
DWORD WINAPI ThreadFunEven(LPVOID lpParam)
{
	while (gCount<10)
	{
		//Mutex lock
		WaitForSingleObject(hMutex, INFINITE);
		//Critical Section Code
		if (gCount % 2 == 0)
		{
			std::cout << "Even - " << gCount++ << std::endl;
		}
		//Mutex unlock
		ReleaseMutex(hMutex);
	}//while-loop
	return 0;
}
DWORD WINAPI ThreadFunOdd(LPVOID lpParam)
{
	while (gCount<10)
	{
		//Mutex lock
		WaitForSingleObject(hMutex, INFINITE);
		//Critical Section Code
		if (gCount % 2 == 1)
		{
			std::cout << "odd - " << gCount++ << std::endl;
		}
		//Mutex unlock
		ReleaseMutex(hMutex);
	}//while-loop
	return 0;
}

void WindowsMutexExample(){
	HANDLE hThread1 = NULL;
	HANDLE hThread2 = NULL;

	hMutex = CreateMutex(NULL, FALSE, NULL);

	if (!hMutex) {
		std::cout << "Mutex Creation Error: " << GetLastError() << std::endl;
	}

	hThread1 = CreateThread(
		NULL,          //Security Attribute
		0,             //Default Stack Size
		&ThreadFunEven,//ThreadStart Address
		NULL,          //Parameter
		0,            //Flags
		0);           //ThreadIDPointer

	hThread2 = CreateThread(
		NULL,          
		0,
		&ThreadFunOdd,
		NULL,         
		0,           
		0);

	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);

	CloseHandle(hThread1);
	CloseHandle(hThread2);
	CloseHandle(hMutex);
}
