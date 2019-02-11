

#include"CricketTeam.h"
#include<fstream>
#include"string.h"
#include<string>
#include<iostream>
using namespace std;

void Cricket_team::setCaptain(string cap){
	captain=cap;
}
void Cricket_team::setRank(int rank){
	Rank=rank;
}
void Cricket_team::setNoOfMembers(int members){
	no_of_members=members;
}
void Cricket_team::setTeamName(string name){
	//teamName=name;
}
string Cricket_team::getCaptain(){
	return captain;
}
int Cricket_team::getRank(){
	return Rank;
}
string Cricket_team::getTeamName(){
	string name;
	if(teamName==nullptr){
		cout<<"No name assigned!!"<<endl;
	}
	else{
		name=teamName;
		return name;
	}
}
int Cricket_team::getNoOfMembers(){
	return no_of_members;

}
Cricket_team::Cricket_team(){
	membernames=nullptr;
	no_of_members=-1;
	teamName=nullptr;
	for(int i=0;i<10;i++){
		Scoreinlast10matches[i]=-1;
	}
	Rank=-1;
	captain="";
}
Cricket_team::Cricket_team(string name,int members){
	int size=name.length();
	teamName=new char[size+1];
	for(int i=0;i<size;i++){
		teamName[i]=name.c_str()[i];
	}
	teamName[size]='\0';
	no_of_members=members;
	membernames=nullptr;
	for(int i=0;i<10;i++){
		Scoreinlast10matches[i]=-1;
	}
	Rank=-1;
	captain="";
}
Cricket_team::Cricket_team(string filename){
	ifstream fin(filename.c_str());
	if(fin.fail()){
		cout<<"Could not locate file!!"<<endl;
	}
	else{
		string temp;
		int i=0;
		int j=0;	
		while(i<1){
			getline(fin,temp);
			int size = 0;
			for (i = 0; temp[i] != ':'; i++){
			}
			for (j = i + 1; temp[j] != '\0'; j++){
				size++;
			}
			teamName = new char[size + 1];
			for (j = i + 1,i=0; temp[j] != '\0'; j++,i++){
				teamName[i] = temp[j];
				//cout << temp[j];
			}
			teamName[i] = '\0';
			getline(fin, temp);
			size = 0;
			for (i = 0; temp[i] != ':'; i++){
				temp[i] = ' ';
			}
			temp[i] = ' ';
			no_of_members=atoi(temp.c_str());
			membernames = new string[no_of_members];
			for (i = 0; i < no_of_members; i++){
				getline(fin, temp);
				membernames[i] = temp;
			}
			getline(fin, temp);
			for (i = 0; temp[i] != ':'; i++){
				temp[i] = ' ';
			}
			temp[i] = ' ';
			Rank = atoi(temp.c_str());
			getline(fin, temp);
			for (i = 0; temp[i] != ':'; i++){
			}
			for (j = i + 1, i = 0; temp[j] != '\0'; j++, i++){
			}
			getline(fin, temp);
			for ( i = 0; temp[i] != ':'; i++){

			}
			//string score;
			//int a = 0;
			//for (j = i + 1,a=0; temp[j] != '\0'; j++,a++){
			//	string score;
			//	for (i=0; temp[j] != ','; j++,i++){
			//		//score[i] = temp[j];
			//	}
			//	score[i] = '\0';
			//	Scoreinlast10matches[a] = atoi(score.c_str());
			//	cout << Scoreinlast10matches[a];
			//}
			i++;
		}
	}
}


