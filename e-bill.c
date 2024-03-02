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

int main (){
    float previous_reading , present_reading, present_counter, previous_counter;
    float kwh1, kwh2, kwh, total_bill;
    float past_bill, present_bill, kwh_per_hrs = 0.5;
    float prev, pres;
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
       
        //1.1
        if (present_reading == previous_reading){
            if (present_counter == previous_counter){
                kwh1 = 0;
                kwh2 = 0;
                total_bill = 50;
                g(2, 6);p("Kilowatt-hour used is: %0.2f", kwh2);
                g(2, 7);p("Electric Bill is: %0.2f", total_bill);
            }//1.2
            else if (present_counter > previous_counter){
                prev = previous_counter * 1000 + previous_reading;
                pres = present_counter * 1000 + present_reading;
                kwh1 = pres - prev;
                total_bill = 50;
                g(2, 6);p("Kilowatt-hour used is: %0.2f", kwh1);
                g(2, 7);p("Electric Bill is: %0.2f", total_bill);
            }//1.3
            else if (present_counter < previous_counter){
                prev = previous_counter * 1000 + previous_reading;
                pres = present_counter * 1000 + present_reading;
                kwh1 = 100000 - (prev + pres);
                total_bill = 50;
                g(2, 6);p("Kilowatt-hour used is: %0.2f", kwh1);
                g(2, 7);p("Electric Bill is: %0.2f", total_bill);
            }
        }
        //2.1
        if (present_reading > previous_reading){
            if (present_counter == previous_counter){
                prev = previous_counter * 1000 + previous_reading;
                pres = present_counter * 1000 + present_reading;
                kwh1 = pres - prev;
                total_bill = 50;
                g(2, 6);p("Kilowatt-hour used is: %0.2f", kwh1);
                g(2, 7);p("Electric Bill is: %0.2f", total_bill);
            }
            else if(present_counter > previous_counter){
                prev = previous_counter * 1000 + previous_reading;
                pres = present_counter * 1000 + present_reading;
                kwh1 = pres - prev;
                total_bill = kwh1 * 0.50;
                g(2, 6);p("Kilowatt-hour used is: %0.2f", kwh1);
                g(2, 7);p("Electric Bill is: %0.2f", total_bill);
            }
            if (previous_counter > present_counter){
                prev = previous_counter * 1000 + previous_reading;
                pres = present_counter * 1000 + present_reading;
                kwh1 = 100000 - (previous_counter * 1000) + pres;
                total_bill = kwh1 * 0.50;
                g(2, 6);p("Kilowatt-hour used is: %0.2f", kwh1);
                g(2, 7);p("Electric Bill is: %0.2f", total_bill);
            }
        }
        //3.1
        if (present_reading < previous_reading){
            if (present_counter == previous_counter){
                prev = previous_counter * 1000 + previous_reading;
                pres = present_counter * 1000 + present_reading;
                kwh1 = 100000 - prev;
                total_bill = kwh1 * 0.50;
                g(2, 6);p("Kilowatt-hour used is: %0.2f", kwh1);
                g(2, 7);p("Electric Bill is: %0.2f", total_bill);
            }
            else if (present_counter > previous_counter){
                prev = previous_counter * 1000 + previous_reading;
                pres = present_counter * 1000 + present_reading;
                kwh1 = pres - prev;
                total_bill = kwh1 * 0.50;
                g(2, 6);p("Kilowatt-hour used is: %0.2f", kwh1);
                g(2, 7);p("Electric Bill is: %0.2f", total_bill);
            }
            else if (present_counter < previous_counter){
                prev = previous_counter * 1000 + previous_reading;
                pres = present_counter * 1000 + present_reading;
                kwh1 = 100000 - prev;
                total_bill = kwh1 * 0.50;
                g(2, 6);p("Kilowatt-hour used is: %0.2f", kwh1);
                g(2, 7);p("Electric Bill is: %0.2f", total_bill);
            }
        }

        g(2, 8);p("Another Customer? Y/N: ");
        g(25, 8);s("%s", &ans);
        g(19, 2);p("                   ");
        g(59, 2);p("                   ");
        g(19, 4);p("                   ");
        g(59 , 4);p("                  ");
        g(20, 6);p("                   ");
        g(20, 7);p("                   ");
        g(20, 8);p("                   ");
    } while (ans == 'Y' || ans == 'y');
}
