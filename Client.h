#pragma once

class Client
{
	int clinicID;
	int clientID;
	char* clientSurname = new char[50];
	int clientAge;

public:

	void setClinicID(int clinicID) { this->clientID = clinicID; }
	void setClientID(int clientID) { this->clientID = clientID; }
	void setClientSurname(char* clientSurname) { this->clientSurname = clientSurname; }
	void setClientAge(int clientAge){ this->clientAge = clientAge; }

	int getClinicID() { return clinicID; }
	int getClientID() { return clientID; }
	char* getClientSurname() { return clientSurname; }
	int getClientAge() { return clientAge; }
	Client(){}
	~Client(){}
};

