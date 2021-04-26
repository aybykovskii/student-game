#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

void red(){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, 4);
}
void white(){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, 7);
}
void yellow(){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, 6);
}
void green(){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, 2);
}
void instruction(){
    cout << "Привет, меня зовут Алексей Быковский и я создатель этой мини-игры!" << endl
        << "Сейчас я вкратце расскажу тебе инструкцию :)" << endl
        << "В первых пяти вопросах тебе будет предложено задать начальные параметры своего персонажа," << endl
        << "задай их в пределах от "; red(); cout << 0; white(); cout << " до "; green(); cout << 100; white(); cout << ".  :-*" << endl
        << "После тебе будет предложено ввести Имя и Фамилию для твоего персонажа." << endl
        << "Ты сожешь сделать это как на русском, так и на английском языке :)" << endl
        << "Потом ты можешь ввести любое количество действий, которое захочешь, но учти," << endl
        << "произвести больше действий, чем ты задал, увы, не получится(((" << endl
        << "Позже ты можешь вводить любую из команд, список которых ты увидишь на экране," << endl
        << "но вводить их можно только на английском(русификация будет, я над этим работаю :) )" << endl;
    cout << "Вот собственно и все, что я хотел тебе сказать :-)" << endl << endl; yellow();
    cout << "Желаю приятной игры!!!" << endl << endl; white();
    cout << "P.S.                               "; red(); cout << "      /\\/\\    " << endl; white();
    cout << "Забыл сказать, я люблю Дашулю Тюличкову!"; red(); cout << " \\  / " << endl
        << "                                          \\/ " << endl; white();
    cout << "Если все понял, нажми Enter и добро пожаловать...";
    string line;
    getline(cin, line);
    system("cls");
    cout << "Loading";
    for (int i = 0; i < 15; ++i)
    {
        Sleep(500);
        cout << ".";
    }
    system("cls");
}
void action_list(){
    cout << "Возможные действия:" << endl << "1) sleep" << endl << "2) study" << endl
        << "3) eat" << endl << "4) wait" << endl << "5) watch TV" << endl;
    cout << "(Напишите stop, если хотите перестать играть)" << endl << endl;
    cout << "Что желаете сделать с персонажем?" << endl;
    cout << "(Необходимо написать слово)" << endl;
}
class Student {
private:
    char name[51];
    char surname[51];
    int energy;
    int iq;
    int sanity;
    int exci;
    int hp;
    void change_field(int& field, int delta);
    void change_params(int d_hp, int d_energy, int d_iq, int d_sanity, int d_exci);
    void apply_effect();
public:
    bool is_alive();
    void show();
    void eat();
    void wait();
    void study();
    void sleep();
    void watch_tv();
    void show_bar(int x);
    Student(int hp,
        int energy,
        int iq,
        int sanity,
        int exci);
};
Student::Student(int hp, int energy, int iq, int sanity, int exci){
    cout << "Как будут звать вашего персонажа?   ";
    cin >> name;
    system("cls");
    cout << "Какая у него будет фамилия?   ";
    cin >> surname;
    system("cls");
    this->energy = energy;
    this->hp = hp;
    this->iq = iq;
    this->sanity = sanity;
    this->exci = exci;
}
void Student::change_field(int& field, int delta){
    if (field + delta > 0 && field + delta < 101) field += delta;
    else if (field + delta <= 0) field = 0;
    else if (field + delta >= 100) field = 100;
}
void Student::change_params(int d_hp, int d_energy, int d_iq, int d_sanity, int d_exci){
    change_field(this->hp, d_hp);
    change_field(this->energy, d_energy);
    change_field(this->iq, d_iq);
    change_field(this->sanity, d_sanity);
    change_field(this->exci, d_exci);
}
bool Student::is_alive(){
    return (hp > 0 ? 1 : 0);
}
void Student::show(){
    if (is_alive()){
        cout << name << " " << surname << endl;
        cout << setw(11) << setfill(' ') << "HP:"; show_bar(hp);
        cout << setw(11) << setfill(' ') << "Energy:"; show_bar(energy);
        cout << setw(11) << setfill(' ') << "IQ:"; show_bar(iq);
        cout << setw(11) << setfill(' ') << "Sanity:"; show_bar(sanity);
        cout << setw(11) << setfill(' ') << "Excitement:"; show_bar(exci);
        cout << endl << endl;
    }
    else{
        cout << "GAME OVER!!!" << endl;
        cout << "FOR WHAT YOU KILL YOUR HUMAN????" << endl << endl;
    }
}
void Student::eat(){
    if (!is_alive()) return;
    change_params(1, 7, -1, 0, -2);
    apply_effect();
}
void Student::wait(){
    if (!is_alive()) return;
    change_params(1, -3, 0, 0, -3);
    apply_effect();
}
void Student::study(){
    if (!is_alive()) return;
    change_params(-2, -4, 5, -5, -2);
    apply_effect();
}
void Student::sleep(){
    if (!is_alive()) return;
    change_params(2, -2, 0, 7, 0);
    apply_effect();
}
void Student::watch_tv(){
    if (!is_alive()) return;
    change_params(-2, -3, -3, 1, 5);
    apply_effect();
}
void Student::apply_effect(){
    if (energy == 0)
        change_field(hp, -25);
    if (energy == 100)
        change_field(hp, -10);
    if (sanity <= 10)
        change_field(hp, -(15 - sanity));
    if (exci < 25)
        change_field(sanity, -5);
}
void Student::show_bar(int x){
    cout << " [";
    for (int i = 0; i < x; ++i)
    {
        if (i <= 30)
            red();
        else if (i > 30 && i < 70)
            yellow();
        else
            green();
        cout << "=";
    }
    white();
    for (int i = 0; i < (100 - x); ++i)
        cout << " ";
    cout << "] ";
    cout << setw(3) << setfill('0') << x << "/100" << endl;
}
int main() {
    setlocale(LC_ALL, "Rus");
    int hp, ener, iq, sanity, exci;
    instruction();

    cout << "Сколько HP будет у вашего персонажа?  ";
    cin >> hp;
    system("cls");
    cout << "Сколько энергии будет у вашего персонажа?  ";
    cin >> ener;
    system("cls");
    cout << "Какой IQ будет у вашего персонажа?  ";
    cin >> iq;
    system("cls");
    cout << "Какой уровень здравомыслия будет у вашего персонажа?  ";
    cin >> sanity;
    system("cls");
    cout << "Какой уровень настроения будет у вашего персонажа?  ";
    cin >> exci;
    system("cls");

    Student u1(hp, ener, iq, sanity, exci);
    int m;
    cout << "Сколько действий хотите произвести с персонажем?  ";
    cin >> m;
    string s;
    cout << "Loading";
    for (int i = 0; i < 5; ++i){
        Sleep(500);
        cout << ".";
    }

    for (int i = 0; i < m + 1; ++i){
        action_list();
        getline(cin, s);
        system("cls");
        if (s[0] == 'w'){
            if (s[2] == 'i'){
                u1.wait();
                u1.show();
            }
            else{
                u1.watch_tv();
                u1.show();
            }
        }
        if (s[0] == 'e'){
            u1.eat();
            u1.show();
        }
        if (s[0] == 's'){
            if (s[1] == 't'){
                if (s[2] == 'u'){
                    u1.study();
                    u1.show();
                }
                else{
                    cout << "Already leaving??" << endl; Sleep(1000);
                    cout << " We are crying!" << endl; Sleep(1000); cout << endl;
                    cout << "Итоги игры: " << endl; Sleep(1000);
                    cout << "Loading";
                    for (int i = 0; i < 5; ++i){
                        Sleep(500);
                        cout << ".";
                    }
                    system("cls");
                    u1.show();
                    break;
                }
            }
            else{
                u1.sleep();
                u1.show();
            }
        }
        if (!u1.is_alive())
            break;
    }
    
    cout << "Thanks for playing!" << endl
        << "Waiting for you again  :-*  " << endl << endl;

    return 0;
}
