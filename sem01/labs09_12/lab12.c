#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int first_number, second_number, summ;
    first_number = atoi (argv[1]);
    second_number = atoi (argv[2]);
    summ = first_number + second_number;
    freopen ("out.txt","w", stdout);
    fprintf( stdout, "Summ = %d\n", summ);
    fclose(stdout);
    return 0;
}