import java.io.*;
import java.util.Stack;

public class Main{
    public static void main(String[]args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String str = br.readLine();
        int M = Integer.parseInt(br.readLine());
        Stack<String>leftst = new Stack<String>();
        Stack<String>rightst = new Stack<String>();

        String[] arr = str. split("");
        for(String s:arr){
            leftst.push(s); //처음 커서는 문장의 맨 뒤에서 시작하므로 왼쪽 스택에 초기 문자 다 넣기
        }
        for(int i=0; i<M; i++){
            String command = br.readLine();
            char c = command.charAt(0);

            switch(c){
                case 'L':
                    if(!leftst.isEmpty())
                        rightst.push(leftst.pop());
                    break;
                case 'D':
                    if(!rightst.isEmpty())
                        leftst.push(rightst.pop());
                    break;
                case 'B':
                    if(!leftst.isEmpty())
                        leftst.pop();
                    break;
                case 'P':
                    char t = command.charAt(2);
                    leftst.push(String.valueOf(t));
                    break;
                default:
                    break;
            }
        }
        while(!leftst.isEmpty())
            rightst.push(leftst.pop());
        while(!rightst.isEmpty())
            bw.write(rightst.pop());
        bw.flush();
        bw.close();
    }
}