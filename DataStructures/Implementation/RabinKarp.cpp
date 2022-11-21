#include <iostream>
using namespace std;

void RabinKarp(string txt, int txt_len, string pat, int pat_len, int base)
{
    unsigned int pat_hash = 0;
    unsigned int txt_hash = 0;
    unsigned int curr_hash = 1;
    for (int i = 0; i < pat_len - 1; i++)
    {
        curr_hash = curr_hash * base;
    }

    for (int i = 0; i < pat_len; i++)
    {
        pat_hash = (base * pat_hash + pat[i]);
        txt_hash = (base * txt_hash + txt[i]);
    }

    for (int i = 0; i <= txt_len - pat_len; i++)
    {
        if (pat_hash == txt_hash)
        {
            int j;
            for (j = 0; j < pat_len; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    break;
                }
            }
            if (j == pat_len)
            {
                cout << i << endl;
                return;
            }
        }

        if (i < txt_len - pat_len)
        {
            txt_hash = (base * (txt_hash - txt[i] * curr_hash) + txt[i + pat_len]);
        }
    }
    cout << "Not Found" << endl;
}

int main(void)
{
    string txt;
    string pat;
    cin >> txt >> pat;
    RabinKarp(txt, txt.length(), pat, pat.length(), 1 << (txt.length()));
}