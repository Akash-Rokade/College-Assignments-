#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;
int main()
{
char line[80];
int cnt=0;
fstream myfile("story2.txt");
if(myfile.is_open())
{
while(!myfile.eof())
{
myfile.getline(line,80);
if(line[0]!='A')
{
cnt++;
}
}
}
else
{
cout<<"\n unable to open the file";
}
cout<<"\n number of line are:"<<cnt;
myfile.close();
return 0;
}
