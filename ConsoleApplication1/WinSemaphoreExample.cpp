#include "stdafx.h"
#include "WinSemaphoreExample.h"

HANDLE hSemaphore;
DWORD WINAPI  ThreadFun(LPVOID lpParam)
{
	DWORD dwWaitResult;
	BOOL bCondtion = TRUE;
	/*When bCondtion = TRUE then 5 Threads run parallel
	and the remaining Threads will be wait. Once the 5 threads
	entered in Critical Section then bCondtion = FALSE.
	loop will terminates and again...  the remaining Threads will enter
	in Critical Section*/
	while (bCondtion)
	{
		/*It Decrease the Semaphore Value to 1.
		if This Function return WAIT_OBJECT_0 then
		It will print the ThreadID of currently executing Threads.*/
		dwWaitResult = WaitForSingleObject(hSemaphore, INFINITE);
		switch (dwWaitResult)
		{
		case WAIT_OBJECT_0:
			std::cout << "\nThreadID - " << GetCurrentThreadId() << std::endl;
			bCondtion = FALSE;
			Sleep(5000);
			//It increases the Semaphore Value
			ReleaseSemaphore(hSemaphore, 1, 0);
			break;
		case WAIT_TIMEOUT:
			/*If WAIT_TIMEOUT occurs i.e That Thread will not enter
			in Critical Sections*/
			std::cout << "\n Wait Time Out" << std::endl;
			std::cout << "\n ThreadID - " << GetCurrentThreadId() << std::endl;
			break;
		default:
			break;
		}//switch
	}//while
	return 0;
}

void WindowsSemaphoreExample()
{
	//Local Variable
	HANDLE hThread[8];//Arrays of Threads
	DWORD ThreadID;
	//STEP-1 Create Counting Semaphore
	hSemaphore = CreateSemaphore(
		NULL,//Seucrity Attribute
		5, //Initial Count->5
		5,//Max Count
		NULL);//Semaphore Name
	if (NULL == hSemaphore)
	{
		std::cout << "Semaphore Creation Failed" << std::endl;
		std::cout << "Error No - " << GetLastError() << std::endl;
		return;
	}
	std::cout << "Semaphore Creation Success" << std::endl;

	//STEP-2 Create 8 Threads
	for (size_t i = 0; i < 8; i++)
	{
		hThread[i] = CreateThread(
			NULL,//Security Attributes
			0,//Default Stack Size
			&ThreadFun,//Thread Start Address
			NULL,//Parameters
			0,//Creation Flag
			&ThreadID);//Updates this variable with a new threadId
	}

	//STEP-3 Wait for All threads to Terminate
	WaitForMultipleObjects(8, hThread, TRUE, INFINITE);

	//STEP-4 Close Handle for Thread
	for (size_t i = 0; i < 8; i++)
	{
		CloseHandle(hThread[i]);
	}

	//STEP-5 Close Handle for Semaphore
	CloseHandle(hSemaphore);
}
