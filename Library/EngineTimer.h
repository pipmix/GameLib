#pragma once
#include <windows.h>


class EngineTimer {
	public:
		EngineTimer();


		void Init();
		void Update();
		float GetDelta();
	private:
		INT64 m_frequency, m_startTime;
		float m_ticksPerMs, m_frameTime;



};