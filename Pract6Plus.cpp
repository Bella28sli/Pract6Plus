#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <algorithm>
#include <random>
using namespace std;
using std::vector;




int main()
{
    double budget = 1000;

    vector<Genre> genres(10);
    vector<Audience> audiences(4);
    vector<Actor> actors(5);

    vector<Book> books(8);

    Genre genre1{ "Вестерн", 10 };
    Genre genre2{ "Романтика", 80 };
    Genre genre3{ "Триллер", 70 };
    Genre genre4{ "Фэнтези", 40 };
    Genre genre5{ "Комедия", 50 };
    Genre genre6{ "Драма", 90 };
    Genre genre7{ "Ужасы", 70 };
    Genre genre8{ "Фантастика", 40 };
    Genre genre9{ "Автобиография", 50 };
    Genre genre10{ "Боевик", 90 };
    genres.push_back(genre1);genres.push_back(genre2);genres.push_back(genre3);genres.push_back(genre4);genres.push_back(genre5);
    genres.push_back(genre6);genres.push_back(genre7);genres.push_back(genre8);genres.push_back(genre9);genres.push_back(genre10);

    Audience audience1(16, true, genre2, 70);
    Audience audience2{ 40, true, genre6, 95 };
    Audience audience3{ 23, false, genre3, 40 };
    Audience audience4{ 56, false, genre5, 67 };
    audiences.push_back(audience1);audiences.push_back(audience2);audiences.push_back(audience3); audiences.push_back(audience4);

    Actor actor1{ "Джонни Депп", false, 95, 60, false, genre4, 100 };
    Actor actor2{ "Тимоти Шаламе", false, 78, 28, false, genre6, 100 };
    Actor actor3{ "Зендея", false, 69, 27, true, genre2, 100 };
    Actor actor4{ "Эмма Томпсон", false, 79, 65, true, genre6, 100 };
    Actor actor5{ "Джим Керри", false, 88, 62, false, genre5, 100 };
    actors.push_back(actor1); actors.push_back(actor2);actors.push_back(actor3); actors.push_back(actor4);actors.push_back(actor5);


    vector<Genre> book1list(2); static vector<Genre> book2list(2);
    vector<Genre> book3list(3); static vector<Genre> book4list(2);
    vector<Genre> book5list(2); static vector<Genre> book6list(2);
    vector<Genre> book7list(3); static vector<Genre> book8list(3);

    book1list.push_back(genre8); book1list.push_back(genre10);
    book2list.push_back(genre9); book2list.push_back(genre5);
    book3list.push_back(genre1); book3list.push_back(genre6);book3list.push_back(genre10);
    book4list.push_back(genre2); book4list.push_back(genre6);
    book5list.push_back(genre5); book5list.push_back(genre7);
    book6list.push_back(genre4); book6list.push_back(genre2);
    book7list.push_back(genre8); book7list.push_back(genre3);book7list.push_back(genre7);
    book8list.push_back(genre10); book8list.push_back(genre4);book8list.push_back(genre6);

    Book book1{ "Звезда на Марсе", book1list, 0, audience1 };
    Book book2{ "Во всём виноват Дима", book2list, 16, audience2 };
    Book book3{ "Ураган перекати-поле", book3list, 18, audience4 };
    Book book4{ "Покуда обещание в силе", book4list, 16, audience2 };
    Book book5{ "10 ошибок Боба Лафгуд", book5list, 12, audience4 };
    Book book6{ "Её Высочество Мия", book6list, 0, audience1 };
    Book book7{ "Дары плесени", book7list, 21, audience3 };
    Book book8{ "Мох", book8list, 21, audience3 };


    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    string choice;

    do {
        cout << "Добро пожаловать!\nВаша цель: успешно показать фильм. Обращайте внимание на соответствие в предпочтениях и популярность.\nЧто хотите сделать?";
        cout << "\n1. Создать фильм\n2. Узнать подробнее об Актёрах\n3. Узнать подробнее про ЦА\n4. Узнать подробнее про книги\n5. Узнать популярность жанров\n6. Узнать бюджет компании\n7. Показать фильм";
        cin >> choice;

        if (choice == "1") {
        }
        else if (choice == "2") {
        }
        else if (choice == "3") {
        }
        else if (choice == "4") {
        }
        else if (choice == "5") {
        }
        else if (choice == "6") {
            ReturnBudget(budget);
        }
        else if (choice == "7") {
        }
        else {
            cout << "Введите число от 1 до 7";
        }

    } while (true);
}

void ReturnBudget(int budget) {
    cout << "\nВаш бюджет: " << budget;
}

class Genre {
public:
    Genre(string genreName, int genrePopularity)
    {
        this->genreName = genreName;
        this->genrePopularity = genrePopularity;
    }

    string genreName;
    int genrePopularity;
};

class Audience
{
public:
    Audience(int age, bool gender, Genre favGenre, int loyalty) : favGenre(favGenre)
    {
        this->age = age;
        this->gender = gender;
        this->favGenre = favGenre;
        this->loyalty = loyalty;
    }

    int age;
    bool gender;
    int loyalty;
    Genre favGenre;
};

class Actor : Audience
{
public:
    Actor(string name, bool ignore, int popularity, int age, bool gender, Genre favGenre, int loyalty) : Audience(age, gender, favGenre, loyalty)
    {
        this->name = name;
        this->ignore = ignore;
        this->popularity = popularity;
    }

    string name;
    bool ignore;
    int popularity;
};

class Book {
public:
    Book(string title, vector<Genre> genreList, int ageRestriction, Audience targetAudience) : TargetAudience(targetAudience)
    {
        this->Title = title;
        this->GenreList = genreList;
        this->AgeRestriction = ageRestriction;
        this->TargetAudience = targetAudience;
    }

protected:
    string Title;
    vector<Genre> GenreList;
    int AgeRestriction;
    Audience TargetAudience;
};

class Movie : Book
{
public:
    Actor mainActor;
    int successChance;

    Movie(string title, vector<Genre> genreList, int ageRestriction, Actor mainActor, Audience targetAudience, int successChance) : Book(title, genreList, ageRestriction, targetAudience), mainActor(mainActor)
    {
        this->mainActor = mainActor;
        this->successChance = successChance;
    };
};