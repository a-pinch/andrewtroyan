#pragma once

#include <Windows.h>
#include <list>
#include <string>

struct queue_entity {
	wstring from, to;
	int progress;
	queue_entity(wstring from_, wstring to_) : from(from_), to(to_), progress(0) {};
};

class Copier {
private:
	std::list <queue_entity> queue;
	HANDLE threadOfCopying;
public:
	Copier();
	~Copier();

	bool addToQueue(wstring from, wstring to);
	int checkStatusOfCurrentCopying();
};