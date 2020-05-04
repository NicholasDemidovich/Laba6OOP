#pragma once
class Procedure
{
	int procedureID;
	char* procedureName = new char[50];
public:

	void setProcedureID(int procedureID) { this->procedureID = procedureID; }
	void setProcedureName(char* procedureName) { this->procedureName = procedureName; }

	int getProcedureID() { return procedureID; }
	char* getProcedureName() { return procedureName; }

	Procedure(int procedureID, char* procedureName)
	{
		this->procedureID = procedureID;
		this->procedureName = procedureName;
	}

	Procedure(){}
	~Procedure(){}
};

