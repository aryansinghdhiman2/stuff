#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

int main()
{
    int day,month,year;
    cout<<"Enter Day,Month and Year from which you want number of days(divide by spaces)"<<endl;
    cin>>day>>month>>year;

    tm input_time={0};//declare a struct tm which holds information about time
    input_time.tm_mday=day;//add input date into input_time struct
    input_time.tm_mon=month-1;
    input_time.tm_year=year-1900;

    time_t converted_input_time=mktime(&input_time);//convert the struct into time_t variable which holds number of seconds passed till epoch

    time_t current_time=time(0);//get current time
    tm current={};
    tm* current_ptr=&current;//make a pointer to struct tm
    current_ptr=gmtime(&current_time);//convert time_t to tm struct 
    current_ptr->tm_hour=current_ptr->tm_min=current_ptr->tm_sec=0;//set hours,seconds and minutes to 0 (as they will interfere with calculations)
    current_time=mktime(current_ptr);//convert tm struct to time_t 

    int number_of_days=(int)((converted_input_time-current_time)/86400);//find difference in number of seconds and convert it into days
    cout<<"The number of days between today and the inputted date is : "<<number_of_days;

    return 0;
}