// l181158_lab4.cpp : Defines the entry point for the console application.
//

#include"CricketTeam.h"
#include<string>
#include<iostream>
using namespace std;

int main()
{
	string filename="team.txt";
	Cricket_team team(filename.c_str());
	return 0;
}

