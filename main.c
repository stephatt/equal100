//
//  main.c
//  equal100
//
//  Created by Tong Tingting on 13-12-19.
//  import from Baidu tieba using java
//

import java.util.ArrayList;
import java.util.List;
public class sum100 {
    static final String[] sarr = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
    static final String ADD = "+";
    static final String MINUS = "-";
    static final String NUL = "";
    static final int SUM = 100;
    private int total;
    private int probable;
    void cal(String str) {
        int sum = 0;
        List<Integer> nums = new ArrayList<Integer>();
        List<Character> mark = new ArrayList<Character>();
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if ('1' <= c && '9' >= c) {
                sb.append(c);
                continue;
            }
            if ('+' == c || '-' == c) {
                nums.add(Integer.parseInt(sb.toString()));
                sb = new StringBuffer();
                mark.add(c);
            }
        }
        nums.add(Integer.parseInt(sb.toString()));
        sum = nums.get(0);
        for (int i = 0; i < mark.size(); i++) {
            switch (mark.get(i)) {
                case '+':
                    sum += nums.get(i + 1);
                    break;
                case '-':
                    sum -= nums.get(i + 1);
                    break;
            }
        }
        if (sum == SUM) {
            System.out.println(str + "=" + sum);
            System.out.println("-----------------------------------------");
            probable++;
        }
    }
    void method() {
        String[] str = new String[8];
        fo(str, 0);
        System.out.println(probable + "/" + total);
    }
    void fo(String[] str, int n) {
        for (int i = 0; i < 3; i++) {
            str[n] = itos(i);
            if (n == 7) {
                cal(mix(str));
                total++;
                if (i == 2)
                    break;
            } else {
                fo(str, n + 1);
            }
        }
    }
    String itos(int i) {
        switch (i) {
            case 0:
                return NUL;
            case 1:
                return ADD;
            case 2:
                return MINUS;
            default:
                return null;
        }
    }
    String mix(String[] str) {
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < str.length; i++) {
            sb.append(sarr[i]);
            sb.append(str[i]);
        }
        sb.append(sarr[sarr.length - 1]);
        return sb.toString();
    }
    public static void main(String[] args) {
        sum100 s = new sum100();
        s.method();
    }
}