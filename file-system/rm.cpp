#include <iostream>
#include <fstream>
#include <print.h>
#include <print.cpp>

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        string commandUsed(argv[0]);

        // output usage
        print("\x1B[1m"
              "Usage:"
              "\x1B[0m");
        print("\t" +
              commandUsed +
              " <file to delete>");
        print("\t"
              "Please do not use on folders, behavior untested!");
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        string file(argv[i]);

        ifstream fileCheck(file);
        if (!fileCheck.good())
        {
            print("\x1B[31m"
                  "\x1B[1m"
                  "Skipping file "
                  "\x1B[22m" +
                  file + "\x1B[0m");
            fileCheck.close();
            continue;
        }
        fileCheck.close();

        print("\x1B[1m"
              "removing file "
              "\x1B[22m" +
              file + "\x1B[0m");
        remove(file.c_str());
        print("\x1B[32m"
              "\x1B[1m"
              "successfully removed file "
              "\x1B[22m" +
              file + "\x1B[0m");
    }

    return 0;
}
