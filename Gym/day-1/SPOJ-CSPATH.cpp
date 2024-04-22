#include<iostream>
using namespace std;
#define l long long
#define w while
#define v (f!=i||g!=k)
l c(l n,l r){l k=1,y=n-r;w(n)k*=n--;w(r)k/=r--;w(y)k/=y--;return k;}int main(){l t;cin>>t;w(t--){l x,y,f,g,i,k;cin>>x>>y>>f>>g>>i>>k;l u=c(x+y,y),a=c(x-f+y-g,x-f),b=c(f+g,f),d=c(x-i+y-k,x-i),e=c(i+k,i),p=f-i,q=g-k;if(p<0)p*=-1;if(q<0)q*=-1;l j=u-a*b,h=c(p+q,p);if(v)j-=d*e;if(f<=i&&g<=k&&v)j+=h*b*d;if(i<=f&&k<=g&&v)j+=h*a*e;cout<<j<<'\n';}}

/*
banyaknya jalan dari O(0,0) menuju titik A(x,y) tanpa melalui titik B(x1,y1) dan C(x2,y2)?
x = banyak jalan (O-A) - banyak jalan(O-B-A) - banyak jalan(O-C-A), jika B != C.
    banyak jalan (O-A) - banyak jalan(O-B-A), jika B == C.
jika salah satu titik berada di kanan atas titik lain dan kedua titik tidak sama, 
misal B berada di kanan atas C dan B != C, maka x += banyak jalan(O-C) * banyak jalan (C-B) * banyak jalan (A-B). 
*/
