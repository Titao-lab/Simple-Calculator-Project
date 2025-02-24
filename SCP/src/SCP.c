// Simple Calculator Project - (EN/US) - (V 1.0.0 Stable).

#include <stdio.h>

int main (void) {

    double FNum = 0, SNum = 0, Base = 0, NegExp = 0, Result = 0;
    int FNumDiv = 0, SNumDiv = 0, Rest = 0;
    char Op = 'A', EndAsk = 'A';

    puts ("Welcome to the Simple Calculator!\n\nWARNING: If you want to use decimal numbers, only use '.', never use ','.\n\n");

    do {

        FNum = 0, SNum = 0, Base = 0, NegExp = 0, Result = 0, FNumDiv = 0, SNumDiv = 0, Rest = 0, Op = 'A', EndAsk = 'A';

        puts ("Please enter the first number, after the operation with '+', '-', '*', '/', '%' or '^', followed by the second number:\n");

        scanf ("%lf %c %lf", &FNum, &Op, &SNum);

        puts ("\nCalculating...\n");

        switch (Op) {

            case '+': { Result = FNum + SNum; break; }
            case '-': { Result = FNum - SNum; break; }
            case '*': { Result = FNum * SNum; break; }
            case '%': { Result = FNum / 100 * SNum; break; }

            case '/': { if (SNum == 0) { puts ("ERROR: Don't do divisions for 0! \nResetting...\n\n"); continue; }
                        else { Result = FNum / SNum, FNumDiv = FNum, SNumDiv = SNum, Rest = FNumDiv % SNumDiv; } break;
            }

            case '^': { Base = 1;

                if (SNum < 0) { NegExp = SNum, SNum = SNum - SNum - SNum; }

                for (int I = 0; I < SNum; I++) { Base *= FNum; }

                if (NegExp < 0) { SNum = NegExp, Result = 1 / Base; }
                else { Result = Base; } break;
            }

            default: { puts ("ERROR: Check if you used '+', '-', '*', '/', '%' or '^' and try again.\nResetting...\n\n"); continue; }
        }

        printf ("%lf %c %lf = %lf - Result: %lf.", FNum, Op, SNum, Result, Result);

        if (Op == '/') { if (Rest > 0) { printf (" - Rest: %d.", Rest); }  }
        
        puts ("\n\nFinished! Do you want to continue? (Y/N):\n");

        scanf (" %c", &EndAsk);

        switch (EndAsk) {

            case 'Y': { puts ("\nResetting...\n\n"); continue; }
            case 'y': { puts ("\nResetting...\n\n"); continue; }

            case 'N': { puts ("\nExiting..."); return 0; }
            case 'n': { puts ("\nExiting..."); return 0; }

            default: { puts ("ERROR: Invalid input, check if you used Y/N and try again.\nResetting...\n\n"); continue; }
        }

    } while (1);

    return 0;
    
}

// End of the code.