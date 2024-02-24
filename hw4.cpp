/***********************************************
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University’s Academic Integrity policy. Students are expected to
strictly avoid academic dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
All programming assignments in this class are to be done by the
student alone. No outside help is permitted except the instructor and
approved tutors.
I certify that the work submitted with this assignment is mine and was
generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.

Date: 2/8/2023
Name: Clyde Shtino
***********************************************/
#include <iostream>
#include <string>
using namespace std;



class ZipCode
{
    public: 
        ZipCode(); // default constructor
        ZipCode(int iZip); // zip copy constructor
        ZipCode(string newBar); // bar copy constructor

        int getZipCode(); // Obtains zip 
        string getBarCode(); // Obtains barcode

        void check_bar(string barCode); // Checks whether barcode is valid.

    private: 
        int zip; 
        string barcode; 
};


ZipCode::ZipCode()
{
    zip = 00000;
}

ZipCode::ZipCode(int iZip)
{
    int i[5] = {0};
    int num = 0;
    string code = "";
    int temp = iZip;

    while(iZip > 0) // In order to obtain digits of zip. 
    { 
        i[num] = iZip % 10;
        iZip /= 10;
        num++;
    }

    for(num = 4; num >= 0; num--)
    { 
        switch(i[num]) // Switch to randomize order of 1s and 0s.
        { 
            case 0:
                code = code + "11000";
                break;
            case 1:
                code = code + "00011";
                break;
            case 2:
                code = code + "00101";
                break;
            case 3:
                code = code + "00110";
                break;
            case 4:
                code = code + "01001";
                break;
            case 5:
                code = code + "01010";
                break;
            case 6:
                code = code + "01100";
                break;
            case 7:
                code = code + "10001";
                break;
            case 8:
                code = code + "10010";
                break;
            case 9:
                code = code + "10100";
                break;
            }
    }

    code.insert(0, "1"); // to insert the beginning and end of the barcode numbers
    code.insert(26, "1"); // numbers that range from 0 to 26
    zip = temp; 
    barcode = code; 

}

ZipCode::ZipCode(string newBar) // Obtains the new barcode
{
    check_bar(newBar);
    string temp = newBar;
    newBar = newBar.substr(1, newBar.length() - 2); 

    int a[5];
    int zip_code;
    int num = 0;

    for(int i = 0; i <= 20; i = i + 5)
    {
        string temp_a = newBar.substr(i, 5);
        
        //Static cast for encoding the barcode
        a[num] = (7 * (static_cast<int>(temp_a[0]) - 48)) + (4 * (static_cast<int>(temp_a[1]) - 48)) + (2 * (static_cast<int>(temp_a[2]) - 48)) + (1* (static_cast<int>(temp_a[3]) - 48));
        
        if(a[num] == 11)
        {
            a[num] = 0;
        }

        num++;
    }


    zip_code = 10000 * a[0]; // Obtains zip in the whole numbers
    zip_code = zip_code + 1000 * a[1]; // Iterates through the 1st index
    zip_code = zip_code + 100 * a[2]; // Iterates through the 2nd index
    zip_code = zip_code + 10 * a[3]; // Iterates through the 3rd index
    zip_code = zip_code + 1 * a[4]; // Iterates through the 4th index

    barcode = temp;
    zip = zip_code;

}

void ZipCode::check_bar (string barCode) // Checks whether barcode is valid.
{ 

    for(int i = 0; i < barCode.length(); i++)
    {

        if(barCode[i] != '0' && barCode[i] != '1')
        {
            cout << "Wrong barcode! A barcode can only contain '0' and '1'." << endl; 
            break;
        }

    }
}

int ZipCode:: getZipCode() //Obtains zip code
{ 
    return zip;
}

string ZipCode:: getBarCode() // Obtains barcode
{ 
    return barcode;
}



int main(int argc, char * argv[]) {
    ZipCode zip(99504),
    zip2("100101010011100001100110001"),
    zip3(12345),
    zip4(67890);
    
    cout << zip.getZipCode() << "'s bar code is '"
    << zip.getBarCode() << "'" << endl;
    cout << zip2.getZipCode() << "'s bar code is '"
    << zip2.getBarCode() << "'" << endl;
    cout << zip3.getZipCode() << "'s bar code is '"
    << zip3.getBarCode() << "'" << endl;
    cout << zip4.getZipCode() << "'s bar code is '"
    << zip4.getBarCode() << "'" << endl;
    
    cout << endl;
    
    // Test a range of values by first constructing a zip code
    // with an integer, then retrieving the bar code and using
    // that to construct another ZipCode.
    int zip_int = 0;
    for (int i = 0; i < 25; i++)
    {
        // Make an aribrary 5-digit zip code integer, and use it
        // to construct a ZipCode
        int five_digit_zip = (zip_int * zip_int) % 100000;
        ZipCode z1(five_digit_zip);
        
        // Construct a second ZipCode from the first's bar code
        string z1_barcode = z1.getBarCode();
        ZipCode z2(z1_barcode);
        
        cout.width(3);
        cout << (i + 1) << ": ";
        cout.width(5);
        cout << z2.getZipCode() << " has code '"
        << z1_barcode << "'";
        
        if ((z1_barcode == z2.getBarCode()) &&
            (z1.getZipCode() == z2.getZipCode()) &&
            (z2.getZipCode() == five_digit_zip))
        {
            cout << " [OK]" << endl;
        }
        else
        {
            cout << " [ERR]" << endl;
        }
        
        // Increment the test value arbitrarily
        zip_int += (233 + zip_int % 7);
    }
    cout << endl;
    
    // Test some error conditions. This test assumes that
    // ZipCode will simply set its value to a flag that indicates
    // an error, and will not exit the program.
    int BAD_ZIP_COUNT = 2;
    string bad_zips[][2] = {
        { "100101010011100001100110000", "bad start/end character" },
        { "100101010011100001100110021", "bad digit" },
    };
    for (int i = 0; i < BAD_ZIP_COUNT; i++)
    {
        cout << "Testing: " << bad_zips[i][1] << " " << bad_zips[i][0] << endl;
        ZipCode test(bad_zips[i][0]);
        cout << endl;
    }
    
    cout << "Enter a character to quit." << endl;
    char c;
    cin >> c;
    return 0;
}