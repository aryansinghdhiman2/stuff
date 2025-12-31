import java.util.Arrays;
import java.util.Comparator;
import java.util.stream.Stream;


public class NewMain {
    public static void main(String[] args) {
        int[] a = {1, 2, 4, 5, 1, 2, 3};
        Arrays.stream(a).distinct().sorted()
                .forEach(System.out::println);

        String[] c = {"Hello", "World", "Blue", "Blue"};
        Stream.of(c).
                parallel().
                distinct().
//                sorted(Comparator.naturalOrder()).
                forEach(System.out::println);


    }
}
