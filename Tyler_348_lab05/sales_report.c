#include <stdio.h>
#include <stdlib.h>

//Define number of months to be constant
#define MONTHS 12


void read_sales_data(const char *file_path, float sales[MONTHS]) {
    //Function that opens and reads data from file
    FILE *file = fopen(file_path, "r");


    for (int i = 0; i < MONTHS; i++) {
        //Loop that reads each line of data from file
        fscanf(file, "%f", &sales[i]);
        
    }
    fclose(file);
}

void month_sales(float sales[MONTHS]) {
    //Define all months as an array
    const char *months[MONTHS] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    printf("\nMonthly Sales\n");
    printf("%-10s %-10s\n", "Month", "  Sales");
    for (int i = 0; i < MONTHS; i++) {
        //Loop through all months and list the sales
        printf("%-10s %10.2f\n", months[i], sales[i]);
    }
}

void sales_stats(float sales[MONTHS]) {
    const char *months[MONTHS] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    int min_index = 0;
    int max_index = 0;
    for (int i = 1; i < MONTHS; i++) {
        //Loop to find the max sales for the year
        if (sales[i] > sales[max_index]) {
            //If the new index is larger than the current max: make a new max
            max_index = i;
        }
        if (sales[i] < sales[min_index]) {
            //If the new index is smaller than the current min: make a new min
            min_index = i;
        }
    }
    float total = 0;
    for (int i = 0; i < MONTHS; i++) {
        //Add all of the sales to total
        total += sales[i];
    }
    //Devide total by the number of months to find an average 
    float avg = total / MONTHS;
    //Print all of the data about sales 
    printf("\nSales Summary Report:\n");
    printf("Lowest sales: %s - %10.2f\n", months[min_index], sales[min_index]);
    printf("Highest sales: %s - %10.2f\n", months[max_index], sales[max_index]);
    printf("Average sales for all 12 months: %10.2f\n", avg);
}

void six_month_report(float sales[MONTHS]) {
    //Define all 6 month ranges in a year 
    const char *dates[7] = {
        "January-June", "February-July", "March-August", 
        "April-September", "May-October", "June-November", 
        "July-December"
    };

    printf("\nSix-Month Moving Average Report\n");
    for (int i = 0; i <= MONTHS - 6; i++) {
        //Loop through all months that can have a 6 month average 
        float total = 0;
        for (int j = 0; j < 6; j++) {
            //Find the sales in the next 6 month from the starting point
            total += sales[i + j];
        }
        //Print the 6 month earnings 
        printf("%-18s %.2f\n", dates[i], total / 6);
    }
}

void sorted_report(float sales[MONTHS]) {
    //Define all of the months 
    const char *months[MONTHS] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    //Make arrays for edited sales values and indexs
    float new_sales[MONTHS];
    int sorted_index[MONTHS];

    for (int i = 0; i < MONTHS; i++) {
        //Loop to copy sales data to new_sales
        new_sales[i] = sales[i];
        sorted_index[i] = i;
    }

    //Use selection sorting method 
    for (int j = 0; j < MONTHS; j++) {
        //Main loop
        int max_index = j;
        for (int i = j + 1; i < MONTHS; i++) {
            //Find max values 
            if (new_sales[i] > new_sales[max_index]) {
                //We found a new max
                max_index = i;
            }
        }
        //Values in the arrays to sort them
        float temp_sales = new_sales[j];
        new_sales[j] = new_sales[max_index];
        new_sales[max_index] = temp_sales;

        //Swap indexs to that we can track what months the sales happened in
        int temp_index = sorted_index[j];
        sorted_index[j] = sorted_index[max_index];
        sorted_index[max_index] = temp_index;
    }
    //Print the sales 
    printf("\nSales Report (Highest to Lowest)\n");
    printf("Month      | Sales\n");
    for (int i = 0; i < MONTHS; i++) {
        //Loop through our new sorted list and use the indexs to print what month the sales happend in
        printf("%-10s | $%.2f\n", months[sorted_index[i]], sales[sorted_index[i]]);
    }
}

int main() {
    //Define sales as array with values 0
    float sales[MONTHS] = {0};
    //Read from file
    read_sales_data("./Tyler_348_lab05/sales_data.txt", sales);
    //Call funtions that list facts about the data
    month_sales(sales);
    sales_stats(sales);
    six_month_report(sales);
    sorted_report(sales);
    return 0;
}
