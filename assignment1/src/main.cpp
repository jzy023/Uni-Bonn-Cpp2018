#include <iostream>
#include <vector>
#include <array>
#include <math.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include <stdio.h>
#include <unistd.h>


using namespace std;

// Guessing Game
int main(int argc, char const *argv[])
{
	/* code */
	srand(time(NULL));
	int num = rand()%100;
	int guess;

	// debug
	cout << num << endl;

	int max,count;
	max = 10;
	count = 1;

	cout << "The target number is an integer between 0 and 99\nplease ENTER your guess: " << endl;
	cin >> guess;


	while(guess != num && count < max){
		if(guess > num){
			cout << "Your guess is too LARGE, please guess again" << endl;
			cin >> guess;
		}
		else if(guess < num){
			cout << "Your guess is too SMALL, please guess again" << endl;
			cin >> guess;
		}
		count++;
	}
	if(count == max){
		cout << "Max number of guessing achieved. Game Over.";
	}
	else{
		cout << "Congradulation! You Win!";
	}

}