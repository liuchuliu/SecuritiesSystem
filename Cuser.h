#pragma once
class Cuser
{
public:
	Cuser();
	Cuser(string username, string password, string email);
	string m_username;
	string m_password;
	string m_email;
	
	void Load(ifstream& in);
	void Save(ofstream& out);
};

