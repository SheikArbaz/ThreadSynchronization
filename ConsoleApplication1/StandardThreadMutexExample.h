#pragma once
#include <thread>
#include <mutex>
#include <Windows.h>
#include <iostream>

extern std::mutex mtx;

void print_block(int n, char c);
DWORD WINAPI Add(DWORD a, DWORD b);
void StdThreadExample();