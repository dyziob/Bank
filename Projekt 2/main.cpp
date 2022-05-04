#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

class Account{
    int acc_number;
    std::string acc_name, acc_surname;
    double acc_balance = 0;
    double amount = 0;

public:
    Account(){
        srand(time(NULL ));
        std::cout<<"|------------------Otwieranie konta------------------|";
        std::cout<<"\nUtworzony numer konta: ";
        acc_number = (std::rand()% 10000) + 1000;
        std::cout<< acc_number ;
        std::cout<<"\nWprowadz imie wlasciela konta: ";
        std::cin>> acc_name;
        std::cout<<"\nWprowadz nazwisko wlasciciela konta: ";
        std::cin>> acc_surname;
    }
    void acc_info(){
        std::cout<< "\n|----------------------*Informacje o koncie:*---------------------|\n";
        std::cout<< "| Numer konta: " << acc_number << "                                 \n";
        std::cout<< "| Imie: "<< acc_name << "               Nazwisko: "<< acc_surname <<"     \n";
        std::cout<< "| Stan konta: " << acc_balance <<"                                 \n";
        std::cout<< "|------------------******************************-----------------|\n";
    }
    void acc_withdraw(){
        int a;
        double total;
        std::cout<< "\n|------------------*Jaka kwote chcesz wyplacic?:*-----------------|\n";
        std::cout<< "| 1. 50 PLN                                            2. 100 PLN |\n";
        std::cout<< "| 3. 200 PLN                                           4. 500 PLN |\n";
        std::cout<< "| 5. 1000 PLN                                          6. Inna    |\n";
        std::cout<< "| 7. Powrot                                                       |\n";
        std::cout<< "|------------------******************************-----------------|\n";
        std::cin >> a;
            switch (a) {
                case 1 :
                    total = 50;
                    acc_balance -= total;
                    break;
                case 2 :
                    total = 100;
                    acc_balance -= total;
                    break;
                case 3 :
                    total = 200;
                    acc_balance -= total;
                    break;
                case 4 :
                    total = 500;
                    acc_balance -= total;
                    break;
                case 5 :
                    total = 1000;
                    acc_balance -= total;
                    break;
                case 6 :
                    std::cout << "\n Podaj kwote: ";
                    std::cin >> amount;
                    total = amount;
                    acc_balance -= total;
                    break;
                case 7:
                    system("cls");
                    break;
                default:
                    std::cout << "Zly wybor. Powrot do menu\n";
                    system("pause");
            }
    }
    void acc_deposite(){
        int a;
        double total;
        std::cout<< "\n|------------------*Jaka kwote chcesz wplacic?:*-------------------|\n";
        std::cout<< "| 1. Wplac                                            2. Wyjdz     |\n";
        std::cout<< "|------------------******************************------------------|\n";
        std::cin>> a;
        switch (a) {
            case 1 :
                std::cout << "\n Podaj kwote: ";
                std::cin >> amount;
                total = amount;
                acc_balance += total;
                break;
            case 2:
                system("cls");
                break;
            default:
                std::cout << "Zly wybor. Powrot do menu\n";
                system("pause");
        }
    }
    void acc_info_write(){
        std::ofstream file;
        file.open("Zapis_konta.txt", std::ios::out);
        file<<"Numer konta: "<<acc_number<<"\nNazwisko: "<<acc_surname<<"\nImie: "<<acc_name<<"\nStan konta: "<<acc_balance;
        std::cout << "Nastapil zapis do pliku\n";
        file.close();
    }
};

int main(){
    int choice;
    Account a;
    while(true){
        std::cout<< "\n|------------------*Wybierz jedna z opcji:*-----------------------|\n";
        std::cout<< "| 1. Informacje o koncie                     2. Wyplata pieniedzy |\n";
        std::cout<< "| 3. Wplata pieniedzy                        4. Zapis stanu konta |\n";
        std::cout<< "| 5. Wyjscie                                                      |\n";
        std::cout<< "|------------------******************************-----------------|\n";
        std::cin>>choice;
        switch (choice) {
            case 1:
                a.acc_info();
                break;
            case 2:
                a.acc_withdraw();
               break;
            case 3:
                 a.acc_deposite();
               break;
            case 4:
                a.acc_info_write();
                break;
            case 5:
                    exit(0);
            default:
                std::cout << "\nZly wybor... Wprowadz poprawna liczbe\n";
        }
    }
    return 0;
}