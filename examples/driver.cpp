#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    // get the filename and number x from command line arguments
    string filename = argv[1];
    int x = stoi(argv[2]);

    // open the file for reading
    ifstream file(filename);

    // read each line (number) in the file
    int num;
    while (file >> num) {
        // add x to the number
        int new_num = num + x;
        // display the previous and updated numbers on the console
        cout << "Previous number: " << num << ", Updated number: " << new_num << endl;
    }

    // close the file
    file.close();

    return 0;
}