#pragma once
class CSecurity
{
public:
    CSecurity();
    CSecurity(string ssmbol, string nname, double pprice, double cchangePercentage, int vvolume);

    // 证券代码（如：AAPL代表苹果公司）  
    string symbol;
    // 证券名称（如：苹果公司）  
    string name;
    // 当前价格（以货币为单位，如美元）  
    double price;
    // 涨跌幅（百分比形式，如：0.5表示上涨0.5%）  
    double changePercentage;
    // 成交量（单位通常是万股）  
    int volume;
    void Load(ifstream& in);
    void Save(ofstream& out);
};

