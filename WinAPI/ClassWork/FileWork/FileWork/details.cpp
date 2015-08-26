#include "details.h"
#include <fstream>

using namespace std;

bool thread_exit;
const int buf_size = 0x10000; //4 kb

DWORD WINAPI copying(LPVOID);

Copier::Copier() {
	thread_exit = false;
	threadOfCopying = CreateThread(NULL, 0, &copying, (LPVOID)&queue, 0, NULL);
}

Copier::~Copier() {
	thread_exit = true;
	ResumeThread(threadOfCopying);
}

bool Copier::addToQueue(wstring from, wstring to) {
	queue.push_back(queue_entity(from, to));
	Sleep(1);
	ResumeThread(threadOfCopying);
	return true;
}

int Copier::checkStatusOfCurrentCopying() {
	if (queue.size())
		return queue.begin()->progress;
	return 0;
}

DWORD WINAPI copying(LPVOID lp) {
	auto queue = (std::list<queue_entity>*)lp;

	while (!exit) {
		SuspendThread(GetCurrentThread());

		while (queue->size())
		{
			std::ifstream file_from(queue->begin()->from, std::ifstream::ios_base::binary);
			std::ofstream file_to(queue->begin()->to, std::ofstream::ios_base::binary);

			char* buf = new char[buf_size];
			int all_read_bytes = 0, current_read_bytes;

			file_from.seekg(0, file_from.end);
			int file_size = file_from.tellg();
			file_from.seekg(0, file_from.beg);

			while (all_read_bytes < file_size)
			{
				file_from.read(buf, buf_size);

				current_read_bytes = file_from.gcount();
				all_read_bytes += current_read_bytes;

				file_to.write(buf, current_read_bytes);

				queue->begin()->progress = all_read_bytes * 100 / file_size;
			}

			queue->pop_front();
			file_from.close();
			file_to.close();
		}
	}
}