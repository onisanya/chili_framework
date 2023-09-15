#include "Scoreboard.h"



Scoreboard::Score::Score(int score, const char* time)
{
	this->score = score;
	/*
	if (time)
	{*/
		this->time = (char*)malloc(strlen(time) + 1); // deprecated
		//strcpy(this->time, time); // deprecated
		strcpy_s(this->time, strlen(time) + 1, time);
	//}
	//else time = "ERR";
	this->NextScore = nullptr;
	this->PrevScore = nullptr;
}

Scoreboard::Score* Scoreboard::Score::GetNextScore()
{
	return this->NextScore;
}

Scoreboard::Score* Scoreboard::Score::GetPrevScore()
{
	return this->PrevScore;
}

bool Scoreboard::Score::InsertScore(Score* inScore)
{
	if (inScore->score > this->score)
	{
		inScore->NextScore = this;
		return true;
	}
	else
	{
		if (this->NextScore != nullptr)
		{
			this->NextScore->InsertScore(inScore);
			//return false;
		}
		else
		{
			this->NextScore = inScore;
			
		}
	}
	return false;
}

void Scoreboard::Score::PrintScoreboard()
{
	_cprintf("%d%s\n", this->score, this->time);
	if (this->NextScore != nullptr)
	{
		this->NextScore->PrintScoreboard();
	}
}

/*
void Scoreboard::Score::Serialize(FILE* file)
{
}
*/

void Scoreboard::AddScore(int score, const char* time)
{
	Scoreboard::Score* inScore = new Score(score, time);
	
	
	if (firstScore == nullptr)
	{
		firstScore = inScore;
		return;
	}
	if (firstScore->InsertScore(inScore)) 
	{
		firstScore = inScore;
	};
}

void Scoreboard::PrintScoreboard()
{
	firstScore->PrintScoreboard();
}
