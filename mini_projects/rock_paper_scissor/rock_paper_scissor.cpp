#include <iostream>
#include <ctime>
#include <conio.h>
using namespace std;

char get_user_choice();
char get_computer_choice();
char declare_winner(char user, char comp);
string choice_name(char c);
int keep_playing();

int main()
{
    int is_continue = 1;
    char user_choice, comp_choice;
    cout << "\nWelcome to Rock, Paper, Scissor game.\n";

    while (is_continue)
    {
        
        // Gets choicees of user and computer
        user_choice = get_user_choice();
        comp_choice = get_computer_choice();

        // Declares winner by comparing choices
        declare_winner(user_choice, comp_choice);

        // Asks user if they want to play again
        is_continue = keep_playing();

        system("cls");
    }

    cout << "\nThank you for Playing,"
         << "\nHave a nice day.\n";

    cout << "\nPress any key to exit...";
    getch();
    return 0;
}

// gets choice from user
char get_user_choice()
{
    char choice;

    cout << "\nPlease enter your choice."
         << "\n--------------------------"
         << "\n'r' for Rock"
         << "\n'p' for Paper"
         << "\n's' for Scissor\n";
    cin >> choice;

    while (choice != 'r' && choice != 'p' && choice != 's')
    {
        system("cls");
        cout << "\nPlease enter valid choice."
             << "\n--------------------------"
             << "\n'r' for Rock"
             << "\n'p' for Paper"
             << "\n's' for Scissor\n";
        cin >> choice;
    }
    return choice;
}

// gets choice of computer
char get_computer_choice()
{
    srand(time(0));
    int rand_num = (rand() % 3) + 1;

    if (rand_num == 1)
        return 'r';
    else if (rand_num == 2)
        return 'p';
    else
        return 's';
}

// compares choices and declares winner among user or compurer or draw
char declare_winner(char user, char comp)
{
    cout << "\nYour Choice : " << choice_name(user) << "  Vs  "
         << "Computer Choice : " << choice_name(comp) << "\n";

    if (user == 'r' && comp == 's' || user == 'p' && comp == 'r' || user == 's' && comp == 'p')
        cout << "\nWohoo! You Win";
    else if (user == 'r' && comp == 'p' || user == 'p' && comp == 's' || user == 's' && comp == 'r')
        cout << "\nOops! You Lost";
    else
        cout << "\nIt's a Draw";
}

// Asks user if they want to play again or exit game
int keep_playing()
{
    int play;
    cout << "\n\nWant to play again? 1 to play or 0 to exit : ";
    cin >> play;

    while (play != 0 && play != 1)
    {
        cout << "\nInvalid option " << play;
        cout << "\nWant to play again? 1 to play or 0 to exit : ";
        cin >> play;
    }
    return play;
}

// returns full name of choice based on character (only for output display purpose)
string choice_name(char c)
{
    if (c == 'r')
        return "Rock";
    else if (c == 'p')
        return "Paper";
    else if (c == 's')
        return "Scissors";
}