#pragma once
#include "Cuser.h"
#include "CSecurity.h"
class Cinterface
{
public:
	bool Login(Cuser uuser);
	bool Zhuce(Cuser zuser);
	vector<Cuser> users;
	vector<CSecurity> stocks;
	CSecurity Find(CString sid);
	string CurUser;
	void amend(int index, Cuser cuser);
	void MarketTrend();
	void Analyze();
	string SelectStock(int index);
	vector<CSecurity> Filter(double min_p, double max_p, double min_c, double max_c, int min_vv, int max_vv);
	vector<double> Volatility();
	vector<double> MaxDrawdown();
};

