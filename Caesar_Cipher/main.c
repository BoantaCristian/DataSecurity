#include <stdio.h>
#include <stdlib.h>

int main()
{
    char message[50], current;
    int i, key;

    printf("Enter a message to encrypt: ");
    gets(message);  // cu scan %s daca aveam spatiu intre cuvinte, dupa spatiu trecea la urmatorul scan care nu poate citi char/string si returna eroare
    while(key <= 0 || key >= 27)
    {
        printf("Enter key: ");
        scanf("%d", &key);
        if(key <= 0 || key >= 27)
        {
            printf("Wrong key \nHint: Key must be between 1 and 26 \n");
        }
    }

    for(i = 0; message[i] != '\0'; ++i)
    {
        current = message[i];

        if(current >= 'a' && current <= 'z')            // pentru lowercase
        {
            current = current + key;                    // adauga cheia la codul ascii

            if(current > 'z'){
                current = current - 'z' + 'a' - 1;      // daca current depaseste z scade codul ascii al lui z si il adauga pe al lui a ( z - a = 26) - 1
            }

            message[i] = current;
        }
        else if(current >= 'A' && current <= 'Z')       // pentru uppercase
            {
                current = current + key;

                if(current > 'Z')
                {
                    current = current - 'Z' + 'A' - 1;  // daca current depaseste Z scade codul ascii al lui Z si il adauga pe al lui a ( Z - A = 26) - 1
                }

            message[i] = current;
            }
    }

    printf("Encrypted message: %s", message);
    return 0;
}
