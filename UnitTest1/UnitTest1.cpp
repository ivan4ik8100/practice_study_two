#include "pch.h"
#include "CppUnitTest.h"
#include "../Практика 1/Практика7Напарник.cpp"
#include <stdexcept> 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EducationCalcTest
{
    TEST_CLASS(EducationCalcTest)
    {
    public:
        TEST_METHOD(AverageGrade_Test_one)
        {
            int size = 4;
            double Grade[] = { 6.0, 4.0, 3.0, 4.0 };

            Assert::ExpectException<std::out_of_range>([=]()
                {
                    EducationCalc::averageGrade(Grade, size);
                }
            );
        }

        TEST_METHOD(AverageGrade_Test_two)
        {
            int size = 3;
            double Grade[] = { 5.0, 4.0, 3.0 }; 
            double expected = 4.0;
            double actual = EducationCalc::averageGrade(Grade, size);
            Assert::AreEqual(expected, actual, 0.001); 
        }

        TEST_METHOD(examPassPercentage_Test_three)
        {
            double correctAnswers = 15;
            int numberOfResponses = 20;
            int expected = 75;
            double actual = EducationCalc::examPassPercentage(correctAnswers, numberOfResponses);
            Assert::AreEqual(expected, actual, 0.001);  
        }
        TEST_METHOD(examPassPercentage_Test_four)
        {
            double correctAnswers = 50;
            int numberOfResponses = 40;
            Assert::ExpectException<std::out_of_range>([&]()
                {
                    EducationCalc::examPassPercentage(correctAnswers, numberOfResponses);
                }
            );
        }
    };
}