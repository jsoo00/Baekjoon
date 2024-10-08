import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;

public class Main{
    static LinkedList<Character>lnklist;
    public static void main(String[]args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int TestCase = Integer.parseInt(br.readLine());
        for(int i=0; i<TestCase; i++){
            lnklist = new LinkedList<>();
            ListIterator<Character>list = lnklist.listIterator();
            String str = br.readLine();

            for(int j=0; j<str.length(); j++){
                char c = str.charAt(j);
                switch (c){
                    case '<':
                        if(list.hasPrevious())
                            list.previous();
                        break;
                    case '>':
                        if(list.hasNext())
                            list.next();
                        break;
                    case '-':
                        if(list.hasPrevious()){
                            list.previous();
                            list.remove();
                        }
                        break;
                    default:
                        list.add(c);

                }
            }
            StringBuilder sb = new StringBuilder();
            for(char s : lnklist){
                sb.append(s);
            }
            System.out.println(sb.toString());
            
        }
    }
}