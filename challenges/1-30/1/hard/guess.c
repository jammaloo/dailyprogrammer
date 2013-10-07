/*

http://www.reddit.com/r/dailyprogrammer/comments/pii6j/difficult_challenge_1/

we all know the classic "guessing game" with higher or lower prompts. lets do a role reversal; you create a program that will guess numbers between 1-100, and respond appropriately based on whether users say that the number is too high or too low. Try to make a program that can guess your number based on user input and great code!


Random language selector picked C! Enjoy my first ever C program.

*/

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

int makeGuess(int, int);

int main()
{
    //guess boundaries
	int low_bound = 1;
	int high_bound = 100;

	//whether we correctly guessed
	int guessed = 0;

	//current guess
	int guess = 0;

	//current answer from user
	char answer;

	while(!guessed)
	{
	    //make the guess
        guess = makeGuess(low_bound, high_bound);


        //check if the guess is right
        printf("Is your number Higher(h), Lower(l) or Equal(e) to %d? ", guess);
        fflush(stdout);

        scanf(" %c", &answer);

        answer = tolower(answer);

        if(answer == 'e')
        {
            guessed = 1;
        }
        else if(answer == 'l')
        {
            high_bound = guess - 1;
        }
        else if(answer == 'h')
        {
            low_bound = guess + 1;
        }
        else
        {
            printf("Sorry, I didn't understand that, please enter h, l or e\n");
        }

        sleep(0.5);
	}

	printf("YOUR NUMBER WAS %d!\n", guess);
	printf("MACHINES WIN!\n");

	return 0;
}

int makeGuess(int low, int high)
{
    return round((low + high) / 2);
}