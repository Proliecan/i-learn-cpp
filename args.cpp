#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << argc << " arguments found!" << endl;
    
    for (int i = 0; i < argc; i++)
    {
        cout << argv[i] << endl;
    }
    
    
    return 0;
}
