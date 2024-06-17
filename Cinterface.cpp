#include "pch.h"
#include "Cinterface.h"

bool Cinterface::Login(Cuser uuser)
{
	CString strFilePath = _T(".\\UsersInfo.txt");
    CString FilePath = _T(".\\Stocks.txt");
	ifstream in(strFilePath, ios::in);
    ifstream in2(FilePath, ios::in);
    users.clear();
    if (in.is_open())
    {
        int num; //��¼����
        in >> num;
        for (int i = 0; i < num; i++)
        {
            Cuser iinfo;
            iinfo.Load(in);
            users.push_back(iinfo);
        }
        for (int i = 0; i < users.size(); i++)
        {
            if (users[i].m_username == uuser.m_username && users[i].m_password == uuser.m_password && users[i].m_email == uuser.m_email)
            {
                stocks.clear();
                if (in2.is_open())
                {
                    int sum;
                    in2 >> sum;
                    for (int j = 0; j < sum; j++)
                    {
                        CSecurity sttocks;
                        sttocks.Load(in2);
                        stocks.push_back(sttocks);
                    }
                }
                CurUser = uuser.m_username;
                return true;
            }
        }

        return false;
    }
	return false;
}

bool Cinterface::Zhuce(Cuser zuser)
{
    CString strFilePath = _T(".\\UsersInfo.txt");
    int num;
    users.clear();
    ifstream in(strFilePath, ios::in);
    if (in.is_open())
    {
        in >> num;
        for (int i = 0; i < num; i++)
        {
            Cuser iinfo;
            iinfo.Load(in);
            users.push_back(iinfo);
        }
    }
    for (int i = 0; i < users.size(); i++)
    {
        if (zuser.m_username == users[i].m_username || zuser.m_email == users[i].m_email)
        {
            return false;
        }
    }
    users.push_back(zuser);
    ofstream out(strFilePath, ios::out);
    if (out.is_open())
    {
        out << users.size() << endl;
        for (int i = 0; i < users.size(); i++)
        {
            users[i].Save(out);
        }
        out.close();
        return true;
    }
    return false;
}

CSecurity Cinterface::Find(CString sid)
{
    for (int i = 0; i < stocks.size(); i++)
    {
        if (stocks[i].symbol.c_str() == sid)
        {
            return stocks[i];
        }
    }
    return CSecurity(TEXT(""), TEXT(""), -1, -1, -1);
}

void Cinterface::amend(int index, Cuser cuser)
{
    users[index] = cuser;
    CString strFilePath = _T(".\\UsersInfo.txt");
    ofstream out(strFilePath, ios::out);
    if (out.is_open())
    {
        out << users.size() << endl;
        for (int i = 0; i < users.size(); i++)
        {
            users[i].Save(out);
        }
        out.close();
    }
}

void Cinterface::MarketTrend()
{
    CString FilePath = _T(".\\Stocks.txt");
    ifstream in(FilePath, ios::in);
    if (in.is_open())
    {
        int sum;
        in >> sum;
        for (int j = 0; j < sum; j++)
        {
            CSecurity sttocks;
            sttocks.Load(in);
            stocks.push_back(sttocks);
        }
    }
}

void Cinterface::Analyze()
{
    CString FilePath = _T(".\\Stocks.txt");
    ifstream in(FilePath, ios::in);
    if (in.is_open())
    {
        int sum;
        in >> sum;
        for (int j = 0; j < sum; j++)
        {
            CSecurity sttocks;
            sttocks.Load(in);
            stocks.push_back(sttocks);
        }
    }
}

string Cinterface::SelectStock(int index)
{
    string ans;
    switch (index)
    {
    case 0: ans = "ƻ���ɼ�С�����ǣ��������ȶ�����ʾ��Ͷ���߶���δ��ǰ�������ġ�"; break;
    case 1: ans = "�ȸ�ɼ�΢�����������ϵͣ������ܵ��г����ڲ�����Ӱ�졣"; break;
    case 2: ans = "΢��ɼ��������ǣ�������Ҳ������ӣ������г���΢���δ���������ֹ�̬�ȡ�"; break;
    case 3: ans = "����Ͱ͹ɼ��Ȳ����������������У���ʾ��Ͷ���߶�����ҵģʽ���Ͽɡ�"; break;
    case 4: ans = "�����ɼ��Ƿ��ϴ󣬽�����Ҳ�������ӣ����������ڽ���ҵ�����������г����õ�Ӱ�졣"; break;
    case 5: ans = "��Ѷ�ɼ��Ȳ����������������У���ʾ���г���������Ϸ���罻ý�����������ȵ�λ���Ͽɡ�"; break;
    default: ans = "���޴˹�Ʊ��"; break;
    }
    return ans;
}

vector<CSecurity> Cinterface::Filter(double min_p, double max_p, double min_c, double max_c, int min_vv, int max_vv)
{
    vector<CSecurity> tmp_stocks;
    for (int i = 0; i < stocks.size(); i++)
    {
        if (stocks[i].price <= max_p && stocks[i].price >= min_p && stocks[i].changePercentage <= max_c && stocks[i].changePercentage >= min_c && stocks[i].volume <= max_vv && stocks[i].volume >= min_vv)
        {
            tmp_stocks.push_back(stocks[i]);
        }
    }
     return tmp_stocks;
}

vector<double> Cinterface::Volatility()
{
    double sum, mean, var;
    vector<double> HistoryPrices, ans;
    CString FilePath = _T(".\\StocksHistory.txt");
    ifstream in(FilePath, ios::in);
    for (int i = 0; i < stocks.size(); i++)
    {
        for (int j = 0; j < 18; j++)
        {
            double tmp;
            in >> tmp;
            HistoryPrices.push_back(tmp);
        }
        sum = 0.0;
        mean = 0.0;
        var = 0.0;
        for (int j = 0; j < 18; j++)
        {
            sum += HistoryPrices[j];
        }
        mean = sum / 18;
        for (int j = 0; j < 18; j++)
        {
            var += pow(HistoryPrices[j] - mean, 2);
        }
        ans.push_back(sqrt(var / 18));
        for (int j = 17; j >=0; j--)
        {
            HistoryPrices.erase(HistoryPrices.begin() + j);
        }
    }
    return ans;
}

vector<double> Cinterface::MaxDrawdown()
{
    CString FilePath = _T(".\\StocksHistory.txt");
    vector<double> HistoryPrices, ans;
    ifstream in(FilePath, ios::in);
    double maxPrice, currentDrawdown, maxDrawdown;
    for (int i = 0; i < stocks.size(); i++)
    {
        for (int j = 0; j < 18; j++)
        {
            double tmp;
            in >> tmp;
            HistoryPrices.push_back(tmp);
        }
        maxPrice = *max_element(HistoryPrices.begin(), HistoryPrices.end());
        currentDrawdown = 0.0, maxDrawdown = 0.0;
        for (int j = 0; j < 18; j++)
        {
            currentDrawdown = (maxPrice - HistoryPrices[j]) / maxPrice;
            maxDrawdown = (std::max)(maxDrawdown, currentDrawdown);
            if (HistoryPrices[j] > maxPrice) {
                maxPrice = HistoryPrices[j];
                currentDrawdown = 0.0; // ���ûس�  
            }
        }
        ans.push_back(maxDrawdown);
        for (int j = 17; j >= 0; j--)
        {
            HistoryPrices.erase(HistoryPrices.begin() + j);
        }
    }
    return ans;
}
