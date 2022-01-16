#include <iostream>
#include <string>
using namespace std;

/**
* PURPOSE:
*   compare software two versions to determine which is the latest
* PARAMETER:
*   input two strings consisting of major#.minor#.revision# or more
* RETURN VALUE
*   -1 if ver1 is greater, 1 if ver2 is greater, or 0 if they're equal
*/

// note for me: need to come back and refactor; could make some fuctions to replace the multi function calls
int compareVersions(string ver1, string ver2)
{
    string strCounter = ver1 + ver2;

    while (strCounter != "")
    {
        // begin check of similar version comparisions
        if (ver1 == "" && ver2 == "")
        {
            return 0;
        }
        else if (ver1[0] == '.' && ver2[0] == '.')
        {
            ver1.erase(0, 1);
            ver2.erase(0, 1);
        }
        else if (ver1.find(".") > 0 && ver2.find(".") > 0)
        {
            if(stoi(ver1.substr(0, ver1.find("."))) > stoi(ver2.substr(0, ver2.find("."))))
            {
                return -1;
            }
            else if(stoi(ver1.substr(0, ver1.find("."))) < stoi(ver2.substr(0, ver2.find("."))))
            {
                return 1;
            }
            else
            {
                ver1.erase(0, ver1.find("."));
                ver2.erase(0, ver2.find("."));
            }
        }
        // begin check of unique version comparisions

        /// this is needs to be sorted to work out for the last value set
//        else if (ver1[0] != 0 && ver2[0] == '.')
//        {
//            if (stoi(ver1.substr(2, ver1.find("."))) == stoi(ver2.substr(1, ver2.find("."))))
//                return -1;
//        }
//        else if (ver2[0] != 0 && ver1[0] == '.')
//        {
//            if (stoi(ver1.substr(2, ver1.find("."))) == stoi(ver2.substr(1, ver2.find("."))))
//                return 1;
//        }
        ///
        else if (ver1[0] == '.' && ver2 == "" && stoi(ver1.substr(1, 1)) > 0)
                return -1;
        else if (ver2[0] == '.' && ver1 == "" && stoi(ver2.substr(1, 1)) > 0)
                return 1;
        else
            return 0;
    }
    return 2;
}
int main()
{
    cout << compareVersions("0.1", "0.1") << endl; // 0
    cout << compareVersions("1.0", "1.1") << endl; // 1
    cout << compareVersions("2.0", "2.0.1") << endl; // 1
    cout << compareVersions("0.1", "0.2") << endl; // 1
    cout << compareVersions("0.13.1", "0.13.2") << endl; // 1
    cout << compareVersions("1.0", "1.0") << endl; // 0
    cout << compareVersions("6", "6") << endl; // 0
    cout << compareVersions("0", "0") << endl; // 0
    cout << compareVersions("1.1.0", "1.1.1") << endl; // 1
    cout << compareVersions("1", "1.1") << endl; // 1
    cout << compareVersions("1.1", "1.1.0") << endl; // 0
    cout << compareVersions("256", "300.2.1") << endl; // 0
    cout << compareVersions("0.1", "1") << endl;
    cout << compareVersions("3", "3.1.1") << endl;
    cout << compareVersions(".0.4", ".1") << endl;
    cout << compareVersions("2.2.2.2.2.2.2.2.2.2.2.2", "2.2.2.2.2.2.2.2.2.2.2.2.1") << endl;
    cout << compareVersions("0.1.2.3.4.5.6.7", "0.1.1.1") << endl;
    cout << compareVersions("0.1.2.3.4.5.6.7", ".1.3.0.0.0.0") << endl;
    return 0;
}
