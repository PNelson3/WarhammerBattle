#include "UnitTester.h"



UnitTester::UnitTester()
{
	std::cout << "Testing the unit class" << std::endl;
}


UnitTester::~UnitTester()
{
	std::cout << "Done testing the unit class" << std::endl;
}

void UnitTester::RunAllTests()
{
	TestConstructorStatsNotNull();
	TestConstructorStatsNull();
}

void UnitTester::TestConstructorStatsNotNull()
{
	std::cout << "Testing the constructor with a non-null stat class.  This is for memory leak check" << std::endl;

	Stats* hi1 = new BloodLetterStats();

	Unit hello1(hi1);

	Stats* hi2 = new BloodLetterStats();

	Unit* hello2 = new Unit(hi2);

	delete hello2;

	hello2 = nullptr;
}

void UnitTester::TestConstructorStatsNull()
{
	std::cout << "Testing the constructor with NULL and nullptr.  This  is for memory leaks." << std::endl;

	Stats* hi1 = NULL;
	Stats* hi2 = nullptr;

	Unit hello1(hi1);
	Unit* hello2 = new Unit(hi2);

	//Will call stats::operation==
	std::cout << (*(hello1.stats) == (*(hello2->stats))) << std::endl;

	std::cout << "Expect 1 1 1 1 1 1 1 1 1 1 1" << std::endl;
}