import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{
    public static void main(String[]args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int [] count = new int[26]; //알파벳 개수 배열
        String s = br.readLine();

        for(int i=0; i<s.length(); i++){
            char c = s.charAt(i);
            count[c-97]++; //소문자 a의 아스키코드 = 97
        }
        for(int i=0; i<26; i++)
            System.out.print(count[i]+" ");
            //System.out.print(count[i]+' '); <-이렇게 하면 왜 이상하게 나오지

    }

}