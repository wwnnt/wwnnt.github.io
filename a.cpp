#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,H,M;
		cin>>n>>H>>M;
		vector<int> h(n),m(n);
		int ansh=23,ansm=59;
		int nowh=0,nowm=0;
		for(int i=0;i<n;i++)
		{
			cin>>h[i]>>m[i];
			if(h[i]==H){
				if(m[i]>=M)
					nowh = 0,nowm = m[i]-M;
				else
					nowh = 23,nowm = m[i]-M+60;
			}
			else if(h[i]>H){
				if(m[i]>=M)
					nowm = m[i]-M;
				else
					h[i]--,nowm = m[i]-M+60;
				nowh = h[i]-H;
			}
			else{
				h[i] = h[i]+24;
				if(m[i]>=M)
					nowm = m[i]-M;
				else
					h[i]--,nowm = m[i]-M+60;
				nowh = h[i]-H;
			}
			//cout<<nowh<<" "<<nowm<<endl;
			if(nowh==ansh){
				ansm = min(nowm,ansm);
			}
			else if(nowh<ansh){
				ansh = nowh;
				ansm = nowm;
			}
		}
		cout<<ansh<<" "<<ansm<<endl;

	}
}