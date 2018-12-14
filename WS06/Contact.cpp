/* W06
* Contact.cpp
* Ivy Leano
*/

#include<iostream>
#include<string>
#include<cstring>
#include"Contact.h"

using namespace std;

namespace sict {

	bool sict::Contact::isValidPhoneNum(long long nums)
	{
		string tempNum = to_string(nums);
		int length = tempNum.length();

		bool invalidTwelveDigit = tempNum[0] == 0 && tempNum[2] == 0 && tempNum[5] == 0;
		bool invalidElevenDigit = tempNum[0] == 0 && tempNum[1] == 0 && tempNum[4] == 0;
		bool optionOne = !invalidTwelveDigit && length == 12;
		bool optionTwo = !invalidElevenDigit && length == 11;

		return (optionOne || optionTwo);
	}

	sict::Contact::Contact()
	{
		name[0] = '\0';
		phoneNumber = nullptr;
		amountPhoneNumber = 0;
	}

	sict::Contact::Contact(const char * names, const long long * phoneNumbers, int amountPhoneNumbers)
	{
		//To Store Valid Names
		if (names == nullptr || names[0] == ' ') 
		{
			name[0] = '\0';
		}
		else 
		{
			strncpy(name, names, MAX_CHAR);
			name[MAX_CHAR] = '\0';
		}

		if (!isEmpty() && phoneNumber != nullptr && amountPhoneNumber != 0) 
		{
			int count = 0;

			//To Set the amountPhoneNumber for Dynamic Memory Allocation
			for (int i = 0; i < amountPhoneNumbers; i++) 
			{
				if (isValidPhoneNum(phoneNumbers[i])) 
				{
					count++;
				}
			}
			//To Store Valid Phone Number Count (Setting amountPhoneNumber size)
			amountPhoneNumber = count;
			phoneNumber = new long long[amountPhoneNumber];

			int x = 0;

			//To Store Valid Phone Numbers to Dynamic array
			for (int i = 0; i < amountPhoneNumbers; i++) 
			{
				if (isValidPhoneNum(phoneNumbers[i])) 
				{
					phoneNumber[x] = phoneNumbers[i];
					x++;
				}
			}
		}
		else 
		{
			phoneNumber = nullptr;
			amountPhoneNumber = 0;
		}
	}

	sict::Contact::~Contact()
	{
		delete[] phoneNumber;
		phoneNumber = nullptr;
	}

	bool sict::Contact::isEmpty() const
	{
		bool empty = name[0] == '\0';
		return empty;
	}

	void Contact::display() const
	{
		if (!isEmpty()) 
		{
			int tempNumLength;
			string tempNum;
			string countryCode;
			string areaCode;
			string NN1;
			string NN2;

			cout << name << endl;

			for (int i = 0; i < amountPhoneNumber; i++) 
			{
				tempNum = to_string(phoneNumber[i]);
				tempNumLength = tempNum.length();

				if (tempNumLength == 12) 
				{
					countryCode = tempNum.substr(0, 2);
					areaCode = tempNum.substr(2, 3);
					NN1 = tempNum.substr(5, 3);
					NN2 = tempNum.substr(8, tempNumLength);

					cout << "(+" << countryCode << ") " << areaCode << " " << NN1 << "-" << NN2 << endl;
				}
				if (tempNumLength == 11) 
				{
					countryCode = tempNum.substr(0, 1);
					areaCode = tempNum.substr(1, 3);
					NN1 = tempNum.substr(4, 3);
					NN2 = tempNum.substr(7, tempNumLength);
					cout << "(+" << countryCode << ") " << areaCode << " " << NN1 << "-" << NN2 << endl;
				}
			}
		}
		else 
		{
			cout << "Empty contact!" << endl;
		}
	}

	Contact::Contact(const Contact & contact)
	{
		phoneNumber = nullptr;
		*this = contact;
	}

	Contact & Contact::operator=(const Contact & contact)
	{
		if (this != &contact) {
			amountPhoneNumber = contact.amountPhoneNumber;
			strncpy(name, contact.name, MAX_CHAR);
			name[MAX_CHAR] = '\0';

			delete[] phoneNumber;

			if (contact.phoneNumber != nullptr) 
			{
				phoneNumber = new long long[amountPhoneNumber];
				for (int i = 0; i < amountPhoneNumber; i++) 
				{
					phoneNumber[i] = contact.phoneNumber[i];
				}
			}
			else
			{
				phoneNumber = nullptr;
			}
		}
		return *this;
	}

	Contact & Contact::operator+=(long long newPhoneNum)
	{
		if (isValidPhoneNum(newPhoneNum)) 
		{
			amountPhoneNumber++;
			long long* newPhoneNumber = nullptr;
			newPhoneNumber = new long long[amountPhoneNumber];

			for (int i = 0; i < amountPhoneNumber - 1; i++) 
			{
				newPhoneNumber[i] = phoneNumber[i];
			}
			newPhoneNumber[amountPhoneNumber - 1] = newPhoneNum;

			delete[] phoneNumber;
			phoneNumber = newPhoneNumber;
		}
		return *this;
	}
}