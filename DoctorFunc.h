#pragma once
#include "Policlinic.h"
#include "Doctor.h"
#include "stdio.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;


ostream& operator<<(ostream& out, Doctor doc)
{
	return out << "\nИдентификационный номер доктора:  " << doc.getDoctorID()
		<< "\nФамилия доктора:  " << doc.getDoctorSurname()
		<< "\nДолжность доктора:  " << doc.getPosition() << endl;
}

void addDoctor(stack<Policlinic, vector<Policlinic>>* st)
{
	stack<Policlinic, vector<Policlinic>> stTmp = *st;
	Policlinic policlinic;
	Doctor tmp;
	Policlinic* massTmp = new Policlinic[50];

	int id,clinicID,counter=0;
	char* doctorSurname = new char[50];
	char* position = new char[70];

	int clinicIDTmp,countDoc;
	char* clinicName = new char[30];
	char* address = new char[70];
	cout << "\n\tВведите идентификационный номер поликлиники: ";
	cin >> clinicID;

	while (!stTmp.empty())
	{
		policlinic = stTmp.top();
		if (stTmp.top().getClinicID() == clinicID)
		{		
			stTmp.pop();
			cout << "\nВведите идентификационный номер доктора: ";
			cin >> id;
			cout << "\nВведите фамилию доктора: ";
			cin >> doctorSurname;
			cout << "\nВведите должность доктора: ";
			cin >> position;
			tmp.setDoctorID(id);
			tmp.setDoctorSurname(doctorSurname);
			tmp.setPosotion(position);
			policlinic.setDoctor(tmp);

			stTmp.push(policlinic);
			if (counter != 0)
			{
				for (int i = counter-1; i >= 0; i--)
				{
					stTmp.push(massTmp[i]);
				}
			}
			(*st) = stTmp;
			return;
		}
		massTmp[counter] = stTmp.top();
		counter++;
		stTmp.pop();
	}
	
}

void showDoctorList(stack<Policlinic, vector<Policlinic>> st)
{
	Doctor* docTmp = new Doctor[50];
	int clinicID;
	cout << "\n\tВведите идентификационный номер поликлиники: ";
	cin >> clinicID;
	while(!st.empty())
	{		
		if (st.top().getClinicID() == clinicID)
		{			
			if (st.top().getCountDoc() == 0) { cout << "\nСписок докторов пуст!!!"<<endl;return; }
			docTmp = st.top().getDoctor();
			cout << "\n\t***Информация о докторах***";
			for (int i = 0; i < st.top().getCountDoc(); i++)
			{				
				cout << docTmp[i];
			}
			return;
		}
		st.pop();
	}
}

void editDoctor(stack<Policlinic, vector<Policlinic>>* st)
{
	stack<Policlinic, vector<Policlinic>> stTmp = *st;
	Policlinic policlinic;
	Doctor tmp;
	Policlinic* massTmp = new Policlinic[50];

	bool flagPol = false;
	int id,editDoctorID, clinicID, counter = 0;
	char* doctorSurname = new char[50];
	char* position = new char[70];

	int clinicIDTmp, countDoc;
	char* clinicName = new char[30];
	char* address = new char[70];
	cout << "\n\tВведите идентификационный номер поликлиники: ";
	cin >> clinicID;

	while (!stTmp.empty())
	{
		policlinic = stTmp.top();
		if (stTmp.top().getClinicID() == clinicID)
		{
			flagPol = true;
			stTmp.pop();			
			cout << "\nВведите идентификационный номер редактируемого доктора: ";
			cin >> editDoctorID;
			cout << "\nВведите новый идентификационный номер доктора: ";
			cin >> id;
			cout << "\nВведите новую фамилию доктора: ";
			cin >> doctorSurname;
			cout << "\nВведите новую должность доктора: ";
			cin >> position;
			tmp.setDoctorID(id);
			tmp.setDoctorSurname(doctorSurname);
			tmp.setPosotion(position);
			policlinic.setDoctorID(tmp,editDoctorID);

			stTmp.push(policlinic);
			if (counter != 0)
			{
				for (int i = counter - 1; i >= 0; i--)
				{
					stTmp.push(massTmp[i]);
				}
			}
			(*st) = stTmp;
			return;
		}
		massTmp[counter] = stTmp.top();
		counter++;
		stTmp.pop();
	}
	if(!flagPol){ cout << "\n\tДанной поликлиники в списке нет!" << endl; return; }

}