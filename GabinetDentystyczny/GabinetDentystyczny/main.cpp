#include <iostream>
#include <chrono>
#include <ctime>
#include <stdlib.h>

/*
#include "mysql_connection.h"
#include "cppconn/driver.h"
#include "cppconn/exception.h"
#include "cppconn/resultset.h"
#include "cppconn/statement.h"
*/

using namespace std;
std::string Login, Haslo, Wynik;
int liczbaProb = 0;
int maksymalnaIloscProb = 3;

void wyswietlDateGodzine();
void wyswietlMenuAdministracja();
void wyswietlMenuLekarz();
void logowanieDoSystemu();
//void testowaniePolaczenia();

int main()
{
    do
    {
        std::cout << "---------- WITAMY w GABINECIE STOMATOLOGICZNYM ----------" << std::endl;
		std::cout << "----------- P - R - O - D - E - N - T - A - L -----------\n" << std::endl;

        wyswietlDateGodzine();
        logowanieDoSystemu();

		if ((Login == "Wolska") && (Haslo == "1234"))
        {
            std::cout << "\nPrawidlowe logowanie do systemu\n" << std::endl;

            Wynik = "P";
            system("pause");
            system("cls");

            std::cout << "ZALOGOWANY UZYTKOWNIK: " << Login << " NA STANOWISKU: " << "###Tutaj powinno wyswietlic sie stanowisko###" << std::endl;
            std::cout << "\nWybierz dzialanie z menu programu\n" << std::endl;

            wyswietlMenuAdministracja();
        }
            else
            {
                liczbaProb++;
                std::cout << "\nBledne dane logowania. Sprobuj ponownie" << std::endl;
                std::cout << "\nZostalo: " << maksymalnaIloscProb - liczbaProb <<" prob logowania"<< std::endl;

                Wynik = "F";
                system("pause");
                system("cls");
            }
        }

	while (Wynik != "P" && liczbaProb < maksymalnaIloscProb);
}

void wyswietlDateGodzine()
{
auto end = std::chrono::system_clock::now(); //zwraca wartosc zegara systemowego
std::time_t end_time = std::chrono::system_clock::to_time_t(end); //konwersja na date i godzine

std::cout << "Dzisaj jest: " << std::ctime(&end_time) << std::endl;
}

void wyswietlMenuLekarz()
{
std::cout << "1. Wyœwietl harmonmogram wizyt." << std::endl
        << "2. Dodaj komentarz do wizyty." << std::endl
        << "3. Diagram godzin pracy." << std::endl
        << "4. Zglaszanie dni wolnych od pracy." << std::endl
        << "5. Wyœwietl karte pacjenta." << std::endl
        << "6. Przeglad formularzy i zgod." << std::endl
        << "7. Wystawienie e-recepty." << std::endl
        << "8. Sprawdz premie za uslugi." << std::endl
        << "0. WYJSCIE Z PROGRAMU" << std::endl;
}

void wyswietlMenuAdministracja()
{
std::cout << "1. Dodaj pacjenta do bazy danych" << std::endl
		<< "2. Wyszukaj pacjenta w bazie danych" << std::endl
		<< "3. Rezerwacja wizyty stomatologicznej" << std::endl
		<< "4. Harmonogram pracy" << std::endl
		<< "5. Zaopatrzenie gabinetu w materialy medyczne" << std::endl
		<< "6. Place i finanse" << std::endl
		<< "7. Tworzenie raportow" << std::endl
		<< "0. WYJSCIE Z PROGRAMU" << std::endl;
}

void logowanieDoSystemu()
{
std::cout << "ZALOGUJ SIE DO SYSTEMU\n";
std::cout << "\nLogin: ";
std::cin >> Login;
std::cout << "Haslo: ";
std::cin >> Haslo;
}

/*
void testowaniePolaczenia()
{
try {
  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  sql::ResultSet *res;

  driver = get_driver_instance();
  con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
  con->setSchema("test");

  stmt = con->createStatement();
  res = stmt->executeQuery("SELECT 'Hello World!' AS _message"); //testowa wiadomosc
  while (res->next()) {
    cout << "\t... MySQL replies: ";
    cout << res->getString("_message") << endl;
    cout << "\t... MySQL says it again: ";
    cout << res->getString(1) << endl;
  }
  delete res;
  delete stmt;
  delete con;

} catch (sql::SQLException &e) {
  cout << "#ERR: SQLException in " << __FILE__;
  cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
  cout << "#ERR: " << e.what();
  cout << " (MySQL error code: " << e.getErrorCode();
  cout << ", SQLState: " << e.getSQLState() << " )" << endl;
}

cout << endl;
}
*/
