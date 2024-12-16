#include<iostream>
#include <ctime>
#include<unistd.h>
#include<ostream>
#include <iomanip>


int getDayOfYear() {
    std::time_t now = std::time(nullptr);
    std::tm* now_tm = std::localtime(&now);
    std::tm start_of_year = *now_tm;
    start_of_year.tm_mon = 0;
    start_of_year.tm_mday = 1;
    std::time_t start_of_year_time = std::mktime(&start_of_year);
    double seconds_since_start_of_year = std::difftime(now, start_of_year_time);
    int day_of_year = static_cast<int>(seconds_since_start_of_year / (60 * 60 * 24));
    return day_of_year + 1;
}
int yearDays(int year) {
    int days = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? 366 : 365;
    return days;
}
int main()
{
    time_t now=time(0);
    tm *time=localtime(&now);
    if(time->tm_hour>=22){
        system("echo -e \033[32m夜深了请睡吧 \033[0m ");
    }
    std::cout<<"现在时间 ";
    std::cout << time->tm_year+1900 <<"年"<<time->tm_mon<<"月"<<time->tm_mday<<"日"<<std::endl;
    if(time->tm_hour>=12)
        std::cout<<"下午"<< time->tm_hour-12<<"时"<< time->tm_min<<"分"<<time->tm_sec<<"秒";
    else{
        std::cout<<"上午"<< time->tm_hour<<"时"<< time->tm_min<<"分"<<time->tm_sec<<"秒";
    }
    double endYearFraction = (yearDays(time->tm_year + 1900) - getDayOfYear()) / static_cast<double>(yearDays(time->tm_year + 1900));   
    std::cout << std::fixed << std::setprecision(3) << "今年还有" << endYearFraction << "%"<<std::endl;
    return 0;
}
