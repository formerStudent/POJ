package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Scanner sc = new Scanner(System.in);
        int n = 0,m = 0;
        String ctmp = sc.nextLine();
        String[] ctmps = ctmp.split(" ");
        n = Integer.parseInt(ctmps[0]);
        m = Integer.parseInt(ctmps[1]);
        String[] str = new String[m];
        int[] invertedSeq = new int[m];
        for(int i = 0; i < m; i++)
        {
            str[i] = sc.nextLine();
            char[] ch = str[i].toCharArray();
            int nA = 0,nC = 0,nG = 0;
            invertedSeq[i] = 0;
            for(int k = n-1;k>=0;k--)
            {
                switch (ch[k])
                {
                    case 'A':
                        nA++;
                        break;
                    case 'C':
                        nC++;
                        invertedSeq[i] += nA;
                        break;
                    case 'G':
                        nG++;
                        invertedSeq[i] += nC + nA;
                        break;
                    case 'T':
                        invertedSeq[i] += nG + nC + nA;
                        break;
                    default:
                        break;
                }
            }
            for(int j = i;j>0;j--)
            {
                if(invertedSeq[j]<invertedSeq[j-1])
                {
                    int tmp = invertedSeq[j];
                    invertedSeq[j] = invertedSeq[j-1];
                    invertedSeq[j-1] = tmp;
                    String cstr = str[j];
                    str[j] = str[j-1];
                    str[j-1] = cstr;
                }
            }
        }
        for(int i = 0;i<m;i++)
            System.out.printf("%s\n",str[i]);
    }
}
