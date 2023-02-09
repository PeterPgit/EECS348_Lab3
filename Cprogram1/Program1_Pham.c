#include <stdio.h>
#include <cstdlib>
#include <string.h>


float *read_file(const char *file_name)
{
    float *month_sales_data = (float*)malloc(sizeof(float) * 12);
    FILE *fp = fopen(file_name, "r+");
    if (fp == NULL)
    {
        printf("Incorrect/incompatible input file.");
    }


    for (int i = 0; i<12; i++)
    {
        fscanf(fp, "%f\n", &month_sales_data[i]);
    }
    return month_sales_data;
}



int main()
{
    float *month_sales_data = read_file("input.txt");
    char month_names[13][16] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    float sales_avg;


    // print monthly sales report
    printf("Monthly sales report for 2022:\n\nMonth\t\tSales\n");
    for (int i = 0; i < 12; i++)
    {
        // if statement in order to fix formatting of month name with <8 chars
        if (strlen(month_names[i]) <=7)
        {
            printf("%s\t\t%.2f\n", month_names[i], month_sales_data[i]);
        }
        else
        {
            printf("%s\t%.2f\n", month_names[i], month_sales_data[i]);
        }
        
    }



    // print Sales summary
    float total_sales = 0;
    int min_sale_index = 0, max_sale_index = 0;

    printf("\n\nSales Summary: \n\n");

    for (int i = 0; i < 12; i++)
        {
            // Min sales data
            if (month_sales_data[i] < month_sales_data[min_sale_index])
            {
                min_sale_index = i;
            }

            // Max sales data
            if (month_sales_data[i] > month_sales_data[max_sale_index])
            {
                max_sale_index = i;
            }

            // Total sales amount for calculating avg
            total_sales = total_sales + month_sales_data[i];
        }

    printf("Minimum sale: \t%.2f (%s)\n", month_sales_data[min_sale_index], month_names[min_sale_index]);
    printf("Maximum sales: \t%.2f (%s)\n", month_sales_data[max_sale_index], month_names[max_sale_index]);
    printf("Average sales: \t%.2f\n", total_sales/12);



    // print Six-Month moving average report
    printf("\n\nSix-Month moving average report:\n\n");

    // loops through offsets to get avg
    for (int i = 0; i < 7; i++)
    {
        float six_month_total = 0;

        // loops through 6 month data
        for (int j = 0; j < 6; j++)
        {
            six_month_total = six_month_total + month_sales_data[j + i];
        }
        printf("%s-%s\t%.2f\n", month_names[i], month_names[5 + i], six_month_total/6);
    }



    // print Sales report (highest to lowest)
    int high_to_low_sales_index[12];
    
    high_to_low_sales_index[0] = max_sale_index;
    int upper_threshold = max_sale_index, lower_threshold = min_sale_index, next_smallest = 0;



    // loops through all months
    for (int i = 1; i < 12; i++)
    {
        next_smallest = min_sale_index;
        // loops to compare other month sale values to current index month's sale value
        for (int j = 0; j < 12; j++)
        {
            if (month_sales_data[j] < month_sales_data[upper_threshold] && month_sales_data[j] > month_sales_data[next_smallest])
            {
                next_smallest = j;
            }
        }
        high_to_low_sales_index[i] = next_smallest;
        upper_threshold = next_smallest;
    }

    printf("\n\nSales report (highest to lowest):\n\nMonth\t\tSales\n");
    for (int i = 0; i < 12; i++)
    {
        // if statement in order to fix formatting of month name with <8 chars
        if (strlen(month_names[high_to_low_sales_index[i]]) <=7)
        {
            printf("%s\t\t$%.2f\n", month_names[high_to_low_sales_index[i]], month_sales_data[high_to_low_sales_index[i]]);
        }
        else
        {
            printf("%s\t$%.2f\n", month_names[high_to_low_sales_index[i]], month_sales_data[high_to_low_sales_index[i]]);
        }
    }
    return 0;
}

