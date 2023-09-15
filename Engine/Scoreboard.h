#pragma once
#include <stdlib.h>
#include <conio.h>
#include <cstring>

#define _CRT_SECURE_NO_WARNINGS


using namespace std;

class Scoreboard
{
	
private:
	class Score
	{
	public:
		Score(int score, const char* time);
		~Score() { free(time); };
		Score* GetNextScore();
		Score* GetPrevScore();
		bool InsertScore(Score* inScore);
		void PrintScoreboard();
		//void Serialize(FILE* file);
	private:
		int score;
		char* time;
		Score* NextScore;
		Score* PrevScore;
	};


public:
	Scoreboard() {};
	~Scoreboard() {};
	void AddScore(int score, const char* time);
	Score* firstScore = nullptr;
	void PrintScoreboard();
};

