package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	// write your code here
        int n = 12;
        float totalSalary = 0.00f;
        Scanner sc = new Scanner(System.in);
        while(n-->0)
        {
            float salary = sc.nextFloat();
            if(salary>1000000.00f||salary<0.00f)
                break;
            totalSalary += salary;
        }
        System.out.printf("$%.2f\n",totalSalary/12.0f);
    }
}
