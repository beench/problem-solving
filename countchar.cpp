#include <iostream>
using namespace std;

int count_char(char* st, char c)
{
    int count = 0;
    for (int i = 0; st[i]!='NULL'; i++){
        if (st[i] == c) count++;
    }
    return count;

}

main()
{
  char st[1000];

  cin.getline(st,1000);

  cout << "space: " << count_char(st,' ') << endl;
  cout << "dot: " << count_char(st,'.') << endl;
  cout << "semi: " << count_char(st,';') << endl;
}