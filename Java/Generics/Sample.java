import java.util.*;
class Fruit { int i;}
class Banana extends Fruit{}
class Mango extends Fruit {}

public class Sample {
    public static <T> void copy (List<? extends T> src, List<? super T> target) {
        for (T s : src) {
            target.add(s);
        }
    }

    public static void main (String [] arg) {
        Banana banana = new Banana();
        Mango mango = new Mango();
        Fruit fruit = new Fruit();
        System.out.println(fruit.i);
        List<Fruit> fruitList = new ArrayList<>();
        List<Banana> bananaList = new ArrayList<>();
        List<Mango> mangoList = new ArrayList<>();
        fruitList.add(fruit);
        bananaList.add(banana);
        copy(bananaList, fruitList);
        copy(mangoList, fruitList);


//        copyFromFruit(fruitList, bananaList);
//        fruitList.add(mango);
        System.out.println("Fuity");
    }
}
