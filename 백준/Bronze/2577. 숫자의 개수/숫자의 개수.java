import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine()) * Integer.parseInt(br.readLine())*Integer.parseInt(br.readLine());
        String s = String.valueOf(num);//숫자를 문자열로 바꿈

        int [] count = new int[10]; //숫자 셀 배열

        for(int i=0; i<s.length(); i++){
            count[s.charAt(i)-'0']++;
        }

        for(int seq : count){
            System.out.println(seq);
        }
    }
}