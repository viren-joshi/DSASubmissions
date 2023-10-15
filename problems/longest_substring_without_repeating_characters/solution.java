class Solution {
    public int lengthOfLongestSubstring(String s) {
        int maxLength = 0;
        int len = s.length();
        String temp = "";
        Character currentChar = ' ';
        for(int i=0; i<len; i++) {
            temp = "";
            for(int j=i; j<len; j++) {
                if(temp.indexOf(s.charAt(j)) == -1) {
                    temp += s.charAt(j);
                    maxLength = Math.max(temp.length(),maxLength);
                } else {
                    break;
                }
            }
        }
        return Math.max(maxLength, temp.length());
    }
}