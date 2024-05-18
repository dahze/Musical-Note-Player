# Musical Note Player

This C++ program is a simple musical note player that reads musical pieces from text files and plays them using the system speaker. The user can select from four different musical pieces, choose the octave and tempo, and listen to the selected piece.

## Features
- **Piece Selector**: Allows users to choose from four predefined musical pieces: Melancholy, Uncertainty, Acceptance, and Silence.
- **Octave Selector**: Offers three octave options for sound pitch: Low Pitched, High Pitched, and Middled.
- **Tempo Selector**: Enables users to set the tempo for the musical piece within a range of 200 ms to 500 ms.
- **Musical Note Player**: Reads the selected musical piece from a text file and plays it using the `Beep` function, with a visual representation of the piano notes.

## Code Overview

### Libraries and Namespace
```cpp
#include <iostream>
#include <fstream>
#include <iomanip>
#include <Windows.h>
using namespace std;
```
The program includes standard libraries for input/output operations, file handling, and formatting. The `Windows.h` library is used for the `Sleep` and `Beep` functions.

### Piece Selector
The `selector` function displays a welcome message (only on the first run) and presents a menu for selecting a musical piece. It reads the chosen piece from a corresponding text file and returns its content as a string.

#### Custom Pieces
Users can compose their own musical pieces by modifying the existing text files or creating a new text file. To use a custom piece, replace the file path in any of the `ifstream` commands with the path to the new text file. Additionally, you can change the name displayed in the `cout` statement for clarity.

##### Example:
If you create a new musical piece file named `CustomPiece.txt`, you can update the `ifstream` command in the code to:
```cpp
ifstream musicobj("CustomPiece.txt");
```
And modify the corresponding `cout` statement to:
```cpp
cout << "1. Custom Piece\n";
```
This allows you to easily integrate your own compositions into the program and enjoy listening to them.

### Octave Selector
The `octaveselect` function allows the user to choose the pitch of the sound by selecting one of three octave options.

### Tempo Selector
The `temposelect` function prompts the user to set the tempo for playing the musical piece within the specified range (200 ms to 500 ms).

### Piano Display
The `display` function visually represents a simple piano keyboard layout.

### Frequency Checker
The `frequencycheck` function determines the frequency of the note to be played based on the note character and the selected octave. It also prints a visual cue on the console representing the note.

### Repetition Prompter
The `prompter` function asks the user if they would like to listen to another piece after the current one finishes playing.

### Main Function
The `main` function orchestrates the overall flow of the program. It initializes variables, calls the selection and setting functions, and plays the selected musical piece using the `Beep` function. The user can choose to listen to another piece or end the session.

```cpp
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
```
