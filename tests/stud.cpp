
#include <iostream>
#include <string>
#include <vector>

class Appearance {
    private:
        int m_hight;
        int m_weight;
        std::string m_skinColor;
        std::string m_eyeColor;
        std::string m_hairColor;

    public:
        Appearance() {}

        Appearance(
            int height,             // height of smth [cm]
            int weight,             // 
            std::string skin, 
            std::string eye, 
            std::string hair) : 
            m_hight(height), m_weight(weight), m_skinColor(skin), m_eyeColor(eye), m_hairColor(hair) {}

        void setHColor(std::string color) { m_hairColor = color; }
        void setEColor(std::string color) { m_eyeColor = color; }
        void setSColor(std::string color) { m_skinColor = color; }
        void setHight(int hight) { m_hight = hight; }
        void setWeight(int weight) { m_weight = weight; }

        std::string getHColor() { return m_hairColor; }
        std::string getEColor() { return m_eyeColor; }
        std::string getSColor() { return m_skinColor; }
        int getHight() { return m_hight; }
        int getWeight() { return m_weight; }

        friend std::ostream &operator<<(std::ostream &out, const Appearance &app)
        {
            out << "Hight:" << app.m_hight
                << "\nWeight:" << app.m_weight
                << "\nSkin color " << app.m_skinColor
                << "\nEye color " << app.m_eyeColor
                << "\nHair color " << app.m_hairColor << std::endl;
            return out;
        }
    };

class Date
{
private:
    int m_day;
    int m_month;
    int m_year;

public:
    Date() {}

    Date(int day, int month, int year) : m_day(day), m_month(month), m_year(year) {}

    void setBirth(int day, int month, int year)
    {
        m_day = day;
        m_month = month;
        m_year = year;
    }

    int getDay() { return m_day; }
    int getMonth() { return m_month; }
    int getYear() { return m_year; }

    friend std::ostream &operator<<(std::ostream &out, const Date &date)
    {
        out << "Birthday: " << date.m_day << "." << date.m_month << "." << date.m_year << std::endl;
        return out;
    }
};

class Human
{
private:
    std::string m_name;
    std::string m_surname;
    std::string m_secondname;
    int m_age;
    std::string m_citizenship;
    std::string m_placeOfResidence;
    Date m_birthday;
    Appearance m_appearance;

public:
    //Human(){}

    Human(std::string name, int age, int day, int month, int year) : m_name(name), m_age(age), m_birthday({day, month, year}) {}

    //Human(std::string name, std::string surname, std::string secondname,int age, int day, int month, int year, std::string citizenship, int hight, int weight, std::string s_color, std::string e_color, std::string h_color) :
    //    m_name(name), m_surname(surname), m_secondname(secondname), m_age(age), m_citizenship(citizenship), m_birthday({ day,month,year })
    //{
    //    //m_birthday.day = day;
    //    //m_birthday.month = month;
    //    //m_birthday.year = year;
    //    m_appearance.hight = hight;
    //    m_appearance.weight = weight;
    //    m_appearance.skinColor = s_color;
    //    m_appearance.eyeColor = e_color;
    //    m_appearance.hairColor = h_color;
    //}

    void setName(std::string s) { m_name = s; }
    void setSurname(std::string s) { m_surname = s; }
    void setSecondname(std::string s) { m_secondname = s; }
    void setAge(int age) { m_age = age; }
    /*void setBirth(int day, int month, int year) { m_birthday.day = day; m_birthday.month = month; m_birthday.year = year;}*/
    void setPlace(std::string place) { m_placeOfResidence = place; }
    void setCitizenship(std::string citizen) { m_citizenship = citizen; }
    //void setHColor(std::string color) { m_appearance.hairColor = color; }
    //void setEColor(std::string color) { m_appearance.eyeColor = color; }
    //void setSColor(std::string color) { m_appearance.skinColor = color; }
    //void setHight(int hight) { m_appearance.hight = hight; }
    //void setWeight(int weight) { m_appearance.weight = weight; }

    Валерий Яровой, [24.01.21 14 : 16] std::string getName() { return m_name; } std::string getSurname() { return m_surname; }
    std::string getSecondname() { return m_secondname; }
    std::string getCitizen() { return m_citizenship; }
    std::string getPlace() { return m_placeOfResidence; }
    //std::string getHColor() { return m_appearance.hairColor; }
    //std::string getEColor() { return m_appearance.eyeColor; }
    //std::string getSColor() { return m_appearance.skinColor; }
    //int getHight() { return m_appearance.hight; }
    //int getWeight() { return m_appearance.weight; }
    int getAge() { return m_age; }
    /* int getDay() { return  m_birthday.day; }
    int getMonth() { return  m_birthday.month; }
    int getYear() { return  m_birthday.year; }*/

    friend std::ostream &operator<<(std::ostream &out, const Human &hu)
    {
        out << "Name:\t" << hu.m_name
            << "\nSurname:\t" << hu.m_surname
            << "\nAge:\t" << hu.m_age << std::endl;
        return out;
    }
};

class Univer
{
private:
    std::string m_university;
    std::string m_faculty;
    std::string m_graduateLevel;
    int m_course;

public:
    Univer(){};

    Univer(std::string university, std::string faculty, std::string grad, int course) : m_university(university), m_faculty(faculty), m_graduateLevel(grad), m_course(course) {}

    void setUniv(std::string un)                { m_university = un; }
    void setFaculty(std::string facu)           { m_faculty = facu; }
    void setGarduateLevel(std::string level)    { m_graduateLevel = level; }
    void setCourse(int cours)                   { m_course = cours; }

    std::string getUniv() { return m_university; }
    std::string getFaculty() { return m_faculty; }
    std::string getGraduateLevel() { return m_graduateLevel; }
    int getCourse() { return m_course; }

    friend std::ostream &operator<<(std::ostream &out, const Univer &un)
    {
        out << "University:\t" << un.m_university
            << "\nFaculty:\t" << un.m_faculty
            << "\nGraduate level:\t" << un.m_graduateLevel
            << "\nCourse:\t" << un.m_course << std::endl;
        return out;
    }
};

class Student : public Human
{

private:
    Univer m_university;
    unsigned int m_id;
    double m_avarageScore;

public:
    /*Student(){}*/

    //Student(unsigned int id, std::string un, std::string facu, std::string grad, int cours, double score) :
    //    m_id(id) ,m_avarageScore(score)
    //{
    //    university.m_university = un;
    //    university.m_faculty = facu;
    //    university.m_graduateLevel = grad;
    //    university.m_course = cours;
    //}

    Student(std::string name, int age, int day, int month, int year,
            unsigned int id, Univer uni, double score) : Human(name, age, day, month, year), m_id(id), m_avarageScore(score), m_university(uni) {}

    /*void setUniv(std::string un) { university.m_university = un; }
    void setFaculty(std::string facu) { university.m_faculty = facu; }
    void setGarduateLevel(std::string level) { university.m_graduateLevel = level; }
    void setCourse(int cours) { university.m_course = cours; }*/
    void setScore(double score) { m_avarageScore = score; }
    void setId(unsigned int id) { m_id = id; }

    /* std::string getUniv() { return university.m_university; }
    std::string getFaculty() { return university.m_faculty; }
    std::string getGraduateLevel() { return university.m_graduateLevel; }
    int getCourse() { return university.m_course; }*/
    unsigned int getId() { return m_id; }
    double getScore() { return m_avarageScore; }

    friend std::ostream &operator<<(std::ostream &out, const Student &st)
    {
        out << "ID:\t" << st.m_id
            << "\nScore:\t" << st.m_avarageScore << std::endl;
        return out;
    }
};

int main()
{
    std::vector<std::string> level = {"Bachelor", "Specialist", "Master", "Aspirant", "Doctorant"};
    Student st1 = Student("Valera", 18, 10, 12, 2002, 007, Univer("NURE", "KI", level[0], 1), 89.8);

    return 0;
}