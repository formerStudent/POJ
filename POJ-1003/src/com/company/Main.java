package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	// write your code here
        float c = 0.00f;
        Scanner sc = new Scanner(System.in);
        while(true)
        {
            c = sc.nextFloat();
            if(c == 0.00f)
                break;
            if(c<0.01f||c>5.20f)
                continue;
            int count = 0;
            float increNum = 2.0f;
            float totalLen = 0.00f;
            while(totalLen<c)
            {
                totalLen += 1.0f/increNum;
                increNum += 1.0f;
                count++;
            }
            System.out.printf("%d card(s)\n",count);
        }
    }
}
