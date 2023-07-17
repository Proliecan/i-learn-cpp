#include <iostream>
#include <fstream>
#include <./print.h> // Remeber to compile with `g++ file-writing.cpp print.cpp -I . -o file-writing`!

using namespace std;

int main(int argc, char const *argv[])
{
    // arg1: path to ifile
    // arg2: path to ofile
    // objective: write content of ifile to ofile

    if (argc < 3)
    {
        // print usage

        string commandUsed(argv[0]);

        print("\x1B[4m\x1B[1m"
              "Copy file");
        print("\x1B[24m\x1B[22m"
              "Usage:"
              "\t"
              "\x1B[31m" +
              commandUsed + " <source> <destination>\x1B[0m");
        return 1;
    }

    string source(argv[1]), dest(argv[2]);

    ifstream sourceFile(source);
    if (!sourceFile.is_open())
    {
        print("\x1B[31m"
              "Error reading source file " +
              source + "!");
        return 1;
    }

    ifstream destCheck(dest);
    if (destCheck.good())
    {
    question:
        print("The destination file " + dest + "already exists.");
        cout << "Do you really want to proceed and overwrite it? "
                "(y/n):"
                " ";
        char answer;
        cin >> answer;
        if (answer == 'n')
        {
            print("abort");
            return 1;
        }
        if (answer != 'y')
        {
            print("Please answer with 'y' for yes and 'n' for no!");
            goto question;
        }
    }

    ofstream destFile(dest, ios::trunc);
    if (!destFile.is_open())
    {
        print("\x1B[31m"
              "Error writing destination file " +
              dest + "!");
        return 1;
    }

    // copy contents to destFile
    string line;
    while (getline(sourceFile, line))
    {
        destFile << line << endl;
    }

    sourceFile.close();
    destFile.close();

    return 0;
}
