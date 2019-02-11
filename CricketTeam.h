#include<iostream>
using namespace std;

class Cricket_team{
string * membernames;
int no_of_members;
char *teamName;
int Scoreinlast10matches[10];
int Rank;
string captain;

public:
	string getCaptain();
	int getRank();
	string getTeamName();
	int getNoOfMembers();
	void setCaptain(string cap);
	void setRank(int rank);
	void setNoOfMembers(int members);
	void setTeamName(string name);
	Cricket_team();
	Cricket_team(string name,int no_of_members);
	Cricket_team(string filename);
};