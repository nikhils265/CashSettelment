#include<bits/stdc++.h>
using namespace std;
class person_compare
{
	public:
		bool operator()(pair<string,int> p1,pair<string,int> p2)
		{
			return p1.second<p2.second;
		}
};
int main()
{
	int no_of_transaction,no_of_friends;
	cin>>no_of_transaction>>no_of_friends;
	map<string,int> net;
	while(no_of_transaction--)
	{
		string a,b;
		int amount;
		cin>>a>>b>>amount;
		if(net.count(a)==0)
		{
			net[a]=0;
		}
		if(net.count(b)==0)
		{
			net[b]=0;
		}
		net[a]-=amount;
		net[b]+=amount;
	}
	set<pair<string,int>,person_compare> s;
	for(auto p:net)
	{
		string person = p.first;
		int amount = p.second;
		s.insert(make_pair(person,amount));
		if(amount!=0)
		{
			s.insert(make_pair(person,amount));
		}
	}
	while(!s.empty())
	{
		auto low = s.begin();
		auto high = prev(s.end());
		s.erase(low);
		s.erase(high);
		int debit = low->second;
		string debit_person = low->first;
		int credit = high->second;
		string credit_person = high->first;
		int amount = min(-debit,credit);
		net[debit_person]+=amount;
		net[credit_person]-=amount;
		cout<<debit_person<<" pays "<<amount<<" to "<<credit_person<<endl;
		if(net[debit_person]!=0)
		{
			s.insert(make_pair(debit_person,net[debit_person]));
		}
		if(net[credit_person]!=0)
		{
			s.insert(make_pair(credit_person,net[credit_person]));
		}
	}
	return 0;
}
