# include <iostream>
# include <string>

/*
Name: nmwh.pp (no more world hunger)
Written by: Ori P
Date: 14/3/23

This code solves world hunger using the wisdom of the brilliant people in Stips.
*/

using namespace std;

class Student{
	public:
	void setName(string str){
		name = str;
	}
	void setGrade(string str){
		grade = str;
	}
	int setScore(int s){
		if(s <= 100 && s >= 0){
			score = s;
			return 1;
		}
		else{
			cout << "Student::setScore: Illegal Score\n";
			return 0;
		}
	}
	string getName(){
		return name;
	}
	string getGrade(){
		return grade;
	}
	int getScore(){
		return score;
	}
	
	protected:
	string name;
	string grade;
	int score;
};

class Teacher{
	public:
	void setName(string str){
		name = str;
	}
	void setGrade(string str){
		grade = str;
	}
	int setEvilness(float e){
		if(e <= 10.0 && e >= 0.0){
			evil = e;
			return 1;
		}
		else{
			cout << "Teacher::SetEvilness: Illegal value\n";
			return 0;
		}
	}
	string getName(){
		return name;
	}
	string getGrade(){
		return grade;
	}
	int getEvilness(){
		return evil;
	}
	
	//
	int finalScore(Student sdt){
		int score;
		srand((unsigned) time(NULL));
		score = (rand() % 100) - evil;
		if(score < 0){
			score = 0;
		}
		sdt.setScore(score);
		return score;
	}
	
	protected:
	string name;
	string grade;
	float evil;
};

int main(){
	Student sdt;
	Teacher tcr;
	string str;
	int score;
	float evil;
	
	// Setting student info
	cout << "what is your name?\n";
	getline(cin, str);
	sdt.setName(str);
	cout << "what is your grade?\n";
	cin >> str;
	sdt.setGrade(str);

	// Setting teacher info.
	cout << "what is your physics teacher's name?\n";
	cin.ignore();
	getline(cin, str);
	tcr.setName(str);
	cout << "Which Grade does your physics teacher teach?\n";
	cin >> str;
	tcr.setGrade(str);
	cout << "How much evil is your physics teacher?\n";
	cin >> evil;
	tcr.setEvilness(evil);
	
	// Printing finale grade
	cout << "\nOkay " << sdt.getName() << ", ";
	cout << tcr.getName() << " gave you " << tcr.finalScore(sdt) << " as your finale Score in physics.\n";
	return 0;
}