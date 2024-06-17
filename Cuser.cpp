#include "pch.h"
#include "Cuser.h"

Cuser::Cuser()
{
}

Cuser::Cuser(string username, string password, string email)
{
	this->m_username = username;
	this->m_password = password;
	this->m_email = email;
}

void Cuser::Load(ifstream& in)
{
	in >> m_username;
	in >> m_password;
	in >> m_email;
}

void Cuser::Save(ofstream& out)
{
	out << m_username << "\t" << m_password << "\t" << m_email << "\n";
}

