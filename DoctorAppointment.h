#pragma once
#include "Client.h"

class DoctorAppointment:public Client
{
	char* appointDate = new char[30];

public:

	void setAppointDate(char* appointDate) { this->appointDate = appointDate; }

	char* getAppointDate() { return appointDate; }
	DoctorAppointment() {}
	~DoctorAppointment() {}
};

