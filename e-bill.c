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
    do{
        system("cls");
        g(2, 2);p("Present reading: ");
        g(40, 2);p("Previous reading: ");
        g(2, 4);p("Present Counter: ");
        g(40, 4);p("Previous Counter: ");
        g(19, 2);s("%f", &present_reading);
        g(59, 2);s("%f", &previous_reading);
        g(19, 4);s("%f", &present_counter);
        g(59, 4);s("%f", &previous_counter);

        //this is the condition for [prev == pres]
        if (previous_reading == present_reading){
            if (previous_counter > present_counter){
                kwh_used_1 = (100 - previous_counter + present_counter - 1);
                kwh_used_2 = 1000 - (kwh_used_1 * 1000); //1000 - (kwh_used_1 x 1000)
                total_bill = kwh_per_hrs * kwh_used_2;
                g(2, 6);p("Kilowatt-hour used is: %0.2f", kwh_used_2);
                g(2, 7);p("Electric Bill is: %0.2f", total_bill);
            }
            else if (previous_counter == present_counter){
                kwh_used_1 = 0;
                kwh_used_2 = 0;
                total_bill = kwh_per_hrs * kwh_used_2;
                g(2, 6);p("Kilowatt-hour used is: %0.2f", kwh_used_2);
                g(2, 7);p("Electric Bill is: %0.2f", total_bill);
            }
            else if (previous_counter < present_counter){
                kwh_used_1 = (100 - present_counter + previous_counter - 1);
                kwh_used_2 = (kwh_used_1 * 1000) - 1000;
                total_bill = kwh_per_hrs * kwh_used_2;
                g(2, 6);p("Kilowatt-hour used is: %0.2f", kwh_used_2);
                g(2, 7);p("Electric Bill is: %0.2f", total_bill);
            }
        }
        //this is the condition for [prev > pres]
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
        //this is the condition for [pres > prev]
        if (previous_reading < present_reading){
            if (previous_counter < present_counter){
                kwh_used_1 = 100 - previous_counter + present_counter - 1;
                kwh_used_2 = (1000 - previous_reading + present_reading) + 100;
                total_bill = kwh_per_hrs * kwh_used_2;
                g(2, 6);p("Kilowatt-hour used is: %0.2f", kwh_used_2);
                g(2, 7);p("Electric Bill is: %0.2f", total_bill);
            }
            if (previous_counter > present_counter){
                kwh_used_1 = 100 - previous_counter + present_counter - 1;
                kwh_used_2 = (1000 - previous_reading + present_reading) + (kwh_used_1 * 1000);
                total_bill = kwh_per_hrs * kwh_used_2;
                g(2, 6);p("Kilowatt-hour used is: %0.2f", kwh_used_2);
                g(2, 7);p("Electric Bill is: %0.2f", total_bill);
            } 
            if (previous_counter == present_counter){
                kwh_used_1 = 100 - previous_counter + present_counter - 1;
                kwh_used_2 = (1000 - previous_reading + present_reading) + (kwh_used_1 * 1000);
                total_bill = kwh_per_hrs * kwh_used_2;
                g(2, 6);p("Kilowatt-hour used is: %0.2f", kwh_used_2);
                g(2, 7);p("Electric Bill is: %0.2f", total_bill);
            }
        }
        
        g(2, 8);p("Another Customer? Y/N: ");
        g(25, 8);s("%s", &ans);
         g(19, 2);p("                  ");
        g(59, 2);p("                   ");
        g(19, 4);p("                   ");
        g(59 , 4);p("                   ");
        g(20, 6);p("                     ");
        g(20, 7);p("                    ");
        g(20, 8);p("                    ");
    } while (ans == 'Y' || ans == 'y');  
    system("cls");
}

//kwhused_1 = (previous_reading - present_reading) + (present_counter * 1000) - (previous_counter * 1000);
//previous = (previous_counter * 1000 + previous_reading);
//present = (present_counter * 1000 + present_reading);
//kwhused = (previous - 100000 + present);
