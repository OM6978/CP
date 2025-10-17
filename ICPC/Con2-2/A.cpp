#include <bits/stdc++.h>
using namespace std;

bool isCapWord(string & word)
{
    if(word.size() <= 1)return false;
    if(word[0] > 90 || word[0] < 65)return false;
    
    for(int i=1;i<word.size();i++)
    {
        if(word[i] < 97 || word[i] > 122)
        {
            return false;
        }
    }

    return true;
}

string abbreviate(string & line)
{   
    // cout << line << "\n";

    string word;
    string fullForm;
    string shortForm;
    int ffsz = 0;
    
    string res;

    char a;

    for(int i=0;i<=line.size();i++)
    {
        a = 0;
        if(i < line.size())a = line[i];

        if(a == '.' || a == ',' || i==line.size())
        {
            bool cap = false;

            if(isCapWord(word))
            {
                shortForm.push_back(word[0]);

                if(fullForm.size())fullForm.push_back(' ');
                fullForm+=word;

                ffsz++;

                cap = true;
            }

            if(ffsz > 1)
            {
                res += shortForm;
                res += " (";
                res += fullForm;
                res += ")";
                if(!cap)res.push_back(' ');
            }
            else if(ffsz)
            {
                res += fullForm;
                if(!cap)res.push_back(' ');
            }
            
            if(!cap)res += word;
            if(i!=line.size())res.push_back(a);
            
            fullForm.clear();
            shortForm.clear();
            ffsz = 0;

            word.clear();
        }
        else if(a == ' ')
        {
            if(isCapWord(word))
            {
                shortForm.push_back(word[0]);

                if(fullForm.size())fullForm.push_back(' ');
                fullForm+=word;

                ffsz++;
            }
            else
            {
                if(ffsz > 1)
                {
                    res += shortForm;
                    res += " (";
                    res += fullForm;
                    res += ")";
                    res.push_back(' ');
                }
                else if(ffsz)
                {
                    res += fullForm;
                    res.push_back(' ');
                }
                
                res += word;
                res.push_back(' ');
                
                fullForm.clear();
                shortForm.clear();
                ffsz = 0;
            }
            
            word.clear();
        }
        else
        {
            word.push_back(a);
        }
    }

    return res;
}

void solve()
{
    vector<string> inp;
    string line;
    while(getline(cin, line))
    {
        inp.push_back(line);
    }

    vector<string> out;
    for(auto a : inp)
    {
        out.push_back(abbreviate(a));
    }

    for(auto line : out)
    {
        cout << line << '\n';
    }
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/om/Acads/CP/input.txt", "r", stdin);
        freopen("/home/om/Acads/CP/output.txt", "w", stdout);
    #else
        freopen("abbreviation.in", "r", stdin);
        freopen("abbreviation.out", "w", stdout);
    #endif
    
    solve();
    
    return 0;
}