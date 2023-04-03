#pragma once
#include <Windows.h>

class Semaphore 
{
private:
	HANDLE m_Handle;
public:
	Semaphore() {
		m_Handle = CreateEvent(
			NULL,               // default security attributes
			FALSE,               // manual-reset event
			FALSE,              // initial state is nonsignaled
			TEXT("WriteEvent")  // object name
		);
	}

	~Semaphore() {
		CloseHandle(m_Handle);
	}

	void Signal() {
		SetEvent(m_Handle);
	}

	void Wait() {
		WaitForSingleObject(m_Handle, INFINITE);
	}
};