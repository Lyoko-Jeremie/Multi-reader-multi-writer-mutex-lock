#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <vector>
using namespace std;

#include "RWLock.h"

deque<int> tv;
vector<thread> pt;
RWLock rwl(true);

mutex mtx;

void t1()
{
    for ( int i = 0; i != 100; ++i)
    {
        ATMWGuard a(rwl);
        tv.push_back(i);
    }
    return;
}

void t2()
{
    for ( int i = 0; i != 100; ++i)
    {
        {
            ATMRGuard a(rwl);
            if (!tv.empty())
            {
                lock_guard<mutex> m(mtx);
                cout << tv.back() << "\t";
            }
        }
        {
            ATMWGuard a(rwl);
            if (!tv.empty())
            {
                tv.pop_front();
            }
        }
    }
    return;
}

int main()
{
    cout << "Hello world!" << endl;
    for ( int i = 0; i != 500; ++i)
    {
        pt.emplace_back( i%2==0 ? t1 : t2 );
    }
    for ( thread &a : pt )
    {
        a.join();
    }
    cout << endl;
//    for ( int &a : tv )
//    {
//        cout << a << "\t";
//    }
    return 0;
}





