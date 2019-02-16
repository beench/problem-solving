#include <iostream>

using namespace std;

int main()
{
    int N, cnt = 0; 
    string word;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> word;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
                if (word[i+1] != 'a' && word[i+1] != 'e' && word[i+1] != 'i' && word[i+1] != 'o' && word[i+1] != 'u') {                
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
        cnt = 0;
    }
}