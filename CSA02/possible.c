#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
}

int main(int argc, char* argv[])
{
    
    // checks if there are the correct amount of command-line arguments (hidden word and guess word)
    if (argc < 2) 
    {
        printf ("command usage: %s %s\n",argv[0],"center");
        return 1;
    }

    // assigns arguments to pointers hidden_word and guess_word
    char* guess_word = argv[1];
    char* hints = argv[2];
    
    int found = 0;
    char possible_hidden[6]; // possible hidden words in answers.txt file
    char new_hints[6];

    while (scanf("%5s", possible_hidden) == 1)
    {   
        generate_hints(possible_hidden, guess_word, new_hints);

        if (strcmp(new_hints, hints) == 0)
        {
            found += 1;
            printf("%s ", possible_hidden);
        }
    }
    if (found == 0)
    {
        printf("No possible hidden words found.\n");
    }

    printf("\n");
}