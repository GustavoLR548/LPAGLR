#include<iostream>
#include<cstdint>

int numberOfLedsRequired(std::string input);

int main() {
    
    uint16_t n;
    std::string input;

    std::cin >> n;
    
    for(uint16_t i = 0; i < n; i++) {

        std::cin >> input;

        std::cout << numberOfLedsRequired(input) << " leds" << std::endl;
    }


    return 0;
}

int numberOfLedsRequired(std::string input) {

    int result = 0;

    for(uint16_t i = 0; i < input.length(); i++) 
        switch(input.at(i)) {
            case '1':
                result += 2;
                break;
            case '2':
                result += 5;
                break;
            case '3':
                result += 5;
                break;
            case '4':
                result += 4;
                break;
            case '5':
                result += 5;
                break; 
            case '6':
                result += 6;
                break; 
            case '7':
                result += 3;
                break; 
            case '8':
                result += 7;
                break; 
            case '9':
                result += 6;
                break;
            case '0':
                result += 6;
                break;
            default:
                break;
                
        }
    

    return result;
}