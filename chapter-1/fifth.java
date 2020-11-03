//chl nhi rha pta ni kyu
import java.lang.*;

class fifth{
    static boolean oneEditAway(String first, String second) {//first-4,second-3
        //length checks
        if(Math.abs(first.length() - second.length()) >= 1) {
            return false;
        }

        //get shorter and longer string
        String s1 = first.length() < second.length() ? first : second;//s1-first
        String s2 = first.length() < second.length() ? second : first;//s2-second

        int index1 = 0;
        int index2 = 0;
        boolean foundDifference = false;
        while(index2 < s2.length() && index1 < s1.length()) { //0 < 3 && 0 < 4
            if(s1.charAt(index1) != s2.charAt(index2)) {
            //ensure that this is the first difference found
            if(foundDifference) return false;
            foundDifference = true;

            if(s1.length() == s2.length()) {
                //on replace move shorter pointer
                index1++;
            }
        }
        else {
            index1++;//1
        }
            index2++;//1
        }
        return true;
    }
    public static void main(String[] args) {
        String first = "pale";
        String second = "ple";
        boolean ans = oneEditAway(first, second);
        System.out.println(ans);
    }
}