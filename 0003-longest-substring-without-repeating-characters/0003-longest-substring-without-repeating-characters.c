int lengthOfLongestSubstring(char* s) {
    int map[128]={0};
    int left=0, right=0;
    int maxLen=0;
    while(s[right] != '\0') {
        map[s[right]]++;
        while(map[s[right]] > 1) {
            map[s[left]]--;
            left++;
        }
        int currentLen=right-left+1;
        if(currentLen > maxLen) maxLen=currentLen;
        right++;
    }
    return maxLen;
    
}