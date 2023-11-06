#include <iostream>
#include <string>
#include <cctype>

void lunaAlgorithm (std::string cardNumber)
{
    int sizeCardNumber = cardNumber.length();
    int cardNumbers[sizeCardNumber];
    int totalSum = 0; 

    for (int i = 0; i < sizeCardNumber; i += 1)
    {
       char charset = cardNumber[i];

       if (isdigit(charset))
       {
            int digit = charset - '0';
            cardNumbers[i] = digit; 
       }
       else continue;
    }

    for (int i = sizeCardNumber - 2; i >= 0; i -= 2)
    {
        int sum = cardNumbers[i] * 2; 

        if (sum >= 9)
            sum -= 9;  

        totalSum += sum;
    }

    for (int i = sizeCardNumber - 1; i >= 0; i -= 2)
    {
        int digit = cardNumber[i] - '0'; 
        totalSum += digit; 
    }

    if (totalSum % 10 == 0) 
        std::cout << "\033[32m" 
                  << "The card is being validated..." 
                  << "\033[0m" << std::endl;
    else 
        std::cout << "\033[31m" 
                  << "This card is not validated..." 
                  << "\033[0m" << std::endl;
}

int main ()
{   
    std::string cardNumber;

    do 
    {
        std::string cardNumber;
        std::cout << "Enter your card number: ";
        getline(std::cin, cardNumber);

        if (cardNumber.length() == 16) 
        {
            if (cardNumber[0] == '4') 
            {
                std::cout << "Visa\n";
            } 
            else if (cardNumber[0] == '5') 
            {
                std::cout << "Mastercard\n";
            } 
      
            lunaAlgorithm(cardNumber);
            break;
        } 
        else if (cardNumber.length() >= 16) 
        {
            std::cout << "Card number is too long. Please try again.\n";
        } 
        else 
        {
            std::cout << "Card number is too short. Please try again.\n";
        }

    } while (true); 
}