#include "Player.h"
#include "SlotMachine.h"
#include "Drum.h"
#include <iostream>
#include <Windows.h>
int main(){

	Drum Gosha(30);
	Player Ignat(100);
	SlotMachine M(1000);

	for (int i = 0; i < 10; i++){
		// ������ ������,��������� ����
		Ignat.play(M, 10);
		// ����� ���������� ����
		//M.result(Ignat);
		std::cout << Ignat.toString() << "\n"
			<< M.toString() << std::endl;

	}
	system("pause");
	return 0;
}