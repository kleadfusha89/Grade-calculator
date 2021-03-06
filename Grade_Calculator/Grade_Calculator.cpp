// Name:		Klead Fusha
// Summary:		A calculator of all grades
//              throughout the semester and stores the information into a txt file

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "string"
#include "iomanip"

using namespace std;

ofstream ofs("Grade_Calculator.txt");

// Global variables
string myname = "Fusha Klead";
string dat = "March 19";
string crnum = "CIS2541-001";
string lab = "Midterm";
string sum = "A calculation of a student's grades";
string eof = "EOF MESSAGE";
string lnu = "_____________________________"
"___________________________________________________";
string pipe = "|";
string lnu2 = "|___________________________"
"___________________________________________________|";

// Variables for this program only
string loopttle = "            Calculating grades";
string dashes = "-------------------------------------------";
int choice;
string choice1 = "1. Name of assignments";
string choice2 = "2. User's score";
string choice3 = "3. Available points";
string choice4 = "4. Total number of assignments";
string choice5 = "5. Quit the program!";
string errmsg = "Please enter a valid choice from the menu!!";
string prompt = "Choose an option from the menu 1-5:      ";
string totalhw = "How many assignments did you have?       ";
string entrname = "Enter name of assignment #";
string colon = " : ";
string note = "You can enter the data for your assignments ";
string note2 = "by choosing options 1, 2, 3 from the menu! ";
string equals = "===========================================";
string yourscr = "Enter your score for ";
string totscr = "Enter the total points for ";
string lnu3 = "|_____________________|__________________"
"|__________________|__________________|";
string agrade = "A         ";
string bgrade = "B         ";
string cgrade = "C         ";
string dgrade = "D         ";
string fgrade = "F         ";
string assi = "    Assignment";
string totl = "Total";
string uscore = "    Your Score";
string tscore = "    Total Score";
string lg = "    Letter Grade";

//****************************
//* Create a line with pipes *
//****************************
void pipefunc()
{
	ofs << lnu2 << endl;
}

//**********
//* Header *
//**********
void header()
{
	ofs << lnu << endl;
	ofs << pipe
		<< left << setw(20) << myname
		<< left << setw(20) << dat
		<< left << setw(20) << crnum
		<< left << setw(18) << lab
		<< pipe << endl;
}

//**********
//* Footer *
//**********
void footer()
{
	ofs << pipe << left << setw(78) << sum << pipe << endl;
}

//*******************
//* End of the file *
//*******************
void eoff()
{
	ofs << pipe
		<< left << setw(15) << eof
		<< left << setw(18) << myname
		<< left << setw(13) << dat
		<< left << setw(15) << crnum
		<< left << setw(17) << lab
		<< pipe << endl;
}

//*********************************
//* This is the header of the     *
//* table we're going to print    *
//*********************************
void hdr()
{
	ofs << pipe
		<< right << setw(44) << loopttle
		<< right << setw(35) << pipe << endl;
	pipefunc();
}


//*********************************
//* This function shows the menu  *
//* options (without the equal    *
//* signs that are decorating     *
//* the menu the first time it    *
//* displays). It was created     *
//* because we're going to print  *
//* only the options after the    *
//* first time the menu shows     *
//* (without the decoration)      *
//*********************************
void menuoptn()
{
	cout << string(5, '\t') << choice1 << endl;
	cout << string(5, '\t') << choice2 << endl;
	cout << string(5, '\t') << choice3 << endl;
	cout << string(5, '\t') << choice4 << endl;
	cout << string(5, '\t') << choice5 << endl;
}

//*********************************
//* We're going to pass to this   *
//* function the total number     *
//* of assignments that we entered*
//* after choosing menu option    *
//* 4, and a string array which   *
//* is going to be filled with    *
//* the input the user will give  *
//* to the system and will contain*
//* the names of the assignments. *
//* The total number of assignment*
//* s is passed by value because  *
//* we're not going to change     *
//* it, we'll only need it as     *
//* a sentinel value to stop the  *
//* loop. The function will be    *
//* called when we choose 1 from  *
//* the menu.					  *
//*********************************
void assgname(int total, string * arr1)
{
	cout << endl;

	int	counter = 1;
	for (int i = 0; i < total; i++)
	{
		cout << string(5, '\t') << entrname << counter << colon;

		counter++;

		if (i == 0)
		{
			cin.ignore();
		}

		getline(cin, arr1[i]);

	}

	cout << string(5, '\t') << dashes << endl;
	menuoptn();
	cout << endl;

}

//*********************************
//* Total number of assignments   *
//* will have the same role as in *
//* the previous function. We'll  *
//* import the array string only  *
//* to display specifically the   *
//* name of the assignment we're  *
//* asking the user to give a     *
//* score to, and the array 2     *
//* (int) which we're going to    *
//* fill with the user scores.    *
//* This function will be called  *
//* when we choose 2 from the menu*
//*********************************
void usrscore(int total, int * arr2, string * arr1)
{
	cout << endl;

	for (int i = 0; i < total; i++)
	{
		cout << string(5, '\t') << yourscr << arr1[i] << colon;

		cin >> arr2[i];
	}

	cout << string(5, '\t') << dashes << endl;
	menuoptn();
	cout << endl;
}

//*********************************
//* Total number of assignments   *
//* will have the same role as    *
//* the previous functions. We'll *
//* import the string array only  *
//* to display specifically the   *
//* name of the assignment we're  *
//* asking the user to give an    *
//* input to, and the array 3     *
//* (int) which we're going to    *
//* fill with the total available *
//* points. This function will be *
//* called when we choose 3 from  *
//* the menu					  *
//*********************************
void totscore(int total, int * arr3, string * arr1)
{
	cout << endl;

	for (int i = 0; i < total; i++)
	{
		cout << string(5, '\t') << totscr << arr1[i] << colon;

		cin >> arr3[i];
	}

	cout << string(5, '\t') << dashes << endl;
	menuoptn();
	cout << endl;

}

//*********************************
//* This function will prompt     *
//* the user to enter the total   *
//* number of assignments. We're  *
//* passing it by reference becaus*
//* e we need to save the changes *
//* to the original value of the  *
//* variable, since we're eventual*
//* ly going to pass it to the    *
//* other functions. It will serve*
//* as a sentinel value when we'll*
//* fill the arrays. This function*
//* will be called when we choose *
//* option 4 from the menu		  *
//*********************************
void totassig(int& assign)
{
	cout << string(5, '\t') << totalhw;
	cin >> assign;
	cout << endl;
	cout << string(5, '\t') << dashes << endl;
	cout << string(5, '\t') << note << endl;
	cout << string(5, '\t') << note2 << endl;
	cout << string(5, '\t') << dashes;
	cout << string(2, '\n');
}

//*********************************
//* This function will calculate  *
//* the letter grade for each     *
//* assignment every time the     *
//* loop is iterating.            *
//*********************************
void grade(int * arrtwo, int * arrthree, int j)
{
	double mygrade;

	double second = double(arrtwo[j]);
	double third = double(arrthree[j]);

	// Calculate the grade
	mygrade = second / third * 100;

	// Print the letter grade.
	if (mygrade >= 90)
		ofs << right << setw(18) << agrade;
	else if (mygrade >= 80 && mygrade < 90)
		ofs << right << setw(18) << bgrade;
	else if (mygrade >= 70 && mygrade < 80)
		ofs << right << setw(18) << cgrade;
	else if (mygrade >= 60 && mygrade < 70)
		ofs << right << setw(18) << dgrade;
	else
		ofs << right << setw(18) << fgrade;
}

//*********************************
//* We'll import to this function *
//* the total score and total     *
//* available points, which we'll *
//* print; and we'll calculate    *
//* the final grade. This function*
//* is only the last line of the  *
//* table!                        *
//*********************************
void fnlgrde(int score, int total, double grade)
{
	// Print the string "Total", the total score
	// and the total available points.
	ofs << pipe
		<< setw(21) << left << totl
		<< pipe
		<< setw(18) << right << score
		<< pipe
		<< setw(18) << right << total
		<< pipe;

	double myscr = double(score);
	double tot = double(total);

	// Calculate the final grade
	grade = myscr / tot * 100;

	// Print the final letter grade
	if (grade >= 90)
		ofs << right << setw(18) << agrade;
	else if (grade >= 80 && grade < 90)
		ofs << right << setw(18) << bgrade;
	else if (grade >= 70 && grade < 80)
		ofs << right << setw(18) << cgrade;
	else if (grade >= 60 && grade < 70)
		ofs << right << setw(18) << dgrade;
	else
		ofs << right << setw(18) << fgrade;

	ofs << pipe << endl;
	ofs << lnu3 << endl;


}

//*********************************
//* We're calling this function   *
//* when we quit the program by   *
//* entering 5. A loop will print *
//* to the file, assignment name, *
//* score, total points and it    *
//* will call a function that     *
//* will calculate the letter     *
//* grade. When the loop is done, *
//* it will call a function that  *
//* will calculate and print the  *
//* last line of the table.       *
//*********************************
void printall(int total, string * arr1, int * arr2, int * arr3)
{
	// This will print the table header to the file.
	ofs << pipe
		<< left << setw(21) << assi
		<< pipe
		<< left << setw(18) << uscore
		<< pipe
		<< left << setw(18) << tscore
		<< pipe
		<< left << setw(18) << lg
		<< pipe << endl;
	ofs << lnu3 << endl;

	int totscr = 0;
	int totpoint = 0;
	double fnl = 0;

	// Display name of assignment, score, total score,
	// and calculate the letter grade (call function).
	for (int i = 0; i < total; i++)
	{
		ofs << pipe
			<< left << setw(21) << arr1[i]
			<< pipe
			<< right << setw(18) << arr2[i]
			<< pipe
			<< right << setw(18) << arr3[i]
			<< pipe;

		grade(arr2, arr3, i);

		ofs << pipe << endl;

		ofs << lnu3 << endl;

		totscr += arr2[i];
		totpoint += arr3[i];
	}

	// Call the function that will print only the last line
	// of the menu (Total points and final letter grade)
	fnlgrde(totscr, totpoint, fnl);


}


//*********************************
//* This function will be called  *
//* automatically inside the main *
//* function of the program. It   *
//* will display a menu and will  *
//* iterate until the user enters *
//* 5 to stop the program. Details*
//* d info about the options of   *
//* the menu is provided in the   *
//* switch case statement.        *
//*********************************
void menu()
{
	int assinum = 25;
	string *array1;
	int *array2;
	int *array3;
	array1 = new string[assinum];
	array2 = new int[assinum];
	array3 = new int[assinum];

	cout << string(10, '\n');
	cout << string(5, '\t') << equals << endl;
	cout << string(5, '\t') << loopttle << endl;
	cout << string(5, '\t') << equals << endl;

	menuoptn();

	cout << string(5, '\t') << equals << endl;
	cout << endl;

	do
	{
		cout << string(5, '\t') << prompt;
		cin >> choice;

		switch (choice)
		{
			// Case 1 will call a function that will fill
			// an array with the assignment names.
		case 1:	assgname(assinum, array1);
			break;

			// Case 2 will call a function that will fill
			// an array with the user scores.
		case 2: usrscore(assinum, array2, array1);
			break;

			// Case 3 will call a function that will fill
			// an array with the total available points.
		case 3: totscore(assinum, array3, array1);
			break;

			// Case 4 will call a function that will ask
			// the user about the total number of assignments.
		case 4: totassig(assinum);
			break;

			// Case 5 will print all the inputs from the 
			// previous choices to the file.
		case 5: printall(assinum, array1, array2, array3);
			break;

			// Default message is when the user doesn't follow
			// the instructions of the menu.
		default: cout << string(1, '\n')
			<< string(5, '\t') << errmsg << endl;
		}

	} while (choice != 5);
	system("pause");
}

int main()
{
	header();
	pipefunc();
	pipefunc();
	hdr();
	menu();
	pipefunc();
	footer();
	pipefunc();
	pipefunc();
	eoff();
	pipefunc();
	ofs.close();

	return 0;
}