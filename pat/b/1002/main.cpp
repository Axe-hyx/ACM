#include <cstdio>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

vector<string> py = {"ling" ,"yi","er","san","si","wu","liu","qi","ba","jiu","shi"};
string s;
void ans(int nums){
    if(nums/10){
        ans(nums/10);
        printf(" ");
    }
    printf("%s",py[nums % 10].c_str());
}
int main(){
    getline(cin,s);
    int nums = 0;
    for(int i =0;i<strlen(s.c_str());++i){
        nums += s[i] - '0';
    }

    if(!nums) printf("ling\n");
    else    ans(nums);
}
