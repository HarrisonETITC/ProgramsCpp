#include <iostream>
#include <string>

using namespace std;

int main()
{
    double people, toilets;
    string result = "";

    cin >> people >> toilets;

    if (toilets / people > 3.0 || toilets - 2 < people)
    {
        result = "*";
    }
    else
    {
        if (toilets - 2 == people)
        {
            for (int i = 0; i < toilets; i++)
            {
                if (i == 0 || i % 2 == 0)
                {
                    result += "X";
                }
                else
                {
                    result += "-";
                }
            }
        }
        else
        {
            int cont = 0;
            for (int i = 0; i < toilets; i++)
            {
                if (i == 1 || cont == 2)
                {
                    result += "X";
                    cont = 0;
                }
                else
                {
                    result += "-";
                    cont += i == 0? 0 : 1;
                }
            }
        }
    }

    cout << result << "\n";

    return 0;
}