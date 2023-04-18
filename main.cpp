#include <iostream>
#include <cmath>
#include <cstdlib>


const char banner_text[] = "  ____                            _          _____ _ _                                _ \n / ___|  ___  _____   _____ _ __ | |_ __ _  |  ___(_| |__   ___  _ __   __ _  ___ ___(_)\n \\___ \\ / _ \\/ __\\ \\ / / _ | '_ \\| __/ _` | | |_  | | '_ \\ / _ \\| '_ \\ / _` |/ __/ __| |\n  ___) |  __| (__ \\ V |  __| | | | || (_| | |  _| | | |_) | (_) | | | | (_| | (_| (__| |\n |____/ \\___|\\___| \\_/ \\___|_| |_|\\__\\__,_| |_|   |_|_.__/ \\___/|_| |_|\\__,_|\\___\\___|_|\n\n";
const char menu_text[] = "[1] iterativ \t[2] recursiv \t[3] formula lui binet\n[4] four \t[5] five \t[6] six\n[7] seven \t[8] eight \t[9] nine\n[0] exit\n";
const double sqrt_5 = 2.2360679775;

void print_menu();
void clear_screen();
void pause_program();

void iterative(int n);
void recursive(int n);
long long recursive_utility(int n);
void binet_formula(int n);


int main()
{
    int option, n;

    while (true)
    {
        clear_screen();
        print_menu();
        std::cout << "\n> ";
        std::cin >> option;

        if (option == 0) return 0;

        clear_screen();
        std::cout << "N = ";
        std::cin >> n;

        clear_screen();
        switch (option)
        {
            case 1:
                iterative(n);
                break;
            case 2:
                recursive(n);
                break;
            case 3:
                binet_formula(n);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;

            default:
                break;
        }

        pause_program();
    }
}

void print_menu()
{
    std::cout << banner_text << menu_text;
}

void clear_screen()
{
    // for linux
    std::system("clear");

    //for windows
    //std::system("cls");
}

void pause_program()
{
    char temp;
    std::cout << "\n[0] back\n> ";
    std::cin >> temp;
}

void iterative(int n)
{
    const char iterative_text[] = "void fib(int n)\n{\n\tlong long a = 0, b = 1, c;\n\tfor(int i = 0; i < n; ++i)\n\t{\n\t\tstd::cout << a << ' ';\n\t\tc = a + b;\n\t\ta = b;\n\t\tb = c;\n\t}\n}\n";

    std::cout << iterative_text << '\n' << "N = " << n << '\n';

    long long a = 0, b = 1, c;
    for(int i = 0; i < n; ++i)
    {
        std::cout << a << ' ';
        c = a + b;
        a = b;
        b = c;
    }
    std::cout << '\n';
}

void recursive(int n)
{
    const char recursive_text[] = "long long fib(int n)\n{\n\tif (n <= 1)\n\t\treturn n;\n\n\treturn fib(n - 1) + fib(n - 2);\n}\n";

    std::cout << recursive_text << '\n' << "N = " << n << '\n';

    std::cout << "fib(" << n << ") = " << recursive_utility(n) << '\n';
}

long long recursive_utility(int n)
{
    if (n <= 1)
        return n;
    
    return recursive_utility(n - 1) + recursive_utility(n - 2);
}

void binet_formula(int n)
{
    const char binet_text[] = "long long binet(int n)\n{\n\treturn int((pow(1 + sqrt(5), n) + pow(sqrt(5) - 1, n)) / (pow(2, n) * sqrt(5)));\n}\n";

    std::cout << binet_text << '\n' << "N = " << n << '\n';

    std::cout << "binet(" << n << ") = " << int((pow(1 + sqrt_5, n) + pow(sqrt_5 - 1, n)) / (pow(2, n) * sqrt_5)) << '\n';
}