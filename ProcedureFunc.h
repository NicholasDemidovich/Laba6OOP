#pragma once
#include "Policlinic.h"
#include "Doctor.h"
#include "DoctorFunc.h"
#include "stdio.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;


ostream& operator<<(ostream& out,Procedure proc)
{
	return out << "\nИдентификационный номер процедуры:  " << proc.getProcedureID()
		<< "\nНазвание процедуры:  " << proc.getProcedureName() << endl;
}

void addProcedure(stack<Policlinic, vector<Policlinic>>* st)
{
	stack<Policlinic, vector<Policlinic>> stTmp = *st;
	Policlinic policlinic;
	Doctor tmp;
	Procedure procTmp;
	Policlinic* massTmp = new Policlinic[50];
	Doctor* massDoctorTmp = new Doctor[50];

	int id, clinicID,doctorID, counter = 0,countDoc=0;
	char* procedureName = new char[50];

	cout << "\n\tВведите идентификационный номер поликлиники: ";
	cin >> clinicID;

	while (!stTmp.empty())
	{
		policlinic = stTmp.top();
		if (stTmp.top().getClinicID() == clinicID)
		{
			countDoc = stTmp.top().getCountDoc();
			massDoctorTmp = stTmp.top().getDoctor();
			stTmp.pop();
			cout << "\nВведите идентификационный номер доктора: ";
			cin >> doctorID;
			for (int i = 0; i < countDoc; i++)
			{
				if (doctorID == massDoctorTmp[i].getDoctorID())
				{
					tmp = massDoctorTmp[i];
					cout << "\nВведите идентификационный номер процедуры: ";
					cin >> id;
					cout << "\nВведите название процедуры: ";
					cin >> procedureName;
					procTmp.setProcedureID(id);
					procTmp.setProcedureName(procedureName);
					tmp.setProcedure(procTmp);
					policlinic.setDoctorID(tmp, doctorID);

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
			}
		}
		massTmp[counter] = stTmp.top();
		counter++;
		stTmp.pop();
	}

}

void showProcedureList(stack<Policlinic, vector<Policlinic>> st)
{
	Doctor* docTmp = new Doctor[50];
	Procedure* procTmp = new Procedure[50];
	int clinicID,doctorID;
	cout << "\n\tВведите идентификационный номер поликлиники: ";
	cin >> clinicID;
	while (!st.empty())
	{
		if (st.top().getClinicID() == clinicID)
		{
			if (st.top().getCountDoc() == 0) { cout << "\nСписок докторов пуст!!!" << endl; return; }
			docTmp = st.top().getDoctor();
			cout << "\n\t***Информация о докторах***";
			for (int i = 0; i < st.top().getCountDoc(); i++)
			{
				cout << docTmp[i];
			}
			cout << "\n\tВведите идентификационный номер доктора: ";
			cin >> doctorID;
			for (int i = 0; i < st.top().getCountDoc(); i++)
			{
				if (doctorID == docTmp[i].getDoctorID())
				{
				    procTmp = docTmp[i].getProcedure();
					cout << "\n\t***Информация о процедурах***";
					for (int j = 0; j < docTmp[i].getCountProc(); j++)
					{
						cout << procTmp[j];
					}
					return;
				}
			}			
		}
		st.pop();
	}
}

void editProcedure(stack<Policlinic, vector<Policlinic>>* st)
{
	stack<Policlinic, vector<Policlinic>> stTmp = *st;
	Policlinic policlinic;
	Doctor tmp;
	Procedure procTmp;
	Policlinic* massTmp = new Policlinic[50];
	Doctor* massDoctorTmp = new Doctor[50];

	bool flagDoc = false,flagPol = false;
	int id,editProcID, clinicID, doctorID, counter = 0, countDoc = 0;
	char* procedureName = new char[50];

	cout << "\n\tВведите идентификационный номер поликлиники: ";
	cin >> clinicID;

	while (!stTmp.empty())
	{
		policlinic = stTmp.top();
		if (stTmp.top().getClinicID() == clinicID)
		{
			flagPol = true;
			countDoc = stTmp.top().getCountDoc();
			massDoctorTmp = stTmp.top().getDoctor();
			stTmp.pop();
			cout << "\nВведите идентификационный номер доктора: ";
			cin >> doctorID;
			for (int i = 0; i < countDoc; i++)
			{
				if (doctorID == massDoctorTmp[i].getDoctorID())
				{
					flagDoc = true;
					tmp = massDoctorTmp[i];
					cout << "\nВведите идентификационный номер редактируемой процедуры: ";
					cin >> editProcID;
					cout << "\nВведите идентификационный номер процедуры: ";
					cin >> id;
					cout << "\nВведите название процедуры: ";
					cin >> procedureName;
					procTmp.setProcedureID(id);
					procTmp.setProcedureName(procedureName);
					tmp.setProcedureID(procTmp,editProcID);
					policlinic.setDoctorID(tmp, doctorID);

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
			}
			if (!flagDoc) { cout << "\n\tДанного доктора в списке нет!" << endl; return; }
		}
		massTmp[counter] = stTmp.top();
		counter++;
		stTmp.pop();
	}
	if(!flagPol){ cout << "\n\tДанной поликлиники в списке нет!" << endl; return; }

}
