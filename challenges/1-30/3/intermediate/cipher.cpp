/*

http://www.reddit.com/r/dailyprogrammer/comments/pkwb1/2112012_challenge_3_intermediate/

Welcome to cipher day!
Create a program that can take a piece of text and encrypt it with an alphabetical substitution cipher. This can ignore white space, numbers, and symbols.
for extra credit, make it encrypt whitespace, numbers, and symbols!
for extra extra credit, decode someone elses cipher!

Random language picker said c++!

*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;


/*
Performs the actual encryption

Goes through the text, and sees if that character is in the original alphabet

if it is, then it swaps it with the character at the same position in the encrypted alphabet
*/
string encryptText(string original_alphabet, string encrypted_alphabet, string text)
{
    string encrypted_text = "";
    char current_letter;
    int index;
    for(int i = 0; i < text.length(); i++)
    {
        current_letter = text.at(i);
        index = original_alphabet.find(current_letter);
        if(index != -1)
        {
            current_letter = encrypted_alphabet.at(index);
        }
        encrypted_text = encrypted_text + current_letter;
    }
    return encrypted_text;
}

/*
Gets a simple substitute alphabet

Just takes the original alphabet and shuffles it.

*/
string getEncryptedAlphabet(int seed, string original_alphabet)
{
    string copy_alphabet = original_alphabet;
    string encrypted_alphabet = "";
    char current_letter;

    //set the seed for the random num generator, so that the same result will happen each time
    srand(seed);
    int index;

    while(encrypted_alphabet.length() < original_alphabet.length())
    {
        //grab a random letter
        index = rand() % copy_alphabet.length();
        current_letter = copy_alphabet.at(index);

        //make sure we aren't substituting a character for itself
        if(original_alphabet.at(encrypted_alphabet.length()) == current_letter)
        {
            continue;
        }

        //add it to new alphabet
        encrypted_alphabet = encrypted_alphabet + current_letter;

        //remove the letter from the copy alphabet so we don't get dupes
        copy_alphabet.erase(index, 1);
    }

    return encrypted_alphabet;
}

string cipher(bool encrypt, int seed, string text)
{
    //add any characters you want encypted to this string
    string original_alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWYXZ123456789!$%^&*(){}[]-_=+@'#~,.<>/?\\| ";

    string encrypted_alphabet = getEncryptedAlphabet(seed, original_alphabet);

    //to decrypt it, we just switch the alphabets around, so we are looking up in reverse
    if(!encrypt)
    {
        string tmp = original_alphabet;
        original_alphabet = encrypted_alphabet;
        encrypted_alphabet = tmp;
    }

    return encryptText(original_alphabet, encrypted_alphabet, text);

    return "HELLO";
}

int main(int argc, char* argv[])
{
    if(argc != 4)
    {
        cout << "Usage: " << argv[0] << " encrypt|decrypt numeric_seed text\n";
        return 0;
    }

    string mode = string(argv[1]);
    int seed = (int)strtoul(argv[2], 0, 0);
    string text = string(argv[3]);

    bool encrypt = (mode == "encrypt");

    cout << cipher(encrypt, encrypt, text) << "\n";
    return 0;
}