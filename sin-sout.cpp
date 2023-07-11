#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

    string name = "";

    cout << "What is your name?" << endl;
    cin >> name;

    int age;
    cout << "And how old are you?" << endl;
    cin >> age;

    cout << name << ", you are " << age << " years old." << endl;
    cout << "That means, you are at least " << age * 365 << " days old!" << endl;

    return 0;
}
