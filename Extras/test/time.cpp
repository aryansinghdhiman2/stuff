#include <iostream>
#include <ctime>
#include "example.cpp"
using namespace std;

int main() 
{
   // current date and time on the current system
   time_t now = time(0);
   say_hello();
   // convert now to string form
   char* date_time = ctime(&now);

   cout << "The current date and time is: " << date_time << endl;
}