#include "Convenient_strings.h"


int main() {

    char s[100];
	TString str1;
	std::cout << "Enter string: ";
	std::cin.getline(s, 100);

	// TString str2(s);
	// std::cout << std::endl << "str2 = " << str2;

	// TString str3(str2);
	// std::cout << std::endl << "str3 = " << str3;

	TString str2(s);
	TString str3(str2);
	TString str4 = str3 = str2;
	TString str5;
	str5 = str4 + str3;
	std::cout << "str1 = " << str1 << "\nstr2 = " << str2 << "\nstr3 = " << str3 << "\nstr4 = "
		<< str4 << "\nstr5 = " << str5;
	// if (str2 == str3)
	// 	std::cout << "\nEqual";                                       
	// else
	// 	std::cout << "\nNot equal";
	// if (str4 != str5)
	// 	std::cout << std::endl << "Not equal";
	// else
	// 	std::cout << std::endl << "equal";
	// if (str4 < str5)
	// 	std::cout << std::endl << "less";
	// if (str4 <= str5)
	// 	std::cout << std::endl << "less or equal";
	// if (str5 > str3)
	// 	std::cout << std::endl << "greater";
	// if (str4 >= str3)
	// 	std::cout << std::endl << "greater of equal";
	// std::cout << std::endl << (char*)str5;
    
}