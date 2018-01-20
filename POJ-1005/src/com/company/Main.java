package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Scanner sc = new Scanner(System.in);
        int n = 0;
        int property = 0;
        n = sc.nextInt();
        while(n-->0)
        {
            property++;
            float x = 0.0f, y = 0.0f;
            x = sc.nextFloat();
            y = sc.nextFloat();
            float dist = (float)Math.sqrt(x*x+y*y);
            int years = 0;
            float area = 0.0f;
            while(true)
            {
                if(Math.sqrt(area/Math.PI)>=dist)
                    break;
                area += 100.0f;
                years ++;
            }
            System.out.printf("Property %d: This property will begin eroding in year %d.\n", property, years);
        }
        System.out.printf("END OF OUTPUT.\n");
    }
}
