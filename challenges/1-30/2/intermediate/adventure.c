/*

http://www.reddit.com/r/dailyprogrammer/comments/pjbuj/intermediate_challenge_2/

create a short text adventure that will call the user by their name. The text adventure should use standard text adventure commands ("l, n, s, e, i, etc.").
for extra credit, make sure the program doesn't fault, quit, glitch, fail, or loop no matter what is put in, even empty text or spaces. These will be tested rigorously!
For super extra credit, code it in C

I WANT THAT SUPER EXTRA CREDIT so I picked C, my second ever C program, expect it to be horrible

*/

/*
The adventure file format is as follows;

Room Number;Display Text;[action_letter;room_number...action_letter;room_number;]

Room Number is a 4 digit number to reference each scenario.
Display Text is a string to show the player for this scenario
Action_letter and line_number can be repeated 0 to unlimited times. action_letter is the key the user has to press to get taken to room room_number
If no actions are presented, it is assumed the game is over.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* processRoom(FILE*, char*);
char* getField(char*, int);
char* getRoom(FILE*, char*);
char* getRoomText(char*);
int isGameOver(char*);
char* performAction(char*);

int main()
{
    int game_over = 0;
    char* current_room = "0001";
    FILE* adventure_file = fopen("adventure.csv", "r");

    printf("WELCOME TO JORK, the hyperinteractive text game\n");

    //game loop
    while(!game_over)
    {
        current_room = processRoom(adventure_file, current_room);
        if(!current_room)
        {
            game_over = 1;
        }
    }

    printf("THE GAME IS OVER. GO HOME.\n");
    return 0;
}

char* processRoom(FILE* adventure_file, char* room_number)
{
    //read through the adventure file until you find the right room
    //it means the whole file being read every time, but deal with it
    char* line;

    //grab the current line from the adventure file
    line = getRoom(adventure_file, room_number);

    if(!line)
    {
        printf("Room %s could not be found\n", room_number);
        return 0;
    }

    //output room description
    printf("%s\n", getRoomText(line));

    //if game is over then skip out now
    if(isGameOver(line)) return 0;

    //take the user action
    room_number = performAction(line);

    return room_number;
}

//grabs user input and performs the relevant action
char* performAction(char* line)
{
    char action;
    scanf(" %c", &action);

    //loop through actions
    char* action_key;
    char* action_room;
    int i = 3;
    while(1)
    {
        action_key = getField(line, i);
        action_room = getField(line, i + 1);
        i = i + 2;
        //if there is no action
        if(!action_key || !action_room)
        {
            printf("Sorry, I didn't understand that.\n");
            return performAction(line);
        }

        //this isn't the correct action, so keep going
        if(action != action_key[0]) continue;

        //this is the chosen action, so go to that room
        return action_room;
    }
    return 0;
}

//checks if the game is over
int isGameOver(char* line)
{
    //if there are no actions, then the game is over
    if(!getField(line, 3)) return 1;
    return 0;
}

//gets the text for a room
char* getRoomText(char* line)
{
    //get room_number
    return getField(line, 2);
}

//gets the csv line for the current room
char* getRoom(FILE* adventure_file, char* room_number)
{
    char line[1024];
    char* current_room;
    fseek(adventure_file, 0, SEEK_SET);
    while(fgets(line, 1024, adventure_file))
    {
        //get room_number
        current_room = getField(line, 1);

        if(strcmp(current_room, room_number) == 0)
        {
            return strdup(line);
        }
    }
    return 0;
}

//reads a line as a csv
//grabbed from http://stackoverflow.com/questions/12911299/read-csv-file-in-c
char* getField(char* line, int num)
{
    char* tmp = strdup(line);
    char* tok;
    for (tok = strtok(tmp, ";");
        tok && *tok;
        tok = strtok(NULL, ";\n"))
    {
        if (!--num)
            return tok;
    }
    return 0;
}