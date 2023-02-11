#include <stdio.h>
#include <string.h>

void get_score(int score)
{
    int tdc_pt = 8, tdfg_pt = 7, td_pt = 6, fg_pt = 3, safety_pt = 2; 
    int running_total = 0;

    for (int tdc_count = 0; tdc_count < (score/8)+1; tdc_count++)
    {
        for (int tdfg_count = 0; tdfg_count < (score/7)+1; tdfg_count++)
        {
            for (int td_count = 0; td_count < (score/6)+1; td_count++)
            {
                for (int fg_count = 0; fg_count < (score/3)+1; fg_count++)
                {
                    for (int safety_count = 0; safety_count < (score/2)+1; safety_count++)
                    {
                        if (tdc_count*8 + tdfg_count*7 + td_count*6 + fg_count*3 + safety_count*2 == score)
                        {
                            printf("%i TD + 2pt, %i TD + FG, %i TD, %i 3pt FT, %i Safety\n", tdc_count, tdfg_count, td_count, fg_count, safety_count);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int running = 1;
    int score = 0;
    printf("Enter 0 or 1 to STOP\n");
    while (running)
    {
        printf("Enter the NFL score: ");
        scanf("%i", &score);
        if (score >= 2)
        {
            printf("Possible combinations of scoring plays:\n");
            get_score(score);
        }
        else
        {
            running = 0;
        }
    }
}