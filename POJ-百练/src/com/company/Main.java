package com.company;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    public static void main(String[] args) {
	// write your code here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Map<String, Integer> m = new TreeMap<String, Integer>();
        int n = 0;
        try
        {
            n = Integer.parseInt(br.readLine());
        }catch(IOException e)
        {
            e.printStackTrace();
        }
        while(n-->0) {
            String str = "";
            String tmp = "";
            try
            {
                str = br.readLine();
            }catch(IOException e)
            {
                e.printStackTrace();
            }
            for(int i = 0;i<str.length();i++)
            {
                if(Character.isDigit(str.charAt(i)))
                    tmp += str.charAt(i);
                else
                {
                    switch (str.charAt(i))
                    {
                        case 'A':
                        case 'B':
                        case 'C':
                            tmp += 2;
                            break;
                        case 'D':
                        case 'E':
                        case 'F':
                            tmp += 3;
                            break;
                        case 'G':
                        case 'H':
                        case 'I':
                            tmp += 4;
                            break;
                        case 'J':
                        case 'K':
                        case 'L':
                            tmp += 5;
                            break;
                        case 'M':
                        case 'N':
                        case 'O':
                            tmp += 6;
                            break;
                        case 'P':
                        case 'R':
                        case 'S':
                            tmp += 7;
                            break;
                        case 'T':
                        case 'U':
                        case 'V':
                            tmp += 8;
                            break;
                        case 'W':
                        case 'X':
                        case 'Y':
                            tmp += 9;
                            break;
                        default:
                            break;
                    }
                }
            }
//            System.out.println(tmp);
            if(tmp.length()!=7)
                return;
            else
            {
                Integer count = m.get(tmp);
                if(count == null)
                    m.put(tmp,1);
                else m.put(tmp,count+1);
            }
        }
        TreeSet<String> s = new TreeSet<String>(m.keySet());
        Iterator<String> it = s.iterator();
        boolean isDuplicates = false;
        while(it.hasNext())
        {
            String tmp = it.next();
            int count = m.get(tmp);
            if(count>1)
            {
                System.out.printf("%s-%s %d\n",tmp.substring(0,3),tmp.substring(3),count);
                isDuplicates = true;
            }
        }
        if(isDuplicates == false)
            System.out.println("No duplicates.");
    }
}
