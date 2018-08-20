#pragma once

class Process {
public :
	int PID; 
	int duration_time;
	int priority;
	Process(int pid, int time, int p) {
		PID = pid;
		duration_time = time;
		priority = p;
	}

	void setLastTime(int time) {
		lastTime = time;
	}

	int getLastTime() {
		return lastTime;
	}

	int runningTime(int time) {
		return duration_time > time ? time : duration_time;
	}

	bool runOut(int time) {
		duration_time -= time;
		return duration_time <= 0;
	}
private:
	int lastTime;
};