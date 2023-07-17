#include <iostream>
#include <fstream>

using namespace std;

void print(string string)
{
    cout << string << endl;
}

int main(int argc, char const *argv[])
{

    // second argv is filenae to read
    if (argc < 2)
    {

        // print usage
        print("FILE-READING IS ONLY A TEST PROGRAM!");
        print("PLEASE USE 'cat' INSTEAD!");

        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        string filename(argv[i]);

        ifstream file;
        file.open(filename);

        if (!file.is_open())
        {
            // print file error and continue
            print("\x1B[31m\x1B[4m"
                  "FILE ERROR: " +
                  filename + " cannot be opened!\x1B[0m");
            continue;
        }

        // print an empty line
        cout << endl;

        // print heading
        cout << "\x1B[4m"
             << "\x1B[1m"
             << "\x1B[3" << (i % 5) + 1 << "m" << filename << ":"
             << "\x1B[0m" << endl;

        // print an empty line
        cout << endl;

        // print contents
        string line;
        while (getline(file, line))
        {
            print("\t" + line);
        }
        // print an empty line
        cout << endl;
    }

    return 0;
}
