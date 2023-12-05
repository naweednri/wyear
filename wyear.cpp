#include <ctime>
#include <iostream>
#include <string>
#include <chrono>

using namespace std;

using day=std::chrono::day;

void getWeekOfYear(std::time_t time)
{
    char timeString[std::size("ww")];
    strftime(std::data(timeString), std::size(timeString),
                "%W", std::gmtime(&time));
    cout << timeString << '\n';
}

void Option()
/*
two option:
            1-hit enter to use current time
            2-pass date as parameter
*/
{
    string time;
    getline(cin, time);
    if(time=="")
    {
        std::time_t time=std::time({});
        getWeekOfYear(time);
    }
    else
    {

        string delimiter = "/";
        int pos1=time.find(delimiter);
        int year = stoi(time.substr(0,pos1));
        int pos2=time.find(delimiter,pos1+1);
        int month=stoi(time.substr(pos1+1,pos2-pos1-1));
        int day=stoi(time.substr(pos2+1));
        //cout<<pos1<<endl<<pos2<<endl<<year<<endl<<month<<endl<<day<<endl;
        tm tm{};
        tm.tm_year = year - 1900; 
        tm.tm_mon = month - 1; 
        tm.tm_mday = day; 
        time_t t = std::mktime(&tm);
        getWeekOfYear(t); 
    }
}

int main()
{
    cout<<std::chrono::system_clock::now()<<std::endl;
    cout<<"[This app get you week of year]\nPress enter to use current time\nOtherwise use this format to enter your date: yyyy/mm/dd \n";
    Option();

    return 0;
}
