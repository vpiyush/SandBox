import java.util.*;

public class Test {
    public static void main (String[] args) {
        List<String> list = new ArrayList<>();
        list.add("abc");
//        list.add(new Integer(5)); //OK

        for(Object obj : list){
            //type casting leading to ClassCastException at runtime
            String str=(String) obj;
        }
    }
}
