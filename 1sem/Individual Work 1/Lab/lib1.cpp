#include "lib1.h"

// Â çàïèñè ñêîëüêèõ ÷èñåë ïîñëåäíÿÿ öèôğà áîëüøå íå ïîâòîğÿåòñÿ íè
// ğàçó. Êàêîå èç íå÷åòíûõ ÷èñåë èìååò ìàêñèìàëüíóş ñóììó öèôğ, åñëè
// òàêèõ ÷èñåë íåñêîëüêî – òî ïåğâîå èç íèõ

// ßíà Ìèõàéëîâíà ğåêîìåíäîâàëà ïåğåäàâàòü äâà óêàçàòåëÿ íà íà÷àëî
// è êîíåö ìàññèâà, êàê õîğîøóş ïğàêòèêó ğàáîòû ñ ìàññèâàìè
// Ôóíêöèÿ íå èñïîëüçóåòñÿ, ïğîñòî îñòàâèë
int CountLastDigitNotRepeat(int* start, int* end) {
	int counter = 0;
	for (int *pt = start; pt != end; pt++) {
		if (IsLastDigitNotRepeat(*pt)) {
			counter++;
		}
	}
	return counter;
}

bool IsLastDigitNotRepeat(int number) {
	number = abs(number);
	int lastDigit = number % 10;
	number /= 10;
	while (number > 0) {
		if (number % 10 == lastDigit)
			return false;
		number /= 10;
	}
	return true;
}

// Ôóíêöèÿ íå èñïîëüçóåòñÿ, ïğîñòî îñòàâèë
int MaxSumOfOdd(int* start, int* end) {
	int num = 0;
	int maxSum = 0;
	int currSum;
	for (int* pt = start; pt != end; pt++) {
		if (*pt % 2 == 0) continue;
		currSum = SumOfDigits(*pt);
		if (currSum > maxSum) {
			maxSum = currSum;
			num = *pt;
		}
	}
	return num;
}

int SumOfDigits(int number) {
	number = abs(number);
	int sum = 0;
	while (number > 0) {
		sum += number % 10;
		number /= 10;
	}
	return sum;
}
