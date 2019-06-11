#include <iostream>
#include <string>
#include <time.h>

/*
 * Class for calculating seconds passed since birthday
 *
 * @Author Michal Nawrocki
 * @Date 11th of June 2019
 */
class AgeCalculator{
public:
    static double calculateAge(){
        int birth_day = 0;
        int birth_month = 0;
        int birth_year = 0;
        double secondsDiff = 0;
        std::string birthDate;

        // Get birthday from stdin
        std::cout << "Please provide your birthday in the format <DD:MM:YYYY> : ";
        std::cin >> birthDate;
        std::cout << std::endl;

        birth_day = stoi(birthDate.substr(0,2), nullptr, 10);
        birth_month = stoi(birthDate.substr(3,2), nullptr, 10);
        birth_year = stoi(birthDate.substr(6,4), nullptr, 10);

        // Convert to appropriate struct
        tm tm_birthday = getTimeStruct(birth_day, birth_month, birth_year);

        // Calculate difference
        secondsDiff = getDiffSeconds(tm_birthday);

        return secondsDiff;
    }

private:
    static tm getTimeStruct(int birth_day, int birth_month, int birth_year){
        struct tm tm_birthDate = {0};

        // Set the Hour, Min, Sec values to 0;
        tm_birthDate.tm_hour = 0;
        tm_birthDate.tm_min = 0;
        tm_birthDate.tm_sec = 0;

        // Convert input to given format;
        tm_birthDate.tm_year = birth_year - 1900;
        tm_birthDate.tm_mon = birth_month - 1;
        tm_birthDate.tm_mday = birth_day;

        return tm_birthDate;
    }

    static double getDiffSeconds(tm birthDate){
        double seconds = 0;
        time_t timer;

        // Init time
        time(&timer);

        // Calculate difference
        seconds = difftime(timer, mktime(&birthDate));

        return seconds;
    }
};


int main() {

    double seconds = AgeCalculator::calculateAge();

    std::cout << "Since your birthday " << seconds << " seconds have passed" << std::endl;

    return 0;
}