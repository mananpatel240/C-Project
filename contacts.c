//==============================================
// Name:           Manan Patel

// Student Number: 148603194
// Email:          mspatel45@myseneca.ca
// Section:        NYY
// Date:           03/12/2020
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

void getName(struct Name* name)
{
    
    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]%*c", name->firstName);
    printf("Do you want to enter a middle initial(s)? (y or n): ");
    if (yes())
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]", name->middleInitial);
        clearKeyboard();
       
    }
    else
    {
        name->middleInitial[0] = '\0';
    }
    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]%*c", name->lastName);
}

void getAddress(struct Address* address)
{
    printf("Please enter the contact's street number: ");
    address->streetNumber = getInt();
    while (address->streetNumber < 0)
    {
        printf("*** INVALID STREET NUMBER *** <must be a positive number>: "
        );
        address->streetNumber = getInt();
    }
    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]%*c", address->street);
    printf("Do you want to enter an apartment number? (y or n): ");
    if (yes())
    {
        printf("Please enter the contact's apartment number: ");
        address->apartmentNumber = getInt();
        while (address->apartmentNumber < 0)
        {
            printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            address->apartmentNumber = getInt();
        }
    }
    else
    {
        address->apartmentNumber = '\0';
    }
    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]", address->postalCode);
    clearKeyboard();
    printf("Please enter the contact's city: ");
    scanf("%40[^\n]%*c", address->city);
}

void getNumbers(struct Numbers* numbers)
{
    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbers->cell);
    printf("Do you want to enter a home phone number? (y or n): ");
    if(yes())
    {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(numbers->home);
       
    }
    else
    {
        numbers->home[0] = '\0';
    }
    printf("Do you want to enter a business phone number? (y or n): ");
    if(yes())
    {
        //clearKeyboard();
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(numbers->business);
        
    }
    else
    {
        numbers->business[0] = '\0';
    }
}

void getContact(struct Contact* contact)
{
    struct Contact contact1;
    getName(&contact1.name);
    getAddress(&contact1.address);
    getNumbers(&contact1.numbers);
    *contact = contact1;
}