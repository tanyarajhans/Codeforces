#include <bits/stdc++.h>
using namespace std;
 
int digit(long long int n){
	n = abs(n);
	int c = 0;
	while(n){
		c+= (n%10);
		n /= 10;
	}
	return c;
}
 
long long int power(int x,int y){
    long long int answer = 1;
    for(int i=1;i<=y;i++)
        answer *= x;
    return answer;
}
 
int main(){
 
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
 
	int answer = 0;
    vector<long long int> Answer;
	for(int i=1;i<=81;i++){
		long long int x = b*power(i,a) + c;
		//printf("%d : %lld\n",i,x);
		if(x>0 && digit(x)==i && x<1000000000){
		    Answer.push_back(x);
		    //printf("%d : %lld\n",i,x);
			answer++;
		}
	}
 
	printf("%d\n",answer);
    for(int i=0;i<answer;i++)
        printf("%lld ",Answer[i]);
	return 0;
}
