class sixth{
    static void compress(String str) {
        //check final length and return input string if it would be longer
        int finalLength = countCompression(str);
        if(finalLength >= str.length()) return;
        StringBuilder compressed = new StringBuilder(finalLength);
        int countConsecutive = 0;
        for(int i = 0; i < str.length(); i++) {
            countConsecutive++;
        
        //if next char is different than current then append this char to result
        if(i+1 >= str.length() || str.charAt(i) != str.charAt(i+1)) {
            compressed.append(str.charAt(i));
            compressed.append(countConsecutive);
            countConsecutive = 0;
        }
    }
        System.out.println(compressed.toString()); 
    }

    static int countCompression(String str) {
        int compressedLength = 0;
        int countConsecutive = 0;

        for(int i = 0; i < str.length(); i++) {
            countConsecutive++;

            //if next char is different than the current,increase the length
            if(i+1 >= str.length() || str.charAt(i) != str.charAt(i+1)) {
                compressedLength += 1 + String.valueOf(countConsecutive).length();
                countConsecutive = 0;
            }
        }
        System.out.println(compressedLength);
        return compressedLength;
    }
    public static void main(String[] args) {
        String str = "aaaabbbbbcccccc";//string such as "abcdefgh" would not print because the result would have more characters than the actual striing
                                      // so that would not be counted as string compression...............lol lol lol
        compress(str);
    }
}