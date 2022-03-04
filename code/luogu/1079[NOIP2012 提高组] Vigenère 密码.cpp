#include <bits/stdc++.h>
using namespace std;

char ch[26][26];
queue<char> q;
string key,s;

int main()
{
    for(int i=0;i<26;i++)
    {
        q.push(i);
    }
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            ch[i][j]=q.front();
            q.pop();
            q.push(ch[i][j]);
        }
        q.push(q.front());
        q.pop();
    }
    cin>>key>>s;
    int i=0,j=0;
    bool flag=false;
    for(i=0;i<s.size();i++)
    {
        flag=false;
        if(j==key.size()) j=0;
        if(key[j]>='A'&& key[j]<='Z') key[j]=key[j]-'A'+'a';
        if(s[i]>='A'&& s[i]<='Z') flag=true;
        if(flag) 
        {
            for(int q=0;q<26;q++)
            {
                if(ch[key[j]-'a'][q]==(s[i]-'A'))
                {
                    cout<<(char)(q+'A');
                    break;
                }
            }
        }
        else 
        {
            for(int q=0;q<26;q++)
            {
                if(ch[key[j]-'a'][q]==(s[i]-'a'))
                {
                    cout<<(char)(q+'a');
                    break;
                }
            }
        }
        j++;
    }
    return 0;
} 
