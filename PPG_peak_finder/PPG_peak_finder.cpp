// PPG_peak_finder.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

int threshold;
using namespace std;
typedef unsigned short      WORD;

int main()
{
	FILE *fp = NULL;
	FILE *fp2 = NULL;

	//fp = fopen("C:\\Users\\guy92\\Desktop\\��ȭ��CNN_data_�׽�Ʈ��\\12-15 12��52��2_ppg��ȣ �׷���.csv", "r");
	fp = fopen("C:\\Users\\guy92\\Desktop\\��ȭ��CNN_data_�׽�Ʈ��\\test.csv", "r");
	char temp[100] = { 0, };
	char first[100] = { 0, };
	int max_index = 0;
	int max_PPG = 0;
	WORD min = 0;
	WORD sec = 0;
	WORD temp2[10000] = { 0, };
	WORD temp3[10000] = { 0, };
	int PPG[8000] = { 0, };
	int PPG_amp[8000] = { 0, };
	cout << "�Ӱ谪 ����: ";
	cin >> threshold;
	cout << threshold << endl << endl;
	fscanf(fp, "%s\n", temp);

	for (int i = 0; i < 8000; i++)
	{
		fscanf(fp, "%d\n", &PPG[i]);
	}

	for (int i = 0; i < 8000; i++)
	{
		PPG_amp[i] = PPG[i];
	}

	for (int i = 0; i < 8000; i++)
	{
		if (PPG[i] <= threshold) PPG[i] = 0;
	}

	for (int i = 0; i < 8000; i++)
	{
		if (PPG[i] != 0)
		{
			int j = i;
			for (; j < i + 10; j++)
			{
				if (PPG[j] > max_PPG)
				{
					max_PPG = PPG[j];
					max_index = j;
				}
				PPG[j] = 0;
			}
			i = j;
			PPG[max_index] = 1;
			max_PPG = 0;
			max_index = 0;
		}
	}

	fp2 = fopen("C:\\Users\\guy92\\Desktop\\��ȭ��CNN_data_�׽�Ʈ��\\test_w.csv", "a");

	for (int i = 0; i < 8000; i++)
	{
		fprintf(fp2, "%d, %d\n", PPG_amp[i], PPG[i]);
	}

    return 0;
}

