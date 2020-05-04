#pragma once
#include <iostream>
#include "stdio.h"
#include "Client.h"
#include "DoctorAppointment.h"
#include <queue>
#include <vector>
#include <deque>
using namespace std;

bool operator <(Client c1,Client c2)
{
	return c1.getClientID() < c2.getClientID();
}

void registerClient(queue<Client, deque<Client>> *cl)
{
	Client tmp;
	int clinicID;
	int clientID;
	char* clientSurname = new char[50];
	int clientAge;

	cout << "\nВведите название подходящей клиники:  ";
	cin >> clinicID;
	cout << "\nВведите свой идентификационный номер:  ";
	cin >> clientID;
	cout << "\nВведите свою фамилию:  ";
	cin >> clientSurname;
	cout << "\nВведите свой возраст:  ";
	cin >> clientAge;

	tmp.setClinicID(clinicID);
	tmp.setClientID(clientID);
	tmp.setClientSurname(clientSurname);
	tmp.setClientAge(clientAge);
	(*cl).push(tmp);
}

void makeAppointment(queue<Client, deque<Client>> cl,priority_queue<DoctorAppointment,vector<DoctorAppointment>>* app)
{
	DoctorAppointment docApp;
	int clientID; 
	char* appointDate = new char[50];
	bool flag = true;
	cout << "\nВведите свой идентификационный номер:  ";
	cin >> clientID;
	while (!cl.empty())
	{
		if (cl.front().getClientID()==clientID)
		{
			cout << "\nВведите желаемую дату приема:  ";
			cin >> appointDate;
			docApp.setAppointDate(appointDate);
			docApp.setClientID(cl.front().getClientID());
			docApp.setClientSurname(cl.front().getClientSurname());
			docApp.setClientAge(cl.front().getClientAge());
			docApp.setClinicID(cl.front().getClinicID());
			(*app).push(docApp);
			flag = false;
			break;
		}
		cl.pop();
	}
	if(flag)
	{
		cout << "\nЗарегестрируйтесь в поликлинике!" << endl;
	}
	else
	{
		cout << "\nПрием назначен на дату:  " << appointDate << endl;
	}
}