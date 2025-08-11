import java.util.Arrays;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        int[] numbers = {2,7,11,15};

        TwoSum twoSum = new TwoSum();
        int [] answer = twoSum.twoSum(numbers, 9);
        System.out.println(Arrays.toString(answer));
    }
}