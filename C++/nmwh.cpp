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
using namespace std;

class Problem{
	
	public:
	void setName(string str){
		name = str;
	}
	void setSolution(string str){
		solution = str;
	}
	string getName(){
		return name;
	}
	string getSolution(){
		return solution;
	}
	bool beenSolved(){
		return solved;
	}
	
	void solve(char idea){
		if(idea == '3' or idea == '5'){
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
	wh.setName("World Hunger");
	string solution;
	
	cout << " Are there hungry children in Africa? [y/n]\n";
	char answer;
	cin >> answer;
	while(answer != 'y'){
		cout << " Liar\n\n Are there hungry children in Africa? [y/n]\n";
		cin >> answer;
	}
	
	cout << " Correct! World Hunger is a major problem!\n Let's Solve it!\n\n";
	cout << " I have done the hard part and searched the residence of the most brilliant minds in Israel\
 (and probably the whole world) - Stips, for a solution.\n Here are the options:\n\n";
	
	//
	while(wh.beenSolved() == false){
		cout << OPTION_ONE << "\n" << OPTION_TWO << "\n" << OPTION_THREE << "\n"<< OPTION_FOUR << "\n\n";
		cout << " How are we gonna solve world hunger?\n";
		cin >> answer;
		wh.solve(answer);
		
		switch(answer){
			case '1':
				cout << " That's a very popular idea that may be the solution to world hunger...\n";
				cout << " HOWEVER, as disscussed in the excellent TV show \"It's Always Sunny In Philadelphia\n"; 
				cout << "eating human flesh makes you develope an insatiable hunger that never";
				cout << " stops and you will still be hungry.\n To Read more about that visit\n";
				cout << LINK_ONE << "\n\n";
				break;
				
			case '2':
				cout << " That COULD solve world hunger...\n";
				cout << " HOWEVER, some of the insects are really gross and not everyone will agree to consume them.";
				cout << " In addition, insects are an important part of our eco systems so bad things will happen if we eat them all.\n";
				cout << " To read more about that visit\n";
				cout << LINK_TWO << "\n\n";
				break;
				
			case '3':
				cout << " That is a very nice and noble thing to do and could probably end world hunger.\n";
				cout << " It may not solve the problem entirly but it's a good place to start from.\n";
				cout << " To read more about that visit\n";
				cout << LINK_THREE << "\n\n";
				break;
				
			case '4':
				cout << " It has been proven that even half of his money could solve the problem...\n";
				cout << " HOWEVER, he ain't owe nothing to nobody and that's his money, he worked hard for the money.";
				cout << " In addintion, he has founded an charity that encoureges \n rich people to donate lots of money after they die.\n";
				cout << " To read more about that visit\n";
				cout << LINK_FOUR << "\n\n";
				break;
			case '5':
				break;
			default:
				cout << "That's not a valid option... (Enter the option's number)\n";
				break;
		}
		string solved;
		wh.beenSolved() ? solved = "YES!" : solved = "No...";
		cout << "World Hunger has been solved? " << solved << "\n\n";
	}
	
	return 0;
}
