#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
bool checkKey(string key);
string A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string a = "abcdefghijklmnopqrstuvwxyz";
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string key = argv[1];
        checkKey(key);
        string input = get_string("Message: ");
        int len = strlen(input);
        char output[len];
        printf("Output: ");
        for (int i=0; i<len; i++)
        {
            for(int j = 0; j<26 ; j++)
            {
                if (input[i] == toupper(key[j]) && isalpha(input[i]))
                {
                    output[i] = toupper(A[j]);
                    printf("%c", output[i]);
                }
                else if (input[i] == tolower(key[j]) && isalpha(input[i]))
                {
                    output[i] = tolower(a[j]);
                    printf("%c", output[i]);
                }

            }
            if (!(isalpha(input[i])))
            {
                printf("%c", input[i]);
            }
        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./substitution key\n");
    }
}
bool checkKey(string key)
{
    if (strlen(key) == 26)
    {
        for (int i = 0; i<26; i++)
        {
            if(isalpha(key[i]))
            {
                continue;
            }
            else if(!(isalpha(key[i])))
            {
                printf("Must be a albhabet.\n");
                return false;
            }
        }
        return true;
    }
    else
    {
        printf("Key must be 26 letters long.\n");
        return false;
    }
}
