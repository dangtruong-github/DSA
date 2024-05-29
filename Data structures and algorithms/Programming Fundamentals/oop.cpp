#include<iostream>
#include<string>
#include<cstring> // For strncpy

using namespace std;


/* 
    Declare a class, with public and private variables and behaviors
*/
class Country {
    private:
        char countryCode[3];
        string countryName;
        int area;
    public: 
        char* getCountryCode();
        bool setCountryCode(const char* newCountryCode);
};

/* 
    Define public and private behaviors
*/
char* Country::getCountryCode () {
    return this->countryCode;
};


bool Country::setCountryCode(const char* newCountryCode) {
    if (strlen(newCountryCode) != 2) {
        cout << "Length of new country code must be 2\n";
        return false;
    }

    strncpy(this->countryCode, newCountryCode, 2);
    this->countryCode[2] = '\0';

    return true;
};


int main () {
    cout << "\n\n";
    cout << "Peru\n";

    // Declare an object
    Country Peru;

    // Change object using its behavior(s)
    Peru.setCountryCode("peru");
    cout << Peru.getCountryCode() << endl;
    Peru.setCountryCode("pe");
    cout << Peru.getCountryCode() << endl;

    return 0;
}
