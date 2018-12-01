#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


void prettyprinting(string str1, int l)
{
    string str;
    int countw = 1;
    vector <string> v1;
    
    for(int i= 0; i<str1.length();i++)
        { 
            if(str1[i]==' ')
            {
                v1.push_back(str);
                str = "";
                countw+=1;               // countw has number of words in the line.
            }
            else
            {
                str.append(str1.begin()+i,str1.begin()+i+1);   
            }
        }
    
    v1.push_back(str);
    str="";
    vector<string>::iterator iter;
    int countl = 0;
    vector<string> v2;
    vector<string>::iterator iter2;
    vector<string>::iterator iter3;
    int nwords = 0;
    iter = v1.begin();
    while(iter!=v1.end())
    {
        //cout<<*(iter)<<"\n";                    // Printing for testing :) 
        if(countl + (*iter).length()<= l)
        {
            v2.push_back(*(iter));
            countl = countl + (*iter).length();
            iter++;
            countl +=1;
            nwords +=1;
            if(iter == v1.end())
            {
                cout<<"\"",
                cout<<*(v2.end()-1);
                for(int i=(*(v2.end()-1)).length(); i<l;i++)
                {
                    cout<<" ";
                }
                cout<<"\"";
            }
        }
        else
        {
            if(nwords>1)
            {
               int spaceavail = l - countl + nwords;
               int quo = spaceavail / (nwords-1);
               int rem = spaceavail % (nwords-1);

               if(rem!=0)
               {
                   int temp = rem;
                   cout<<"\"";
                   for(iter2 = v2.begin();iter2!=v2.end();iter2++)
                   {
                       cout<<*(iter2);
                       iter3 = iter2+1;
                      if(iter3!=v2.end())
                   {
                       for(int i=0;i<quo;i++ )
                       {
                           cout<<" ";
                       }
                   
                   }
                       if(temp>0)
                          {
                              cout<<" ";
                              temp = temp - 1;
                          }
                   }
                   v2.erase(v2.begin(),v2.end());
                   cout<<"\""<<", ";
                   countl = 0;
                   nwords = 0;
               } 
               else
               {   
                   cout<<"\"";
                   for(iter2 = v2.begin();iter2!=v2.end();iter2++)
                   {
                       cout<<*(iter2);
                       iter3 = iter2+1;
                   if(iter3!=v2.end())
                   {
                       for(int i=0;i<quo;i++ )
                       {
                           cout<<" ";
                       }
                   
                   }
                   }
                   v2.erase(v2.begin(),v2.end());
                   cout<<"\""<<", ";
                   countl = 0;
                   nwords = 0;
               }
            }
            else
            {
                int spaceavail = l - countl + nwords;
                int quo = spaceavail / (nwords);
                cout<<"\"";
                cout<<*(v2.begin());
                for(int i= 0; i<quo;i++)
                {
                    cout<<" ";
                }
                v2.erase(v2.begin(),v2.end());
                cout<<"\""<<", ";
                countl = 0;
                nwords = 0;
            }
        }
    }
   
}


int main() 
{
    vector<int> count1;
    string s1;
    getline(cin,s1);
    int l;
    scanf("%d",&l);
    if(l > s1.length())
    {
        cout<<"\""<<s1<<" \"";
    }
    else if(l==s1.length())
    {
        cout<<"\""<<s1<<"\"";
    }
    else
    {
      prettyprinting(s1, l);
    }
    return 0;
}
