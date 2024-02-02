/* Reversing order of characters in each word of a given string while maintaining original order of words. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * reverseWords(char * s){
    int len_s = strlen(s);
    char* words = (char *)malloc((len_s + 1) * sizeof(char));
    int* spaces = (int *)malloc(len_s * sizeof(int));

    /* Removing trailing and leading spaces */
    int i = len_s - 1;
    while (s[i] == ' ' && i > 0) {
        i--;
    }
    spaces[0] = i;

    int j = 0;
    while (s[j] == ' ' && j < strlen(s)) {
        j++;
    }

    printf("leadtrail: |%s|\n", s);

    /* storing location of spaces in string */
    int k = 1;
    for (int i = spaces[0]; i > -1; i--) {
        if (s[i] == ' ' && s[i+1] != ' ') {
            spaces[k++] = i;
        }
    }

    spaces[k] = j-1;


    /* Putting into "words" our reversed word order string */
    int l = 0;
    for (int i = 0; i < k; i++) {

        for (int j = spaces[i+1]; j <= spaces[i]; j++) {
            // printf("%d\n", i);
            if (s[j] != ' ') {
                words[l++] = s[j];
                // printf("%c", words[l-1]);
            }
        }

        if (i != k-1) {
            words[l++] = ' ';
        }

    }

    words[l-1] = '\0';

    s = (char *)malloc(sizeof(char) * (strlen(words) + 1));
    strcpy(s, words);
    free(words);
    free(spaces);
    return s;
}


int main() {
    char *test1 = "the sky is blue";
    char *test2 = "  hello world  ";
    char *test3 = "  hello  to th  e  world    ";
    char *test4 = "";
    char *test5 = "    ";

    char * output1 = reverseWords(test1);
    printf("Reversed:|%s|\n", output1);
    free(output1);

    char * output2 = reverseWords(test2);
    printf("Reversed:|%s|\n", output2);
    free(output2);

    char * output3 = reverseWords(test3);
    printf("Reversed:|%s|\n", output3);
    free(output3);

    char * output4 = reverseWords(test4);
    printf("Reversed:|%s|\n", output4);
    free(output4);
    
    char * output5 = reverseWords(test5);
    printf("Reversed:|%s|\n", output5);
    free(output5);
}
