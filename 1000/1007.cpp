#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <iostream>
using namespace std;

int main()
{
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);
	//char **input = new char*[m];
	char **input;
	input = (char**)malloc(sizeof(char*)*m);
	//int *invertedSeq = new int[m];
	int *invertedSeq;
	invertedSeq = (int*)malloc(sizeof(int)*m);
	for (int k = 0; k < m; k++)
	{		
		//input[k] = new char[n + 1]{ '\0' };
		input[k] = (char*)malloc(sizeof(char)*(n + 1));
		scanf("%s", input[k]);
		int nA = 0, nT = 0, nC = 0, nG = 0;
		char *in = input[k];
		invertedSeq[k] = 0;
		for (int i = strlen(in); i >= 0; i--)
		{
			switch (in[i])
			{
			case 'A':
				nA++;
				break;
			case 'C':
				nC++;
				invertedSeq[k] += nA;
				break;
			case 'G':
				nG++;
				invertedSeq[k] += nA + nC;
				break;
			case 'T':
				nT++;
				invertedSeq[k] += nA + nC + nG;
			default:
				break;
			}
		}
		for (int j = k; j > 0; j--)
		{
			if (invertedSeq[j] < invertedSeq[j - 1])
			{
				int tmp = invertedSeq[j];
				invertedSeq[j] = invertedSeq[j - 1];
				invertedSeq[j - 1] = tmp;
				char *ctmp = input[j];
				input[j] = input[j - 1];
				input[j - 1] = ctmp;
			}
		}
	}

	for (int i = 0; i < m; i++)
		printf("%s\n", input[i]);
}