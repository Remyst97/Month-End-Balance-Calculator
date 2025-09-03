# Month-End-Balance-Calculator

This is a C++ console application developed with Visual Studio. It connects to a SQL Server database to retrieve financial data (previous balance, payments, and charges) and calculates the new month-end balance for each account. The application then prints the results to the console.

Technologies

C++: The core programming language for the application.

Visual Studio: The Integrated Development Environment (IDE) used to build and run the project.

SQL Server: The database system used to store and retrieve the financial data.

MFC (Microsoft Foundation Classes): Used for database connectivity (afxdb.h) and string manipulation (CStringList).

Project Structure

Monthend_Balance.sln: The Visual Studio solution file.

Monthend_Balance.vcxproj: The Visual Studio project file with build configurations.

Monthend_Balance.cpp: The main source code file containing all the application logic.

How to Run the Project

Prerequisites

Visual Studio: You must have Visual Studio installed with the Desktop development with C++ workload.

SQL Server: You need access to a SQL Server instance with a database named MonthEndBalanceSQL and a table named MonthendTable containing the columns LastName, PreviousBalance, Payments, and Charges.

SQL Server Native Client 11.0: The project's connection string specifies this driver. Ensure it is installed on your system.

Steps

1. Clone the Repository: Clone this repository to your local machine.
```
git clone [https://github.com/YourUsername/Monthend_Balance.git](https://github.com/YourUsername/Monthend_Balance.git)
```
2. Open in Visual Studio: Open the Monthend_Balance.sln file in Visual Studio.

3. Update Connection String: Open Monthend_Balance.cpp and modify the username and Connection strings to match your specific SQL Server configuration.

4. Build the Project: In Visual Studio, go to the Build menu and select Build Solution to compile the code.

5. Run the Application: Once the build is successful, you can run the application by pressing F5 or by clicking the Start Debugging button. The application will connect to the database, perform the calculations, and display the output in a console window.
