#include<stdio.h>
#include<stdlib.h>

char STR[100], PAT[100], REP[100], ANS[100];
int s, p, r, a, flag = 0;

void read();
void replace();
void display();

int main() {
    read();
    replace();
    display();
    return 0;
}

void read() {
    printf("Enter the MAIN string: ");
    scanf(" %[^\n]", STR);  // Added space before %[^\n] to consume any leftover newline characters
    printf("Enter the PATTERN string: ");
    scanf(" %[^\n]", PAT);
    printf("Enter the Replace String: ");
    scanf(" %[^\n]", REP);
}

void replace() {
    s = p = a = 0;
    while (STR[s] != '\0') {
        if (STR[s] == PAT[p]) {
            s++;
            p++;
            if (PAT[p] == '\0') {  // Pattern found
                flag = 1;
                for (r = 0; REP[r] != '\0'; r++, a++) 
                    ANS[a] = REP[r];
                p = 0;  // Reset pattern pointer
            }
        } else {
            if (p > 0) {  // If there was a partial match, reset p
                s -= p;  // Go back in the STR to where mismatch occurred
                p = 0;   // Reset pattern pointer
            }
            ANS[a] = STR[s];  // Copy the character from STR to ANS
            s++;
            a++;
        }
    }
    ANS[a] = '\0';  // Null-terminate the ANS string
}

void display() {
    if (flag == 0) {
        printf("Pattern not found\n");
    } else {
        printf("\nThe resultant string is: %s\n", ANS);
    }
}
