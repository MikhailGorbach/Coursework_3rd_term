#include "Hours.h"

int SummJHours(List* l)
{
	int sum = 0;
	List* temp = l;
	while (temp)
	{
		sum += temp->p.jHours;
		temp = temp->next;
	}
	return sum;
}
int SummSHours(List* l)
{
	int sum = 0;
	List* temp = l;
	while (temp)
	{
		sum += temp->p.sHours;
		temp = temp->next;
	}
	return sum;
}
int SummH(List* l)
{
	return SummJHours(l) + SummSHours(l);;
}
float PerSHours(List* l)
{
	return ((float)SummSHours(l) / (float)SummH(l)) * 100;;
}