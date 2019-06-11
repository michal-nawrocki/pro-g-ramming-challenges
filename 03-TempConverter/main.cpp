#include <iostream>

/*
 * Class for converting between different temperature scales
 *
 * @Author Michal Nawrocki
 * @Date 11th of June 2019
 */
class TempConverter{

public:
    static float celsToFahr(float cel){
        float result = 0.0;

        result = cel * 1.8f + 32.0f;


        return result;
    };

    static float celsToKel(float cel){
        float result = 0.0f;

        result = cel + 273.15f;

        return result;
    }

    static float fahrToCels(float fahr){
        float result = 0.0f;

        result = (fahr - 32.0f) * (5.0f / 9.0f);

        return result;
    };

    static float fahrToKel(float fahr){
        float result = 0.0f;

        result = fahrToCels(fahr);
        result = celsToKel(result);

        return result;
    }

    static float kelToCels(float kel){
        float result = 0.0f;

        result = kel - 273.15f;

        return result;
    }

    static float kelToFahr(float kel){
        float result = 0.0f;

        result = kelToCels(kel);
        result = celsToFahr(result);

        return result;
    }
};


int main() {

    bool running = 1;
    int option = -1;
    float toConvert = 0.0;

    // Main loop allowing to convert multiple temperatures one after the other
    while(running){
        std::cout << "Select which conversion you want to perform" << std::endl;
        std::cout << "Celsius to Fahrenheit (1), Fahrenheit to Celsius (2), Celsius to Kelvin (3)" << std::endl;
        std::cout << "Kelvin to Celsius (4), Fahrenheit to Kelvin (5), Kelvin to Fahrenheit (6): " << std::endl;
        std::cin >> option;
        std::cout << std::endl;

        if(option < 1 || option > 6){
            std::cout << "Wrong input, Closing!";
            exit(0);
        }

        std::cout << "Provide the temperature you want to convert: ";
        std::cin >> toConvert;
        std::cout << std::endl;

        switch(option){
            case 1:
              toConvert = TempConverter::celsToFahr(toConvert);
                break;
            case 2:
              toConvert = TempConverter::fahrToCels(toConvert);
                break;
            case 3:
              toConvert = TempConverter::celsToKel(toConvert);
                break;
            case 4:
              toConvert = TempConverter::kelToCels(toConvert);
                break;
            case 5:
              toConvert = TempConverter::fahrToKel(toConvert);
                break;
            case 6:
              toConvert = TempConverter::kelToFahr(toConvert);
                break;
            default:
                break;
        }

        std::cout << "The converted temperature is: " << toConvert << std::endl;

        std::cout << "Do you want to convert more? Yes (1), No (2)?" << std::endl;
        std::cin >> option;

        if(option == 1){
            continue;
        }else{
            break;
        }
    }

    return 0;
}