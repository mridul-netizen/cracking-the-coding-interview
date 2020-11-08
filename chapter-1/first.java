//left shift ki kuch bhasodi kr rkhi inn log ne smjh ni aa rha dhang se dekhio ye code
class first{
    static boolean isUniqueChar(String str) {
        int checker = 0;
        for(int i = 0;i< str.length();i++) {
            int val = str.charAt(i) - 'a';
            if((checker & (1 << val)) > 0) {
                return false;
            }
            checker |= (1 << val);
        }
        return true;
    }
    public static void main(String[] args) {
        String s = "abcdefghijklmnopqrstuvwxyz";
        boolean ans = isUniqueChar(s);
        System.out.println(ans);
    }
}