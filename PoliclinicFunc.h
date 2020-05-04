#pragma once
#include "Policlinic.h"
#include "stdio.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;


ostream& operator<<(ostream& out, Policlinic pl)
{
	return out <<"\nИдентификационный номер поликлиники:  " << pl.getClinicID() 
               <<"\nНазвание поликлиники:  " << pl.getClinicName()	
		       <<"\nАдрес поликлиники:  " << pl.getAddress() << endl;
}

void addPoliclinic(stack<Policlinic,vector<Policlinic>>* st)
{
	Policlinic policlinic;
	int id;
	char* clinicName = new char[50];
	char* address = new char[70];

	cout << "\nВведите идентификационный номер поликлиники: ";
	cin >> id;
	cout << "\nВведите название поликлиники: ";
	cin >> clinicName;
	cout << "\nВведите адрес поликлиники: ";
	cin >> address;
	policlinic.setClinicID(id);
	policlinic.setClinicName(clinicName);
	policlinic.setAddress(address);

	(*st).push(policlinic);
}

void showPoliclinicList(stack<Policlinic, vector<Policlinic>> st)
{
	cout << "\n\t***Информация о поликлиниках***";
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
}