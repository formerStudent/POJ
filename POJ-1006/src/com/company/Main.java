package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	// write your code here
        int cases = 0;
        int p = 0,e = 0,i = 0;
        int t = 0;
        Scanner sc =  new Scanner(System.in);
        while(true)
        {
            cases++;
            p = sc.nextInt();
            e = sc.nextInt();
            i = sc.nextInt();
            t = sc.nextInt();
            if(p == -1&&e == -1&& i == -1&&t == -1)
                break;
            p = p%23;
            e = e%28;
            i = i%33;
            int days = t;
            for(int k = 0;;k++)
            {
                if(days<i+k*33)
                {
                    days = i+k*33;
                    break;
                }
            }
            int pr = 0,er = 0;
            while(true)
            {
                pr = (days-p)%23;
                er = (days-e)%28;
                if(pr==0&&er==0)
                {
                    if(days!=t)
                        break;
                }
                days+=33;
            }
            if(days-t>21252)
                break;
            System.out.printf("Case %d: the next triple peak occurs in %d days.\n",cases,days-t);
        }
    }
}
