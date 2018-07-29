#include <bits/stdc++.h>
using namespace std;

string s;
int arr[100100];
vector<pair<int,char> > vowel_pos;
vector<long long> num_vowels,num_vowel;

void compute_vowel_pos()	{
	for(int i=0;i<s.length();i++)	{
		if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')	{
			vowel_pos.push_back(make_pair(i,s[i]));
		}
	}
}

bool comp1(int b, const pair<int,char> &a)	{
	return b<a.first;
}

bool comp2(const pair<int,char> &a, int b)	{
	return a.first<b;
}

int compute_num_vowels(int x)	{
	int temp=abs(x),pos;
	if(x>=0)	{
		pos=upper_bound(vowel_pos.begin(),vowel_pos.end(),temp,comp1)-vowel_pos.begin();
	}
	else	{
		pos=lower_bound(vowel_pos.begin(),vowel_pos.end(),temp,comp2)-vowel_pos.begin();
		pos=(int)vowel_pos.size()-pos;
	}
	return pos;
}

int main()	{
	cin>>s;
	compute_vowel_pos();
	int n,temp;
	cin>>n;
	for(int i=0;i<n;i++)	{
		cin>>arr[i];
		temp=compute_num_vowels(arr[i]);
		num_vowel.push_back(temp);
		//cout<<temp<<endl;
	}
	num_vowels.push_back(num_vowel[0]);
	for(int i=1;i<n;i++)	{
		num_vowels.push_back(num_vowels[i-1]+num_vowel[i]);
	}
	int q;
	cin>>q;
	long long k;
	int pos;
	while(q--)	{
		cin>>k;
		if(k>num_vowels[n-1])	{
			cout<<"-1\n";
			continue;
		}
		pos=lower_bound(num_vowels.begin(),num_vowels.end(),k)-num_vowels.begin();
		//cout<<pos<<endl;
		if(pos!=0)	{
			k-=num_vowels[pos-1];
		}
		k--;
		if(arr[pos]>=0)	{
			cout<<vowel_pos[k].second<<endl;
		}
		else	{
			cout<<vowel_pos[(int)vowel_pos.size()-(int)num_vowel[pos]+k].second<<endl;
		}
	}
	return 0;
}