# include <iostream>
# include <string>
# define MAX_NAME_LEN 50
# define MAX_SOLUTION_LEN 1000
# define OPTION_ONE "[1] Legalize Cannabilzation"
# define OPTION_TWO "[2] Eat insects"
# define OPTION_THREE "[3] Volunteer in saving food"
# define OPTION_FOUR "[4] Bill Gates should give all of his money to charity"
# define LINK_ONE "https://stips.co.il/ask/12114879/%D7%9E%D7%94-%D7%9C%D7%93%D7%A2%D7%AA%D7%9B%D7%9D-%D7%A6%D7%A8%D7%99%D7%9A-%D7%9C%D7%A2%D7%A9%D7%95%D7%AA-%D7%A2%D7%9D-%D7%94%D7%A8%D7%A2%D7%91-%D7%94%D7%A2%D7%95%D7%9C%D7%9E%D7%99"
# define LINK_TWO "https://stips.co.il/ask/8494252/%D7%9E%D7%94-%D7%94%D7%A4%D7%AA%D7%A8%D7%95%D7%9F-%D7%9C%D7%A8%D7%A2%D7%91-%D7%94%D7%A2%D7%95%D7%9C%D7%9E%D7%99-%D7%9C%D7%93%D7%A2%D7%AA%D7%9B%D7%9D"
# define LINK_THREE "https://stips.co.il/ask/10460670/%D7%9E%D7%94-%D7%90%D7%AA%D7%9D-%D7%97%D7%95%D7%A9%D7%91%D7%99%D7%9D-%D7%A9%D7%90%D7%A4%D7%A9%D7%A8-%D7%9C%D7%A2%D7%A9%D7%95%D7%AA-%D7%9B%D7%93%D7%99"
# define LINK_FOUR "https://stips.co.il/ask/10692234/%D7%9C%D7%93%D7%A2%D7%AA%D7%9B%D7%9D-%D7%91%D7%99%D7%9C-%D7%92%D7%99%D7%99%D7%98%D7%A1-%D7%A6%D7%A8%D7%99%D7%9A-%D7%9C%D7%AA%D7%A8%D7%95%D7%9D-%D7%90%D7%AA"

/*
Name: nmwh.pp (no more world hunger)
Written by: Ori P
Date: 14/3/23

This code solves world hunger using the wisdom of the brilliant people in Stips.
*/

using namespace std;

class Problem{
 	
	public:
	
	// Sets the name of the problem
	void setName(string str){
		name = str;
	}
	
	// Sets the solution of the problem
	void setSolution(string str){
		solution = str;
	}
	
	// Returns the name of the problem
	string getName(){
		return name;
	}
	
	// Returns the solution for te problem
	string getSolution(){
		return solution;
	}
	
	// Returns if the problem has been solved
	bool beenSolved(){
		return solved;
	}
	
	// Takes the current solution and if it's a good one, solves the problem.
	void solve(){
		if(solution == OPTION_THREE){
			solved = true;
			cout << "That's a great idea!\n\n";
		}
		else{
			cout << " What? You seriously thought that's gonna solve world hunger??\n\n";
		}
	}
	
	protected:
	string name;
	string solution;
	bool solved = false;
};

int main(){ 
	Problem wh;
	cout << " Are there hungry children in Africa? [y/n]\n";
	char answer;
	cin >> answer;
	
	// Making the user realize that world hunger is a serius problem.
	while(answer != 'y'){
		cout << " Liar\n\n Are there hungry children in Africa? [y/n]\n";
		cin >> answer;
	}
	wh.setName("World Hunger");
	cout << " Correct! World Hunger is a major problem!\n Let's Solve it!\n\n";
	cout << " I have done the hard part and searched the residence of the most brilliant minds in Israel \
	(and probably the whole world) - Stips, for a solution.\n Here are the options:\n\n";
	
	// Looping until user has solved the world hunger problem. 
	while(wh.beenSolved() == false){
		cout << OPTION_ONE << "\n" << OPTION_TWO << "\n" << OPTION_THREE << "\n"<< OPTION_FOUR << "\n\n";
		cout << " How are we gonna solve world hunger?\n";
		cin >> answer;
		
		// Preform differently according to inputed answer.
		switch(answer){
			case '1':
				wh.setSolution(OPTION_ONE);
				cout << " That's a very popular idea that may be the solution to world hunger...\n";
				cout << " HOWEVER, as disscussed in the excellent TV show \"It's Always Sunny In Philadelphia\n"; 
				cout << "eating human flesh makes you develope an insatiable hunger that never";
				cout << " stops and you will still be hungry.\n To Read more about that visit\n\n";
				cout << LINK_ONE << "\n\n";
				break;
				
			case '2':
				wh.setSolution(OPTION_TWO);
				cout << " That COULD solve world hunger...\n";
				cout << " HOWEVER, some of the insects are really gross and not everyone will agree to consume them.";
				cout << " In addition, insects are an important part of our eco systems so bad things will happen if we eat them all.\n";
				cout << " To read more about that visit\n\n";
				cout << LINK_TWO << "\n\n";
				break;
				
			case '3':
				wh.setSolution(OPTION_THREE);
				cout << " That is a very nice and noble thing to do and could probably end world hunger.\n";
				cout << " It may not solve the problem entirly but it's a good place to start from.\n";
				cout << " To read more about that visit\n\n";
				cout << LINK_THREE << "\n\n";
				break;
				
			case '4':
				wh.setSolution(OPTION_FOUR);
				cout << " It has been proven that even half of his money could solve the problem...\n";
				cout << " HOWEVER, he ain't owe nothing to nobody and that's his money, he worked hard for the money.";
				cout << " In addintion, he has founded an charity that encoureges \n rich people to donate lots of money after they die.\n";
				cout << " To read more about that visit\n\n";
				cout << LINK_FOUR << "\n\n";
				break;
			
			// Illegal option has been inputed.
			default:
				cout << "That's not a valid option... (Enter the option's number)\n";
				break;
		}
		
		// Informing the user about the problem's state.
		wh.solve();
		string solved;
		wh.beenSolved() ? solved = "YES!" : solved = "No...";
		cout << "World Hunger has been solved? " << solved << "\n\n";
	}
	
	return 0;
}
