#pragma once
#include<iostream>
#include<vector>
#include<queue>
#include"Random.h"
#include"Process.h"
using namespace std;

struct greater {
	bool operator()(Process p1, Process p2) {
		if (p1.priority == p2.priority && p1.priority == 1) return p1.getLastTime() > p2.getLastTime();
		return p1.priority < p2.priority;
	}
};

class Processor {
private:
	priority_queue<Process, vector<Process>, greater> q;
	int cnt;

	void createProcesses(int cnt) {
		Random gen;
		for (int i = 0; i < cnt; i++) {
			Process p(gen.createNum(100), gen.createNum(79, 1), gen.createNum(4,1));
			q.push(p);
		}
	}

public:

	Processor(int cnt) {
		this->cnt = cnt;
		createProcesses(cnt);
	}

	void run() {
		int currTime = 0;
		int totalTime = 0;
		while (!q.empty()) {
			Process curr = q.top();
			cout << "now is " << currTime << " : processing pid = " << curr.PID << " curr priority = " << curr.priority << " still has " << curr.duration_time << endl;
			// check if visted before
			int getP = curr.priority;
			int slice;
			switch (getP)
			{
			case 2:
				slice = 32;
				break;
			case 3:
				slice = 16;
				break;
			case 4:
				slice = 8;
				break;
			default:
				slice = 80;
			}
			// update time
			q.pop();
			currTime += curr.runningTime(slice);
			bool finish = curr.runOut(slice);
			if (finish) {
				cout << "finish : pid = " << curr.PID << " ends at " << currTime << ". it costs " << currTime << endl;
				totalTime += currTime;
			}
			else {
				//update the last time
				curr.setLastTime(currTime);
				// set priority
				curr.priority--;
				// add to the top , do nothing.
				q.push(curr);
			}
		}
		cout << "all processes have fininsh! And the average time is " << totalTime / cnt << endl;
	}
};