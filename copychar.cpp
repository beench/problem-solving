#include <iostream>
using namespace std;

void copy_string(char* src, char* dest)
{
    int cnt;
    for (int i = 0; src[i] != '\0'; i++){
        dest[i]=src[i];
        cnt = i;
    }
    dest[cnt+1] = '\0';
}

main()
{
  char st1[1000];
  char st2[1000];

  cin.getline(st1,1000);
  copy_string(st1,st2);

  cout << st2 << endl;
}