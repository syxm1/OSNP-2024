#include<iostream>
using namespace std;
#define l long long
#define w while
#define v (f!=i||g!=k)
l c(l n,l r){l k=1,y=n-r;w(n)k*=n--;w(r)k/=r--;w(y)k/=y--;return k;}int main(){l t;cin>>t;w(t--){l x,y,f,g,i,k;cin>>x>>y>>f>>g>>i>>k;l u=c(x+y,y),a=c(x-f+y-g,x-f),b=c(f+g,f),d=c(x-i+y-k,x-i),e=c(i+k,i),p=f-i,q=g-k;if(p<0)p*=-1;if(q<0)q*=-1;l j=u-a*b,h=c(p+q,p);if(v)j-=d*e;if(f<=i&&g<=k&&v)j+=h*b*d;if(i<=f&&k<=g&&v)j+=h*a*e;cout<<j<<'\n';}}
