#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(const string &s1, const string &s2){
    if(s1.size()== s2.size()) //두 단어의 길이가 같은 경우 
        return s1 < s2; //단어 순으로 정렬
    else //길이가 다른 경우 
        return s1.size() < s2.size(); //길이가 짧은 것이 먼저 오도록 
}   

int main(void){
    int num = 0;
    scanf("%d",&num);
    vector<string> v; 
    for(int i = 0; i < num; i++){
        char word[51];
        scanf("%s",word);
        string str(word);
        v.push_back(str);
    }
    sort(v.begin(),v.end(),comp);
    v.erase(unique(v.begin(),v.end()),v.end());
    vector<string>::iterator iter;
    for(iter= v.begin();iter!=v.end();iter++){
        printf("%s\n",(*iter).c_str());
    }
    return 0;
}