int lengthOfLongestSubstring(char* s) {
    int lastFound[128] = {0};
    int result = 0;
    int start = 1;
    int i = 1;
    while(*s != '\0')
    {
        if(lastFound[*s] < start)
        {
            lastFound[*s] = i;
        }
        else
        {
            result = ((i - start) > result)? (i - start) : result;
            start = lastFound[*s] + 1;
            lastFound[*s] = i;
        }
        s++;
        i++;
    }
    result = ((i - start) > result)? (i - start) : result;

    return result;
}
