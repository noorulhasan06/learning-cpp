#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;
/* Head ends here */

multiset<int> data;
multiset<int>::iterator mid;

void print_current_median()
{
    cout << fixed;
    cout << std::setprecision(1);
    //cout << noshowpoint;
    
    if(data.size() == 0)
        cout << "Wrong!" << endl;
    else if(data.size() % 2 == 0) //even
    {
        long double x = (*mid + *next(mid)) * 0.5;
        if(x == (long)x)
            cout<<long(x)<<endl;
        else
            cout << x << endl;
    }
    else
        cout << *mid << endl;
}

void add_update(vector<char> s, vector<int> X)
{
    for(int i=0; i<X.size(); i++)
    {
        int num = X[i];
        int size = (int) data.size();
        
        if(s[i] == 'a')
        {
            data.insert(num);
            
            if(size == 0)  //:
                mid = data.begin();
            else if(size % 2 == 1) //odd
            {
                if(num < *mid)
                    mid = prev(mid);
            }
            else //even :
            {
                if(num >= *mid)
                    mid = next(mid);
            }
            
            //find current median
            print_current_median();
        }
        else if(s[i] == 'r')
        {
            auto it = data.find(num);
            if(size == 0 || it == data.end()) //not found :
            {
                cout << "Wrong!" << endl;
            }
            else // found
            {
                if(it == mid) //1 [1] 1
                    mid = (size % 2 == 0)? next(mid) : prev(mid);
                if(*it == *mid) //shitty:
                {
                    //it = mid;
                    mid = (size % 2 == 0)? next(mid) : mid;
                }
                else if(*it < *mid)
                    mid = (size % 2 == 0)? next(mid) : mid;
                else if((*it > *mid))  //:
                     mid = (size % 2 == 0)? mid : prev(mid);
            
                data.erase(it);
            
                //find current median
                print_current_median();
            }
        }
    }
}

int main(void){

//Helpers for input and output

   int N;
   cin >> N;
   
   vector<char> s;
   vector<int> X;
   char temp;
    int tempint;
   for(int i = 0; i < N; i++){
      cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
   }
   
   add_update(s,X);
   return 0;
}
