#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enPlayerChoice { stone = 1, paper = 2, scissors = 3 };

enum enWinner { player = 1, computer = 2, noWinner = 3 };

/*

int readPositiveNumber(string message)
{
 int number = 0 ;
 do
 {
  cout << message ;
  cin >> number ;
 }while (number < 0);

 return ( int)number ;
}

*/

short readRoundsNumber(string message)
{
	short rounds = 0;

	do
	{
		cout << message;
		cin >> rounds;
	} while (rounds < 1 || rounds > 10);

	return rounds;
}

int RandomNumber(int From, int To)
{
	//Function to generate a random number
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

enWinner checkRoundWinner(short playerChoice, short computerChoice)
{
	if (playerChoice == computerChoice)
		return enWinner::noWinner;

	else if ((playerChoice == enPlayerChoice::stone && computerChoice == enPlayerChoice::scissors)
		|| (playerChoice == enPlayerChoice::scissors && computerChoice == enPlayerChoice::paper)
		|| (playerChoice == enPlayerChoice::paper && computerChoice == enPlayerChoice::stone))
		return enWinner::player;

	else return enWinner::computer;
}

string checkFinalWineer(short playerWonTimes, short computerWonTimes)
{
	if (playerWonTimes == computerWonTimes)
	{
		system("color 6F");
		return "No Winner";
	}

	else if (playerWonTimes > computerWonTimes)
	{
		system("color 2F");
		return "Player";
	}

	else
	{
		system("color 4F");
		cout << "\a";
		return "Computer";
	}
}

/*
bool askPlayerToRePlay(char YorN)
{
 if
  return true ;

 else return false ;
}
*/

string checkChoices(short choice)
{
	switch ((enPlayerChoice)choice)
	{
	case enPlayerChoice::stone:
		return "Stone";
	case enPlayerChoice::scissors:
		return "Scissors";
	default:
		return "Paper";
	}
}

void printRoundResult(
	short round, short playerChoice, short computerChoice,
	short& playerWonTimes, short& computerWonTimes, short& drawTimes
)
{
	cout << "\n_____________ Round[" << round << "]_____________\n";

	cout << "\nPlayer choice : " << checkChoices(playerChoice);

	cout << "\nComputer choice : " << checkChoices(computerChoice);

	cout << "\nRound winner : ";
	switch (checkRoundWinner(playerChoice, computerChoice))
	{
	case enWinner::noWinner:
		system("color 6F");
		cout << "[No winner]";
		++drawTimes;
		break;

	case enWinner::player:
		system("color 2F");
		cout << "[Player]";
		++playerWonTimes;
		break;

	default:
		system("color 4F");
		cout << "\a";
		cout << "[Computer]";
		++computerWonTimes;
		break;
	}

	cout << "\n___________________________________\n" << endl;
}

void printFinalResult(short rounds, short playerWonTimes, short computerWonTimes, short drawTimes)
{
	cout << "\n\n"
		<< "          _______________________________________________\n"
		<< "\n                    +++ G a m e  O v e r +++\n"
		<< "          _______________________________________________\n\n"
		<< "          ________________[Game results]_________________\n\n"
		<< "          Game rounds        : " << rounds << endl
		<< "          Player Won Times   : " << playerWonTimes << "\n"
		<< "          Computer Won Times : " << computerWonTimes << "\n"
		<< "          Draw Times         : " << drawTimes << "\n"
		<< "          Final winner       : " << checkFinalWineer(playerWonTimes, computerWonTimes)
		<< "\n          _______________________________________________" << endl;
}

void playRounds(short& rounds, short& playerChoice, short& playerWonTimes, short& computerWonTimes, short& drawTimes)
{
	short round = 0, computerChoice = 0;

	rounds = 0, round = 0, playerChoice = 0, computerChoice = 0, playerWonTimes = 0, computerWonTimes = 0, drawTimes = 0;

	rounds = readRoundsNumber("Enter rounds between 1 to 10 : ");
	do
	{
		round++;

		cout << "\nRound [" << round << "] begin : " << "\n\n"
			<< "Your choice stone[1] , paper[2] , scissors[3] ? ";
		cin >> playerChoice;

		if (playerChoice < 1 || playerChoice > 3)
			continue;

		computerChoice = RandomNumber(1, 3);

		printRoundResult(round, playerChoice, computerChoice, playerWonTimes, computerWonTimes, drawTimes);
		cout << endl;
	} while (round < rounds);
}

void StartGame()
{
short rounds = 0, playerChoice = 0, playerWonTimes = 0, computerWonTimes = 0, drawTimes = 0;

	char YorN = 'y';
	do
	{
		YorN = 'y';

		system("cls");
		cout << "\033[0m";
		cout << "\033[2J\033[H";

		playRounds(rounds, playerChoice, playerWonTimes, computerWonTimes, drawTimes);
		if (playerChoice < 1 || playerChoice > 3)
		{
			//cout << "pl " << playerChoice;
			break;
		}

		printFinalResult(rounds, playerWonTimes, computerWonTimes, drawTimes);
		cout << "\n          Do you want to play again Y/N ? ";
		cin >> YorN;
		//rounds = 0 ,playerWonTimes = 0,computerWonTimes = 0,drawTimes = 0 ;
	} while (YorN == 'y' || YorN == 'Y');
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}
