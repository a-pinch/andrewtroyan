#include "question_info.h"

int loadQuestions(wifstream& file, vector<question>& storage) {
	wstring stringBuffer;
	question questionBuffer;
	unsigned int amountOfAnswers;

	while (!file.eof()) {
		getline(file, stringBuffer);
		amountOfAnswers = wcstol(stringBuffer.c_str(), NULL, 10);

		getline(file, stringBuffer);
		questionBuffer.indexOfCorrectAnswer = wcstol(stringBuffer.c_str(), NULL, 10);

		getline(file, stringBuffer);
		questionBuffer.points = wcstol(stringBuffer.c_str(), NULL, 10);

		getline(file, questionBuffer.textOfQuestion);

		for (unsigned int i = 0; i < amountOfAnswers; ++i) {
			getline(file, stringBuffer);
			questionBuffer.answers.push_back(stringBuffer);
		}

		storage.push_back(questionBuffer);
		questionBuffer.answers.clear();
	}

	return 0;
}
