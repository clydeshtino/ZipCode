# ZipCode 
# By: Clyde Shtino

# About 
This C++ code defines a class ZipCode that represents a zip code and its corresponding barcode utilziing constructors. 

# Default constructor 
The default constructor's role is to intialize the zip code to "0000"

# Constructor ZipCode(int iZip)
ZipCode(int iZip) takes an integer "iZip" which represents the zip code and generates the corresponding barcode

# Constructor ZipCode(string newBar)
Ths construcot takes a string "newBar" which represents the barcode and decodes it to obtain the zipcode.

# Main routine
In main, several ZipCode objects are formed with different ZipCodes and barcodes using constructors. The zip code and barcode of each objec are then printed, and as a result a range of values is tested by constructings ZipCode objects with integer zip codes and then reconstructing them from the obtained barcodes to ensure their correct. 