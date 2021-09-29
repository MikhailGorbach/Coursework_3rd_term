#pragma once
#include <string>
#include <iostream>
using namespace std;

struct Inf
{
	string ñodeGr;
	string surname;
	int year;
	bool gender;
	int sHours;
	int jHours;
	int id;
};
struct List
{
	Inf p;
	List* next;
};