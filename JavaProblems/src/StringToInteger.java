//link to leetcode: https://leetcode.com/problems/string-to-integer-atoi/solutions/7071723/java-solution-by-twiine-5z5b/

public class StringToInteger {
    public int myAtoi(String s) {
        boolean isNegative = false;
        String workingString = s.replaceFirst("^\\s+", "");
        if (workingString.startsWith("-")) {
            workingString = workingString.replaceFirst("^-", "");
            isNegative = true;
        } else if (workingString.startsWith("+")) {
            workingString = workingString.replaceFirst("^\\+", "");
        }
        workingString = workingString.replaceAll("^0+", "");
        workingString = workingString.replaceFirst("\\D.*", "");
        if(workingString.isEmpty()) {
            return 0;
        }
        long result = 0;
        try {
            result = Long.parseLong(workingString);
        } catch (NumberFormatException e) {
            return isNegative ? Integer.MIN_VALUE : Integer.MAX_VALUE;
        }
        if (isNegative) {
            result = -result;
        }
        if (result < Integer.MIN_VALUE) {
            return Integer.MIN_VALUE;
        } else if (result > Integer.MAX_VALUE) {
            return Integer.MAX_VALUE;
        }
        return (int) result;
    }
}
