#include <iostream>
#include <string>
#include "file_reader.h"

double find_bmi(double height, double weight)
{
    double bmi;
    height = height / 100;
    bmi = weight / (height * height);
    return bmi;
}

class bmi
{
public:
    int roll;
    std::string name;
    std::string dept;
    friend std::istream &operator>>(std::istream &in, bmi &b1);

    virtual void report(float bi){};
 
};
std::istream &operator>>(std::istream &in, bmi &b1)
{

    std::cout << "ENTER ROLL NUMBER: ";
    in >> b1.roll;
    std::cout << "ENTER YOUT AGE: ";
    in >> b1.dept;
    return in;
}
class high_bmi : public bmi
{
public:
    void report(float bi) override
    {
        std::cout << "--------------------------------BMI OF " << dept << " STUDENTS--------------------------" << std::endl;
        std::cout << "-------------------------Giving you a report according to Your BMI----------------" << std::endl;
        if (bi == 25)
        {
            std::cout << "OVERWEIGHT or OBESE" << std::endl;
                  std:: cout<< "1. SHOUDL MAINTAIN A BALANCED DIET"<<std:: endl;
            std:: cout<< "2. Exercise regularly in the morning and in the afternoon."<< std:: endl;
            std:: cout<<"3. Avoid street food and heavy oily food"<< std:: endl;
        }
        else if (bi > 25 && bi < 29.9){
            std::cout << "OVERWEIGHT" << std::endl;
            std:: cout<< "1. SHOUDL MAINTAIN A BALANCED DIET"<<std:: endl;
            std:: cout<< "2. Exercise regularly in the morning and in the afternoon."<< std:: endl;
            std:: cout<<"3. Avoid street food and heavy oily food"<< std:: endl;
        }
        else if (bi >= 30)
        {
            std::cout << "BMI over 30 or higher is classified as obesity" << std::endl;
            std::cout << "* Class I obesity: BMI between 30 and 34.9" << std::endl;
            std::cout << "* Class II obesity: BMI between 35 and 39.9" << std::endl;
            std::cout << "* Class III obesity: BMI of 40 or higher (severe or morbid obesity)" << std::endl;
              std::cout << "___________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________" << std::endl;
        }
    }
};

class low_bmi : public bmi
{
public:
    void report(float bi) override
    {
        std::cout << "--------------------------------BMI OF " << dept << " STUDENTS--------------------------" << std::endl;
        std::cout << "-------------------------Giving you a report according to Your BMI----------------" << std::endl;
        std::cout << "Low BMI:" << std::endl;
        std::cout << "1.A low BMI indicates that a person's weight is below the normal range for their height." << std::endl;
        std::cout << "2.People with a low BMI may be underweight, which can be associated with health risks such as weakened immune system, nutrient deficiencies, and decreased muscle mass." << std::endl;
        std::cout << "3.To maintain a healthy BMI in the normal range, individuals with a low BMI should focus on consuming a balanced diet that provides enough calories, nutrients, and protein. Regular exercise, including strength training, can help build muscle mass and improve overall health." << std::endl;
           std::cout << "___________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________" << std::endl;
    }
};

class medium_bmi : public bmi
{
public:
    void report(float bi) override
    {
        std::cout << "--------------------------------BMI OF " << dept << " STUDENTS--------------------------" << std::endl;
        std::cout << "-------------------------Giving you a report according to Your BMI----------------" << std::endl;
        std::cout << "A medium BMI falls within the normal weight range for a person's height." << std::endl;
        std::cout << "It indicates a healthy body weight, and individuals within this range generally have a lower risk of weight-related health issues." << std::endl;
        std::cout << "To maintain a medium BMI, it is important to continue practicing healthy habits, such as eating a balanced diet that includes a variety of nutrient-dense foods and engaging in regular physical activity. Monitoring portion sizes and making mindful food choices can contribute to maintaining a healthy weight." << std::endl;
        std::cout << "___________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________" << std::endl;
    }
};

int main()
{
    std::cout << "                              WELCOME TO THE BMI CALCULATOR                            " << std::endl;
    std::cout << "****************************************CAUTION ************************************************" << std::endl;
    std::cout << "******************DATA STORED IN THE FILE IN NAME ROLL WEIGHT(KG) HEIGHT(CM)********************" << std::endl;
    int n;
    std::cout << "HOW MANY STUDENTS BMI U WANT TO CALCULATE: " << std::endl;
    std::cin >> n;
    while (n--)
    {
        bmi b1;
        std::cin >> b1;
        FileReader reader;
        std::string name;
        float weight, height;
        int roll_num = b1.roll;
        low_bmi low;
        high_bmi high;
        medium_bmi mid;
        float b;
        if (reader.getdata(roll_num, name, weight, height))
        {
            std::cout << "Name: " << name << std::endl;
            std::cout << "Roll Number: " << roll_num << std::endl;
            std::cout << "Weight: " << weight << std::endl;
            std::cout << "Height: " << height << std::endl;
            b = find_bmi(height, weight);
            std::cout << "BMI: " << b << std::endl;
            if (b >= 25)
            {
                high.report(b);
            }
            else if (b <= 24.9 && b > 18.5)
            {
                mid.report(b);
            }
            else
            {
                low.report(b);
            }
        }
        else
        {
            std::cout << "Student not found." << std::endl;
        }
    }
    return 0;
}
