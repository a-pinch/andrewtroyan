#pragma once

#include <string>
#include <vector>
#include <fstream>

using namespace std;

typedef struct questionTAG {
	wstring textOfQuestion;
	vector<wstring> answers;
	unsigned int indexOfCorrectAnswer, points;
} question;

int loadQuestions(wifstream&, vector<question>&); //file should be opened yet for this function!!!

