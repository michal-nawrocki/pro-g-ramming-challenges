#include <iostream>
#include <vector>
#include <random>
#include <time.h>


/*
 * Class for generating Names with a static method
 *
 * @Author Michal Nawrocki
 * @Date 4th of June 2019
 */
class NameGenerator{
public:
    static std::string generateName(){
        srand(time(NULL));
        int rand_last = (rand() % (size_lastNames-1));
        int rand_first = (rand() % size_firstNames);

        return NameGenerator::firstNames[rand_first] + " " + lastNames[rand_last];
    }
private:
    const static int size_firstNames = 10;
    const static int size_lastNames = 10;

    const static std::string firstNames[size_firstNames];
    const static std::string lastNames[size_lastNames];

};

const std::string NameGenerator::firstNames[] = {"Tom", "Jacob", "Michael", "Richard", "Chad",
                             "Kyle", "Eric", "Peter", "Olivia", "Riley"};

const std::string NameGenerator::lastNames[] = {"Jackson", "Kowalski", "Smith", "Batten", "King",
                                  "Sanchez", "Tompson", "Lee", "Downey", "Ericson"};


int main() {
    std::cout << "The name for you is: " << NameGenerator::generateName() <<  std::endl;
    return 0;
}