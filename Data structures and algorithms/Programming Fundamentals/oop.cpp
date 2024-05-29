#include<iostream>
#include<string>
#include<cstring> // For strncpy

using namespace std;


class Country {
    private:
        char countryCode[3];
        string countryName;
        int area;
    public: 
        char* getCountryCode();
        bool setCountryCode(char* newCountryCode);
};


char* Country::getCountryCode () {
    return this->countryCode;
};


bool Country::setCountryCode(char* newCountryCode) {
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

    Country Peru;
    Peru.setCountryCode("peru");
    cout << Peru.getCountryCode() << endl;
    Peru.setCountryCode("pe");
    cout << Peru.getCountryCode() << endl;

    return 0;
}
