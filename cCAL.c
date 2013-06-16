#include <stdio.h>

//  Things to add:
//  1. Mod (%) equation.
//  2. Check for help everywhere

void clearBuffer()
{
    while(getchar() != '\n');
}

char getSymbol()
{
    char sym;

    printf("Enter symbol: ");
    clearBuffer();
    scanf("%c", &sym);

    return sym;
}

int main()
{
        int i;
        double sum = 0, num = 0;
        char x, opt[15], opt1[15];

        printf("Calculator\n");
        printf("Use -h for help\n: ");
        scanf("%c%c", &opt[0], &opt[1]);
        if(opt[0] == '-' && opt[1] == 'h' || opt[1] == 'H')
        {
            printf("\nInstructions\n");
            printf("============\n");
            printf("- This program is a command-line based calculator written in C\n");
            printf("- You can add, subtract, multiply and divide.\n");
            printf("- The program is based on a loop that is designed to read user input for a number and a symbol.\n");
            printf("\n On the first walk through: \n");
            printf("- The sum will be initialized based on user input for the first unknown variable.\n");
            printf("- This is when the sum is initialized.\n");
            printf("\n The rest of the time: \n");
            printf("- Symbols will indicate the equation type run in the loop.\n");
            printf("- Finally a second number is entered which will alter the sum based on the equation requested\n");
            printf("- The sum will be outputted every time an equation is entered.\n");
            printf("- To exit enter = for the symbol, prompt for a second numeric variable will be ignored.\n");
            printf("- Additionally, to ask for help again you must launch the program again until I fix it.\n");
        }
        else
            printf("Help ignored.\n");
        //The calculator will run calculations indivudally/manually until = is entered.
        while(x != '=')
        {
            if(sum == 0)
            {
                printf(": ");
                scanf("%lf", &sum);
                while(sum == 0)
                {
                    clearBuffer();
                    printf("Error\n: ");
                    scanf("%lf", &sum);
                }
                printf("Number stored as %lf\n", sum);
            }
            x = getSymbol();
            while(x != '+' && x != '-' && x != '/' && x != '*' && x != '=')
            {
                printf("Error\n");
                x = getSymbol();
            }
            if(x != '=')
            {
                printf("Enter new number\n: ");
                scanf("%lf", &num);
                while(num == 0)
                {
                    clearBuffer();
                    printf("Error\n: ");
                    scanf("%lf", &num);
                }
                printf("Num stored as %lf\n", num);
            }
            if(x == '+')
                sum += num;
            else if(x == '-')
                sum -= num;
            else if(x == '/')
                sum /= num;
            else if(x == '*')
                sum *= num;
            printf("The sum is %lf\n", sum);
            i++;
            if(x != '=' && i == 10)
            {
                i = 0;
                clearBuffer();
                printf("Enter -c to clear ?\n: ");
                scanf("%c%c", &opt1[0], &opt1[1]);
                clearBuffer();
                if(opt1[0] == '-' && opt1[1] == 'c')
                {
                    sum = 0;
                    printf("Memory erased.\n");
                }
                else
                    printf("Memory reset ignored.\n");
            }
            num = 0;
        }

        return 0;
}
