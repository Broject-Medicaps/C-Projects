#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    int hour, minute, second, a, error;
    unsigned int microseconds;

    error = a = 0;
    while (error == 0)
    {
        cout << "Enter Hour" << endl;
        cin >> hour;
        cout << "Enter Minute" << endl;
        cin >> minute;
        cout << "Enter second" << endl;
        cin >> second;

        if ((hour < 24) && (minute < 60) && (second < 60))
        {
            error++;
        }
        else
        {
            system("clear");
        }

        while (a == 0)
        {
            system("clear");
            cout << hour << ":" << minute << ":" << second << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            second++;
            if (second > 59)
            {
                second = 0;
                minute++;
            }
            if (minute > 59)
            {
                minute = 0;
                hour++;
            }
            if ((hour > 24))
            {
                hour = 0;
            }
        }
    }
    return 0;
}
