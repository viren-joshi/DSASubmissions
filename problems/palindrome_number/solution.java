class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        String num = Integer.toString(x);
        int len = num.length();
        for(int i=0; i<len/2; i++) {
            if(num.charAt(i) != num.charAt(len - i - 1)) {
                return false;
            }
        }
        return true;
    }
}