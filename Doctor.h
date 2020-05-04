#pragma once
#include"Procedure.h"
class Doctor
{
	int doctorID;
	char* doctorSurname = new char[40];
	char* position = new char[25];

	Procedure* massProc = new Procedure[50];
	int counterProc=0;

public:

	void setDoctorID(int doctorID) { this->doctorID = doctorID; }
	void setDoctorSurname(char* doctorSurname) { this->doctorSurname = doctorSurname; }
	void setPosotion(char* position) { this->position = position; }
	void setProcedure(Procedure procedure) { massProc[counterProc] = procedure; counterProc++; }
	void setCountProc(int counterProc) { this->counterProc = counterProc; }
	void setProcedureID(Procedure procedure, int id)
	{
		for (int i = 0; i < counterProc; i++)
		{
			if (id == massProc[i].getProcedureID()) { massProc[i] = procedure; }
		}
	}

	int getDoctorID() { return doctorID; }
	char* getDoctorSurname() { return doctorSurname; }
	char* getPosition() { return position; }
	Procedure *getProcedure() { return massProc; }
	int getCountProc() { return counterProc; }

	Doctor(int doctorId, char* doctorSurname, char* position, int procedureID, char* procedureName)
	{
		this->doctorID = doctorID;
		this->doctorSurname = doctorSurname;
		this->position = position;
	}

	Doctor(){}
	~Doctor() {}
};

