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
	
	// Set student's name.
	void setName(string str){
		name = str;
	}
	
	// Set student's name.
	void setGrade(string str){
		grade = str;
	}
	
	// Sets student's score.
	int setScore(int s){
		
		// Check if score is legal.
		if(s <= 100 && s >= 0){
			score = s;
			return 1;
		}
		else{
			cout << "Student::setScore: Illegal Score\n";
			return 0;
		}
	}
	
	// Return student's name.
	string getName(){
		return name;
	}
	
	// Return student's grade. 
	string getGrade(){
		return grade;
	}
	
	// Return student's score.
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
	
	// Set teacher name.
	void setName(string str){
		name = str;
	}
	
	// Set which grade teacher is teaching.
	void setGrade(string str){
		grade = str;
	}
	
	// Set Teacher's Evilness level.
	int setEvilness(float e){
		
		// Check if the value is legal.
		if(e <= 10.0 && e >= 0.0){
			evil = e;
			return 1;
		}
		else{
			cout << "Teacher::SetEvilness: Illegal value\n";
			return 0;
		}
	}
	
	// Returns teacher's name.
	string getName(){
		return name;
	}
	
	// Returns teacher's class
	string getGrade(){
		return grade;
	}
	
	// Returns teacher's evilness level.
	int getEvilness(){
		return evil;
	}
	
	// Sets a student's final score in physics and returns it.
	int finalScore(Student sdt){
		int score;
		srand((unsigned) time(NULL));
		score = (rand() % 100) - evil;
		
		// Checks if after the substration the score is illegal (lower than 0).
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
	cout << "What is your physics teacher's evilness level?\n";
	cin >> evil;
	while(tcr.setEvilness(evil) == 0){
		cout << "What is your physics teacher's evilness level?\n";
		cin >> evil;
	}
	
	// Printing finale grade
	cout << "\nOkay " << sdt.getName() << ", ";
	cout << tcr.getName() << " gave you " << tcr.finalScore(sdt) << " as your finale Score in physics.\n";
	return 0;
}