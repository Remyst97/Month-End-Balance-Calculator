#include <stdlib.h>

#include <iostream>
#include <iomanip>
using namespace std;

#include "afxwin.h"
#include <afxdb.h>

void compute(double number[6][6]);
void addcolumns(double number[6][6], double totalarrays[]);
void printdata(CStringList& lastnamelist, double number[6][6]);
void printtotals(double totalarrays[]);

#pragma unmanaged

int main()
{
    system("cls");
    system("Color 70");

    CString Connection;
    CDatabase database;

    CString username;
    CString password;

    username = "servername\\user\\Remy";
    Connection = _T("Driver={SQL Server Native Client 11.0};Server=name\\user;Database=MonthEndBalanceSQL;Trusted_Connection=Yes;Uid=") + username + _T(";Pwd=") + password + _T(";");

    database.OpenEx(Connection, CDatabase::useCursorLib);

    CString query = "SELECT LastName, PreviousBalance, Payments, Charges FROM MonthendTable";

    CRecordset recordset(&database);
    CString temp, record;
    recordset.Open(CRecordset::forwardOnly, query, CRecordset::readOnly);

    CString  lastname, spreviousbalance, spayments, scharges;
    CStringList lastnamelist;

    double previousbalance, payments, charges;
    double number[6][6];

    int col = 0, row = 0;


    while (!recordset.IsEOF())
    {
        record = _T("");
        register int len = recordset.GetODBCFieldCount();

        recordset.GetFieldValue("LastName", lastname);

        recordset.GetFieldValue("PreviousBalance", spreviousbalance);
        recordset.GetFieldValue("Payments", spayments);
        recordset.GetFieldValue("Charges", scharges);


        lastnamelist.AddHead(lastname);


        col = 0;

        previousbalance = atof(spreviousbalance);
        number[row][col] = previousbalance;

        payments = atof(spayments);
        number[row][++col] = payments;

        charges = atof(scharges);
        number[row][++col] = charges;

        row = row + 1;

        recordset.MoveNext();

    }

    double totalarrays[6];

    compute(number);
    addcolumns(number, totalarrays);
    printdata(lastnamelist, number);
    printtotals(totalarrays);
    cout << endl << endl;

    return 0;
}


void compute(double number[6][6])
{
    double previousbalance, payments, charges;
    double nbalance, financecharge, mebalance;

    int i = 0;

    for (int j = 0; j < 6; j++)
    {
        for (i = 0; i < 3; i++)
        {
            if (i == 0)
                previousbalance = number[j][i];

            if (i == 1)
                payments = number[j][i];

            if (i == 2)
                charges = number[j][i];
        }
        nbalance = previousbalance - payments + charges;
        financecharge = nbalance * .12;
        mebalance = nbalance + financecharge;

        number[j][i] = nbalance;
        number[j][++i] = financecharge;
        number[j][++i] = mebalance;
    }

}

void addcolumns(double  number[6][6], double totalarrays[])
{
    double value = 0;
    double totalvalue = 0;

    for (int x = 0; x < 6; x++)
    {
        totalvalue = 0;

        for (int y = 0; y < 6; y++)
        {
            value = number[y][x];
            totalvalue += value;
        }

        totalarrays[x] = totalvalue;
    }

}

void printdata(CStringList& lastnamelist, double number[6][6])
{
    POSITION pos = lastnamelist.GetTailPosition();
    CString lastname = lastnamelist.GetPrev(pos);

    int count = lastnamelist.GetCount();

    for (int i = 0; i < count; i++)
    {
        cout << setw(11) << lastname;

        for (int j = 0; j < 6; j++)
        {
            cout << setw(11) << number[i][j];
        }

        cout << endl;

        if (i < count - 1)
        {
            lastname = lastnamelist.GetPrev(pos);

        }
    }


}


void printtotals(double totalarrays[])
{
    cout << endl;

    for (int z = 0; z < 6; z++)
    {
        if (z == 0)
            cout << setw(37) << totalarrays[z] << " ";
        else
        {
            cout << setw(11) << totalarrays[z] << " ";
        }
    }


}

