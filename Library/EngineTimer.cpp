#include "EngineTimer.h"


EngineTimer::EngineTimer() {

	QueryPerformanceFrequency((LARGE_INTEGER*)&m_frequency);
	m_ticksPerMs = (float)(m_frequency / 1000);
	QueryPerformanceCounter((LARGE_INTEGER*)&m_startTime);
}



void EngineTimer::Update() {
	INT64 currentTime;
	float timeDifference;
	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
	timeDifference = (float)(currentTime - m_startTime);
	m_frameTime = timeDifference / m_ticksPerMs;
	m_startTime = currentTime;
}


float EngineTimer::GetDelta() {

	return m_frameTime; 
}