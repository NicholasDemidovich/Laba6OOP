#pragma once
#include "Doctor.h"

class Policlinic
{
	int clinicID;
	char *clinicName = new char[30];
	char* address = new char[70];

	Doctor* massDoc = new Doctor[50];
	int counterDoc = 0;

public:

	void setClinicID(int clinicID) { this->clinicID = clinicID; }
	void setClinicName(char* clinicName) { this->clinicName = clinicName; }
	void setAddress(char* address) { this->address = address; }
	void setDoctor(Doctor doctor) { massDoc[counterDoc] = doctor; counterDoc++; }
	void setDoctorID(Doctor doctor, int id) 
	{
		for (int i = 0; i < counterDoc; i++)
		{
			if (id == massDoc[i].getDoctorID()) { massDoc[i] = doctor; }
		}
	}
	void setCountDoc(int counterDoc) { this->counterDoc = counterDoc; }

	int getClinicID() { return clinicID; }
	char* getClinicName() { return clinicName; }
	char* getAddress() { return address; }
	Doctor* getDoctor() { return massDoc; }
	int getCountDoc() { return counterDoc; }

	Policlinic(int clinicID, char* clinicName,char* address,
		int doctorId, char* doctorSurname, char* position,
		int procedureID,char* procedureName) 
	{
		this->clinicID= clinicID;
		this->clinicName = clinicName;
		this->address = address;
	}

	Policlinic(){}
	~Policlinic(){}
};

