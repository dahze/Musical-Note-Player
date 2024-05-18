#include <iostream>
#include <fstream>
#include <iomanip>
#include <Windows.h>

using namespace std;

// Piece Selector
string selector(int& count)
{
	int number;
	string welcome = "Welcome to Tayyab's Musical Note Player!";

	if (count < 1)
	{
		for (int i = 0; i < 20; i++)
		{
			cout << '\n';
		}
		cout << setw(57);

		for (int i = 0; i < welcome.length(); i++)
		{
			cout << welcome[i];
			Sleep(25);
		}

		cin.get();
		system("cls");
	}

	cout << "\n1. Melancholy\n";
	Sleep(250);
	cout << "2. Uncertainity\n";
	Sleep(250);
	cout << "3. Acceptance\n";
	Sleep(250);
	cout << "4. Silence\n\n";
	Sleep(250);

	string pieceselect = "Please select a musical piece from the above (1/2/3/4): ";

	do
	{
		for (int i = 0; i < pieceselect.length(); i++)
		{
			cout << pieceselect[i];
			Sleep(25);
		}

		cin >> number;

		if (number < 1 || number > 4)
		{
			cout << "[Error] ";
		}
	} while (number < 1 || number > 4);

	if (number == 1)
	{
		ifstream musicobj("Melancholy.txt");
		string music((istreambuf_iterator<char>(musicobj)), (istreambuf_iterator<char>()));
		return music;
	}

	else if (number == 2)
	{
		ifstream musicobj("Uncertainity.txt");
		string music((istreambuf_iterator<char>(musicobj)), (istreambuf_iterator<char>()));
		return music;
	}

	else if (number == 3)
	{
		ifstream musicobj("Acceptance.txt");
		string music((istreambuf_iterator<char>(musicobj)), (istreambuf_iterator<char>()));
		return music;
	}

	else if (number == 4)
	{
		ifstream musicobj("Silence.txt");
		string music((istreambuf_iterator<char>(musicobj)), (istreambuf_iterator<char>()));
		return music;
	}
}

// Octave Selector
int octaveselect()
{
	int octave;

	cout << "1. Low Pitched (Barely Audible)\n";
	Sleep(250);
	cout << "2. High Pitched (Too Audible)\n";
	Sleep(250);
	cout << "3. Middled (Perfect)\n\n";
	Sleep(250);

	string octavepreference = "Please choose a preference for the sound (1/2/3): ";

	do
	{
		for (int i = 0; i < octavepreference.length(); i++)
		{
			cout << octavepreference[i];
			Sleep(25);
		}

		cin >> octave;

		if (octave > 3 || octave < 1)
		{
			cout << "[Error] ";
		}
	} while (octave > 3 || octave < 1);

	return octave;
}

// Tempo Selector
int temposelect()
{
	int tempo;
	string tempopreference = "Please choose a tempo between 200 ms - 500 ms: ";

	do
	{
		for (int i = 0; i < tempopreference.length(); i++)
		{
			cout << tempopreference[i];
			Sleep(25);
		}

		cin >> tempo;

		if (tempo < 200 || tempo > 500)
		{
			cout << "[Error] ";
		}
	} while (tempo < 200 || tempo > 500);

	return tempo;
}

// Piano Display
void display()
{
	cout << "|    |  |   |  |    ||    |  |   |  |   |  |    |\n|    |  |   |  |    ||    |  |   |  |   |  |    |\n|    |  |   |  |    ||    |  |   |  |   |  |    |\n|     ||     ||     ||     ||     ||     ||     |\n|     ||     ||     ||     ||     ||     ||     |\n|  C  ||  D  ||  E  ||  F  ||  G  ||  A  ||  B  |\n\n";
}

/*
Note Sheet

C = C
D = D
E = E
F = F
A = A
B = B

C# = V
D# = W
F# = X
G# = Y
A# = Z
*/

// Frequency Checker/Calculator
inline float frequencycheck(char& note, int& octave)
{
	float frequency = 0.0;

	// C
	if (note == 'C')
	{
		frequency = 261.33;
		cout << "   -\n";
	}

	// D
	else if (note == 'D')
	{
		frequency = 293.66;
		cout << "          -\n";
	}

	// E
	else if (note == 'E')
	{
		frequency = 329.63;
		cout << "                 -\n";
	}

	// F
	else if (note == 'F')
	{
		frequency = 349.23;
		cout << "                        -\n";
	}

	// G
	else if (note == 'G')
	{
		frequency = 392.00;
		cout << "                               -\n";
	}

	// A
	else if (note == 'A')
	{
		frequency = 440.00;
		cout << "                                      -\n";
	}

	// B
	else if (note == 'B')
	{
		frequency = 493.88;
		cout << "                                             -\n";
	}

	// C#
	else if (note == 'V')
	{
		frequency = 277.18;
		cout << "      .-\n";
	}

	// D#
	else if (note == 'W')
	{
		frequency = 311.13;
		cout << "             .-\n";
	}

	// E#
	else if (note == 'X')
	{
		frequency = 369.99;
		cout << "                           .-\n";
	}

	// F#
	else if (note == 'Y')
	{
		frequency = 415.30;
		cout << "                                  .-\n";
	}

	// G#
	else if (note == 'Z')
	{
		frequency = 466.16;
		cout << "                                         .-\n";
	}

	if (octave == 1)
	{
		frequency /= 2;
	}

	else if (octave == 2)
	{
		frequency *= 2;
	}

	return frequency;
}

// Repetition Prompter
char prompter()
{
	char answer;
	string theend = "The End";

	Sleep(250);
	cout << "|" << setw(21);
	for (int i = 0; i < theend.length(); i++)
	{
		cout << theend[i];
		Sleep(250);
	}
	cout << setw(21) << "|";

	cin.ignore(cin.rdbuf()->in_avail());
	cin.get();
	system("cls");

	string anotherpiece = "Would you like to listen to another piece? (Y/N): ";

	for (int i = 0; i < 20; i++)
	{
		cout << '\n';
	}
	cout << setw(51);

	for (int i = 0; i < anotherpiece.length(); i++)
	{
		cout << anotherpiece[i];
		Sleep(25);
	}

	cin >> answer;
	system("cls");

	return answer;
}

// End Display 
void end()
{
	string thankyou = "Thank you for listening. :]";

	for (int i = 0; i < 20; i++)
	{
		cout << '\n';
	}
	cout << setw(64);

	for (int i = 0; i < thankyou.length(); i++)
	{
		cout << thankyou[i];
		Sleep(25);
	}

	cin.ignore(cin.rdbuf()->in_avail());
	cin.get();
	system("cls");
}

// Main Function
int main()
{
	int count = 0;

	struct
	{
		char answer = '\0';
		string piece{};
		int tempo{ 0 };
		int octave{ 0 };
	} var;

	do
	{
		var.piece = selector(count);
		cout << "\n-\n\n";
		var.tempo = temposelect();
		cout << "\n-\n\n";
		var.octave = octaveselect();

		system("cls");
		cout << '\n';

		display();

		Sleep(1500);
		for (int i = 0; i < var.piece.length(); i++)
		{
			Beep(frequencycheck(var.piece[i], var.octave), var.tempo);
		}

		cout << "\n\n";
		Sleep(500);

		var.answer = prompter();
		count++;
	} while (var.answer == 'Y' || var.answer == 'y');

	end();

	return 0;
}