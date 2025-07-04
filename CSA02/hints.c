#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void valid_input(char *hidden_word, char *guess_word)
{
    // calculates the length of the hidden word and the guess word
    int hidden_word_len = strlen(hidden_word);
    int guess_word_len = strlen(guess_word);

    // checks that the length of the hidden_word and the guess_word is the same
    if (hidden_word_len != guess_word_len)
    {
        printf("error : hidden word is not the same length as the guess word\n");
        exit(1);
    }

    // iteratotes through each character in word
     for (int i = 0; i < guess_word_len; i++)
    {
        // checks if the guess_word and the hidden_word contains lowercase, alphabetical characters
        if (guess_word[i] < 'a' || guess_word[i] > 'z')
        {
            printf("error : guess word contains the invalid character\n");
            exit(1);
        }

        if (hidden_word[i] < 'a' || hidden_word[i] > 'z')
        {
            printf("error : guess word contains the invalid character\n");
            exit(1);
        }
    }
}


void generate_hints(char *hidden_word, char *guess_word, char *hints)
{
    for (int i = 0; i < strlen(guess_word); i++)
    {
        hints[i] = 'r';
    }

    hints[strlen(guess_word)] = '\0';
    int letter_count[26];
    
    // clear memories of array out to make sure array is empty
    for(int i = 0; i < 26; i++)
    {
        letter_count[i] = 0; // 
    }

    // counting number of every unique character in hidden_word
    for(int i = 0; i < strlen(guess_word); i++)
    {
        letter_count[hidden_word[i] - 'a'] += 1;
    }

    for (int i = 0; i < strlen(guess_word); i++)
    {
        // if the character in hidden_word matches the character in guess_word at character i, then that hints[i] is 'g'
        if (guess_word[i] == hidden_word[i])
        {
            hints[i] = 'g';
            letter_count[guess_word[i] - 'a'] -= 1;
        }
    
    }

    for (int i = 0; i < strlen(guess_word); i++)
    {
        if (letter_count[guess_word[i] - 'a'] > 0 && hints[i] != 'g')
        {
            letter_count[guess_word[i] - 'a'] -= 1;
            hints[i] = 'y';
        }
    }
    printf("The hints are %s.\n", hints);
}

    

int main(int argc, char*argv[]) 
{
    // checks if there are the correct amount of command-line arguments (hidden word and guess word)
    if (argc < 3) 
    {
        printf ("command usage: %s %s\n",argv[0],"center");
        return 1;
    }

    // assigns arguments to pointers hidden_word and guess_word
    char *hidden_word = argv[1];
    char *guess_word = argv[2];

    // calls the valid_input function
    valid_input(hidden_word, guess_word);

    // calls the generate_hints function
    char hints[strlen(guess_word) + 1];
    generate_hints(hidden_word, guess_word, hints);    

    return 0;
}