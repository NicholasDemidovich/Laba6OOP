#include "stdio.h"
#include <iostream>
#include "Verification.h"
#include <stack>
#include <vector>
#include <queue>
#include "Policlinic.h"
#include "Client.h"
#include "PoliclinicFunc.h"
#include "DoctorFunc.h"
#include "ProcedureFunc.h"
#include "ClientFunc.h"
#include "DoctorAppointment.h"



void main()
{
    using namespace std;
    setlocale(LC_ALL, "Russian");

    stack<Policlinic, vector<Policlinic>> *policlinic = new stack<Policlinic, vector<Policlinic>>;
    queue<Client, deque<Client>> *client = new queue<Client, deque<Client>>;
    priority_queue<DoctorAppointment, vector<DoctorAppointment>>* appointment = new priority_queue<DoctorAppointment, vector<DoctorAppointment>>;

    int sw;
    while (true)
    {
    mainMenu:
        system("cls");
        cout << "0 - Выход;"
            << "\n1 - Администратор; "
            << "\n2 - Клиент: ";
        cin >> sw;
        if (sw == 0)return;
        if (sw == 1)
        {
            if (verificationAdmin())
            {
                while (true)
                {
                    system("cls");
                    cout << "0 - Переход на верхний уровень;"
                        << "\n1 - Добавить поликлинику;"
                        << "\n2 - Вывести список поликлиник;"
                        << "\n3 - Добавить врача;"
                        << "\n4 - Вывести список врачей;"
                        << "\n5 - Добавить процедуру;"
                        << "\n6 - Вывести список процедур;"
                        << "\n7 - Редкатировать врача;"                        
                        << "\n8 - Редактировать процедуру;";
                    cin >> sw;
                    switch (sw)
                    {
                    case 0:goto mainMenu;
                    case 1:
                        system("cls");
                        addPoliclinic(policlinic);
                        system("pause");
                        break;
                    case 2:
                        system("cls");
                        showPoliclinicList(*policlinic);
                        system("pause");
                        break;
                    case 3:
                        system("cls");
                        addDoctor(policlinic);
                        system("pause");
                        break;
                    case 4:
                        system("cls");
                        showDoctorList(*policlinic);
                        system("pause");
                        break;
                    case 5:
                        system("cls");
                        addProcedure(policlinic);
                        system("pause");
                        break;
                    case 6:
                        system("cls");
                        showProcedureList(*policlinic);
                        system("pause");
                        break;
                    case 7:
                        system("cls");
                        editDoctor(policlinic);
                        system("pause");
                        break;
                    case 8:
                        system("cls");
                        editProcedure(policlinic);
                        system("pause");
                        break;
                    default:cout << "Error!"; break;
                    }
                }
            }
            else { goto mainMenu; }
        }
        if (sw == 2)
        {
            while (true)
            {
                system("cls");
                cout << "0 - Переход на верхний уровень;"
                    << "\n1 - Вывести список поликлиник;"
                    << "\n2 - Зарегистрироваться в поликлинике;"
                    << "\n3 - Записаться на прием:";
                cin >> sw;
                switch (sw)
                {
                case 0:goto mainMenu;
                case 1:
                    system("cls");
                    showPoliclinicList(*policlinic);
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    registerClient(client);
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    makeAppointment(*client,appointment);
                    system("pause");
                    break;
                default:cout << "Error!"; break;
                }
            }
        }
    }



}