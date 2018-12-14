/* W06
* Contact.h
* Ivy Leano
*/

#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict
{
	const int MAX_CHAR = 20;

	class Contact 
	{
		char name[MAX_CHAR + 1];
		long long * phoneNumber;
		int amountPhoneNumber;
		bool isValidPhoneNum(long long num);

	public:

		Contact();
		Contact(const char * names, const long long * phoneNumbers, int amountPhoneNumbers);
		~Contact();
		bool isEmpty() const;
		void display() const;
		Contact(const Contact& contact);
		Contact& operator=(const Contact& contact);
		Contact& operator+=(long long newPhoneNum);
	};
}

#endif // !



