class second{

    static boolean permutation(String s, String t) {
        if(s.length() != t.length()) {//if length not equal then return false
            return false;
        }

        int[] letters = new int[128];//making a new int array of size 128 contaning character count

        char[] s_array = s.toCharArray();//converting god into a character array
        for(char c: s_array) { //count no. of each char in s
            letters[c]++;//increment value of ascii at that place=>God and dog would return false but dog and god would return true
        }

        for(int i = 0;i < t.length();i++) {
            int c = (int) t.charAt(i);//parsing the character at ith index in string t into integer and storing it into an int c
            //decrementing value at that index => at first iteration d becomes 0 then o becomes zero
            letters[c]--;
            if(letters[c] < 0) {
                return false;//so if value of c is negative then return false else iterate again
            }//at end of loop just return true coz all conditions satisfied
        }
        return true;
    }
    public static void main(String[] args) {
        boolean ans = permutation("gdod","dogd");
        System.out.println(ans);
    }
}