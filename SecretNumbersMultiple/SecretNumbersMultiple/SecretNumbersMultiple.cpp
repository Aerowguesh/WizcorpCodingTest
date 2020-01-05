// SecretNumbersMultiple.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <time.h>

using namespace std;

/* Generate 3 different random numbers between 1 and 10 */
void generate_secret_numbers(int& secret_number_1, int& secret_number_2, int& secret_number_3)
{
	secret_number_1 = rand() % 10 + 1;
	do
	{
		secret_number_2 = rand() % 10 + 1;
	} while (secret_number_2 == secret_number_1);
	do
	{
		secret_number_3 = rand() % 10 + 1;
	} while (secret_number_3 == secret_number_1 || secret_number_3 == secret_number_2);
}

int main()
{
	int secretNumber1, secretNumber2, secretNumber3, result;

	/* We use a char* to get the player input so we can test if it's really an integer later */
	char* playerInput;
	playerInput = (char*)malloc(100 * sizeof(char)); 
	int playerNumber;

	/* Initialize random seed */
	srand(time(NULL));

	/* Generate secret numbers between 1 and 10 */
	generate_secret_numbers(secretNumber1, secretNumber2, secretNumber3);

	cout << "3 secret numbers between 1 and 10 have been generated. Can you find a number that is a multiple of them ?" << endl;

	do
	{
		result = 0;

		/* Ask for player input and convert it to an integer */
		cout << "Player input : ";
		cin >> playerInput;
		char* pEnd;
		playerNumber = strtol(playerInput, &pEnd, 10);

		/* If the input isn't an integer, we treat it as if the player typed 0 */
		if (playerNumber == 0) 
		{
			cout << "Your input should be an integer different from 0." << endl;
		}
		else
		{
			/* The result is the amount of secret numbers that are a factor of the submitted number */
			result += playerNumber % secretNumber1 == 0 ? 1 : 0;
			result += playerNumber % secretNumber2 == 0 ? 1 : 0;
			result += playerNumber % secretNumber3 == 0 ? 1 : 0;
			cout << "Result : " << result << endl;
		}

	} while (result != 3);
	
	cout << "Congratulations !" << endl << "Your number " << playerNumber << " is a multiple of the 3 secret numbers : " << secretNumber1 << " " << secretNumber2 << " " << secretNumber3 << endl;

	/* Free the space used by the player input */
	free(playerInput);

	/* Wait for user input to close the console window */
	system("pause");

	return 0;
}