#include <windows.h>
#include <stdio.h>
#include <conio.h>
#define p printf
#define g gotoxy
#define s scanf

void gotoxy(int x,int y){
    COORD coord;
    coord.X = x - 1;
    coord.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(){
    float previous_reading , present_reading, present_counter, previous_counter;
    float kwh_used_1, kwh_used_2, kwh_used, total_bill;
    float past_bill, present_bill, kwh_per_hrs = 0.5;
    char ans;
    system("cls");
    do {
        g(2, 2);p("Present reading: ");
        g(2, 3);p("Previous reading: ");
        g(2, 4);p("Present Counter: ");
        g(2, 5);p("Previous Counter: ");
        g(20, 2);s("%f", &present_reading);
        g(20, 3);s("%f", &previous_reading);
        g(20, 4);s("%f", &present_counter);
        g(20, 5);s("%f", &previous_counter);
        if (previous_reading == present_reading){
            if (previous_counter > present_counter){
                kwh_used_1 = (100 - previous_counter + present_counter - 1);
                kwh_used_2 = (1000 - previous_reading + present_reading)+(kwh_used_1 * 1000);
                total_bill = kwh_per_hrs * kwh_used_2;
                g(2, 6);p("Kilowatt-hour used is: %0.2f", kwh_used_2);
                g(2, 7);p("Electric Bill is: %0.2f", total_bill);
            }
            else if (previous_counter == present_counter){
                kwh_used_1 = (100 - previous_counter + present_counter - 1);
                kwh_used_2 = (1000 - previous_reading + present_reading)+(kwh_used_1 * 1000);
                total_bill = kwh_per_hrs * kwh_used_2;
                g(2, 6);p("Kilowatt-hour used is: %0.2f", kwh_used_2);
                g(2, 7);p("Electric Bill is: %0.2f", total_bill);
            }
            else if (previous_counter < present_counter){
                kwh_used_1 = (100 - present_counter + previous_counter - 1);
                kwh_used_2 = (1000 - previous_reading + present_reading)+(kwh_used_1 * 1000);
                total_bill = kwh_per_hrs * kwh_used_2;
                g(2, 6);p("Kilowatt-hour used is: %0.2f", kwh_used_2);
                g(2, 7);p("Electric Bill is: %0.2f", total_bill);
            }
        }
        if (previous_reading > present_reading){
            if (previous_counter > present_counter){
                kwh_used_1 = (100 - previous_counter + present_counter - 1);
                kwh_used_2 = (1000 - previous_reading + present_reading)+(kwh_used_1 * 1000);
                total_bill = kwh_per_hrs * kwh_used_2;
                g(2, 6);p("Kilowatt-hour used is: %0.2f", kwh_used_2);
                g(2, 7);p("Electric Bill is: %0.2f", total_bill);
            }
            else if (previous_counter == present_counter){
                kwh_used_1 = (100 - previous_counter + present_counter - 1);
                kwh_used_2 = (1000 - previous_reading + present_reading)+(kwh_used_1 * 1000);
                total_bill = kwh_per_hrs * kwh_used_2;
                g(2, 6);p("Kilowatt-hour used is: %0.2f", kwh_used_2);
                g(2, 7);p("Electric Bill is: %0.2f", total_bill);;
            }
            else if (previous_counter < present_counter){
                kwh_used_1 = (100 - present_counter + previous_counter - 1);
                kwh_used_2 = (1000 - previous_reading + present_reading)+(kwh_used_1 * 1000);
                total_bill = kwh_per_hrs * kwh_used_2;
                g(2, 6);p("Kilowatt-hour used is: %0.2f", kwh_used_2);
                g(2, 7);p("Electric Bill is: %0.2f", total_bill);
            }
        }
        if (present_reading > previous_reading){
            if (previous_counter > present_counter){
                kwh_used_1 = (100 - previous_counter + present_counter - 1);
                kwh_used_2 = (1000 - present_reading + previous_reading )+(kwh_used_1 * 1000);
                total_bill = kwh_per_hrs * kwh_used_2;
                g(2, 6);p("Kilowatt-hour used is: %0.2f", kwh_used_2);
                g(2, 7);p("Electric Bill is: %0.2f", total_bill);
            }
            else if (previous_counter == present_counter){
                kwh_used_1 = (100 - previous_counter + present_counter - 1);
                kwh_used_2 = (1000 - present_reading + previous_reading)+(kwh_used_1 * 1000);
                total_bill = kwh_per_hrs * kwh_used_2;
                g(2, 6);p("Kilowatt-hour used is: %0.2f", kwh_used_2);
                g(2, 7);p("Electric Bill is: %0.2f", total_bill);
            }
            else if (previous_counter < present_counter){
                kwh_used_1 = (100 - present_counter + previous_counter - 1);
                kwh_used_2 = (1000 - present_reading + previous_reading) + (kwh_used_1 * 1000);
                total_bill = kwh_per_hrs * kwh_used_2;
                g(2, 6);p("Kilowatt-hour used is: %0.2f", kwh_used_2);
                g(2, 7);p("Electric Bill is: %0.2f", total_bill);
            }
        }
        g(2, 8);p("Another Customer? Y/N: ");
        g(30, 8);s("%s", &ans);
         g(20, 2);p("                  ");
        g(20, 3);p("                   ");
        g(20, 4);p("                   ");
        g(20 , 5);p("                   ");
        g(20, 6);p("                     ");
        g(20, 7);p("                    ");
    } while (ans == 'Y' || ans == 'y');  
    return(0);
}

//kwhused_1 = (previous_reading - present_reading) + (present_counter * 1000) - (previous_counter * 1000);
//previous = (previous_counter * 1000 + previous_reading);
//present = (present_counter * 1000 + present_reading);
//kwhused = (previous - 100000 + present);
