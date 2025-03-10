class Solution {
    public static boolean isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    public long countOfSubstrings(String word, int k) {
        int n = word.length();
        Map<Character, Integer> mp = new HashMap<>();
        int consonantCount = 0;
        long res = 0;
        int nextCons[] = new int[n];
        int lastConsonant = n;
        for (int i = n - 1; i >= 0; i--) {
            nextCons[i] = lastConsonant;
            if (!isVowel(word.charAt(i)))
                lastConsonant = i;
        }
        // sliding window
        int left = 0, right = 0;
        while (right < n) {
            // expanding window
            if (isVowel(word.charAt(right))) {
                mp.put(word.charAt(right), mp.getOrDefault(word.charAt(right), 0) + 1);
            } else {
                consonantCount++;
            }
            // shrinking window if too many constants
            while (left <= right && consonantCount > k) {
                if (isVowel(word.charAt(left))) {
                    mp.put(word.charAt(left), mp.get(word.charAt(left)) - 1);
                    if (mp.get(word.charAt(left)) == 0)
                        mp.remove(word.charAt(left));
                } else {
                    consonantCount--;
                }
                left++;
            }
            // count valid substrings
            while (left < right && mp.size() == 5 && consonantCount == k) {
                res += (nextCons[right] - right);
                if (isVowel(word.charAt(left))) {
                    mp.put(word.charAt(left), mp.get(word.charAt(left)) - 1);
                    if (mp.get(word.charAt(left)) == 0)
                        mp.remove(word.charAt(left));
                } else {
                    consonantCount--;
                }
                left++;
            }
            right++;
        }
        return res;
    }
}