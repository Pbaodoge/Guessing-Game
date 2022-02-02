#include <iostream>
#include <fstream>
#include <cmath>
#include <windows.h>

    int number = 0, inp = 1, low, high, tries = 0;

     int main(){
         std::ofstream logger;
         logger.open("guessing.log");
         std::cout << "This is a guessing game!" << std::endl;
         std::cout << "Please choose your limit : ";
         std::cin >> low >> high;
         system("cls");
         logger << "User entered : " << low << " and " << high << std::endl;
         while(inp != number){
         //revert the numbers if the user entered the higher value than the second number
         if(low > high){
             int temp = high; 
             high = low;
             low = temp;
               logger << "The program revert the number to : " << low << " and " << high << std::endl << "\n";
               number = rand() % low + high;
               logger << "Program generated : " << number << std::endl << "\n\n";
               std::cout << "Now guess the number from " << high << " to " << low << " : ";
               std::cin >> inp;
               tries++;
               logger << "Player entered : " << inp << std::endl;
               system("cls");
         }

         else{
               number = rand() % high + low;
               logger << "Program generated : " << number << std::endl << "\n\n";
               std::cout << "Now guess the number from " << low << " to " << high << " : ";
               std::cin >> inp;
               tries++;
               logger << "Player entered : " << inp << std::endl;
         }

         if(inp == number){
             system("cls");
             std::cout << "Congrats, you guessed the number in " << tries << " tries!" << std::endl;
             std::cout << "The guessed number is : " << number;
             logger << "\nPlayer guessed the number " << number << " in " << tries << " tries." << std::endl;
             break;
         }
         else{
           std::cout << "Please try again!" << std::endl;
           logger << "Player entered " << inp << " which is the wrong number.\n" << std::endl;
           
         } 

     }

     return 0;
 }