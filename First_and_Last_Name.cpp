#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct name
{
    int yearH;
    string nameH;
};

bool comp (name i, name j)
{
    return (i.yearH<j.yearH);
}

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    sttmp1.yearH=year;
    sttmp1.nameH=first_name;
    FNHistory.push_back(sttmp1);
  }
  void ChangeLastName(int year, const string& last_name) {
    sttmp2.yearH=year;
    sttmp2.nameH=last_name;
    LNHistory.push_back(sttmp2);
  }
  string GetFullName(int year) 
  {
    string result;
    if (FNHistory.size()!=0)
    {
    sort (FNHistory.begin(),FNHistory.end(), comp);
    }
    if (LNHistory.size()!=0)
    {
    sort (LNHistory.begin(),LNHistory.end(), comp);
    }
    if (FNHistory.size()!=0)
    {
        for (int i=FNHistory.size()-1;i>=0;i--)
        {
            if(year>=FNHistory[i].yearH)
            {
                result=(FNHistory[i].nameH+' ');
                break;
            }
            if(i==0)
            {
                FNB=1;
                break;
            }
        }   
    }
    else {FNB=1;}
    if (LNHistory.size()!=0)
    {
        for (int i=LNHistory.size()-1;i>=0;i--)
    {
        if(year>=LNHistory[i].yearH)
        {
            if (FNB==1)
            {
                       FNB=0;
               return result=LNHistory[i].nameH+" with unknown first name";
               break;
            }
            else
            {

                        FNB=0;
                return result+=LNHistory[i].nameH;
                break;
            }
        }
        if(i==0)
        {
            if (FNB==1)
            {
                        FNB=0;
                return "Incognito";
            }
            else
            {
                        FNB=0;
                return result+="with unknown last name";
            }
        }

    }
    }
    return "Incognito"; 
  }
  
private:
  vector <name> FNHistory;
  vector <name> LNHistory;
  
  name sttmp1, sttmp2;
  bool FNB=0;
  
};

int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;
}