/*
  NUMBER GUESSING GAME - TO DO

  CORE (get these working first)
  [x] Player 1 enters a number
  [x] Validate the number is within 0-100 (while loop)
  [x] Clear the terminal so Player 2 can't see it
  [x] Player 2 guesses in a loop until correct
  [x] Give "Too low" / "Too high" hints
  [x] Count attempts and show the total at the end

  FIXES AND SAFETY
  [x] Handle non-number input (letters) with cin.clear() + cin.ignore()
  [x] Validate Player 2's guess is also within 0-100
  [x] Clear scrollback too ("\033[3J\033[2J\033[H") so the number can't be scrolled up to
  [x] Remove unused variables (or use them)

  FEATURES
  [x] Hide Player 1's typing while entering the number (turn off echo)
  [x] Limit the number of attempts (e.g., 7) and show "Game over" with the answer
  [x] Show attempts left after each guess
  [x] Add "Play again? (y/n)" using a do...while loop (make 'again' a char)
  [x] Add a single-player mode where the computer picks the number (random)
*/



#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int number, guess;
	const int attempts = 10;
	char again;
	char select;
	srand(time(0));
	
	cout << "--------GUESS IT OUT--------" << endl;
	
	cout << "Welcome to Guess It Out, a number guessing game." << endl;
	
	do{
		do{
        cout << "---Game Modes--- " << endl;
		
		cout << "1. Single Player Mode" << endl;
		
		cout << "2. Multi-player Mode" << endl;
		
		cout << "Select(1/2): ";
		cin >> select;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		}while(select != '1' && select != '2');
		
		system("cls");
		
		if(select == '1'){
			number = rand()%101;
			cout << "A random number has been choosen by the computer." << endl;
		}
		
		else
		{
		
	    do{
           cout << "Player 1| Enter any number(0-100): ";
           cin >> number;
		
         if(cin.fail()){
	       	cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        number = -1;
	        cout << "Numbers Only!!" << endl;
		    }
		
         else if(number > 100|| number < 0){
	        cout << "!!Range Exceeded!!" << endl;
            cout << "!!Try Again!!" << endl;
            }
		
        }while(number > 100|| number < 0 || select == '1');
		}
	     
        system("cls");
		
	
	  for(int i = 1; i <= attempts; i++){
		
		cout << "Player 2| Guess the number(0-100): ";
		cin >> guess;
		
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			guess = -1;
			cout << "!!Numbers Only!!" << endl;
			i--;
			continue;
		}
		
		else if(guess == number){
			
			cout << "Correct Answer || Well done!" << endl;
			
			if(i == 1){
				cout << "Challenge completed in: " << i << " attempt." << endl;
			}
			else{
				cout << "Challenge completed in: " << i << " attempts." << endl;
			}
			break;
		}
		
		else if(guess < number){
			cout << "Too Low__Try Again!!" << endl;
		}
		
		else if(guess > number){
			cout << "Too High__Try Again!!" << endl;		
		}
		
		else if(guess > 100|| guess < 0){
			cout << "Range Exceeded || Please! Try again!" << endl;
			i--;
		}
		
		if(i == attempts){	
			cout << "Attempts Exceeded !! The correct answer is: " << number << endl;
        }
        
		cout << "You have: " << attempts - i << " attempts remaining." << endl;  		
	    }
	
	
	//----play again----
	 do{
	 	
	    cout << "Play Again(y/n): ";
	    cin >> again;
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    
	 }while(again != 'y' && again != 'Y' && again != 'n' &&  again != 'N');
	 
	 system("cls");
	 
	}while(again == 'y' || again == 'Y');
	
	cout << "Thank For Playing" << endl;
    return 0;
}