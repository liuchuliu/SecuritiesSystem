#pragma once
class CSecurity
{
public:
    CSecurity();
    CSecurity(string ssmbol, string nname, double pprice, double cchangePercentage, int vvolume);

    // ֤ȯ���루�磺AAPL����ƻ����˾��  
    string symbol;
    // ֤ȯ���ƣ��磺ƻ����˾��  
    string name;
    // ��ǰ�۸��Ի���Ϊ��λ������Ԫ��  
    double price;
    // �ǵ������ٷֱ���ʽ���磺0.5��ʾ����0.5%��  
    double changePercentage;
    // �ɽ�������λͨ������ɣ�  
    int volume;
    void Load(ifstream& in);
    void Save(ofstream& out);
};

