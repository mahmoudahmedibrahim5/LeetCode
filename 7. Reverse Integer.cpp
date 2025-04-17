int arr[] = {-2, -1, -4, -7, -4, -8, -3, -6, -4, -7};
class Solution {
public:
    int reverse(int x) {
        int digits = 0;
        int copy = x;
        while(copy){
            copy /= 10;
            digits++;
        }
        if(digits > 9)
        {
            int y;
            if(x > 0)
                y = -1 * x;
            else
                y = x;

            for(int i = 0; i < 10; i++)
            {
                if(y % 10 == arr[i])
                    y /= 10;
                else if(y % 10 > arr[i])
                    break;
                else if(y % 10 < arr[i])
                    return 0;
            }
        }

        int result = 0;
        for(int i = 0; i < digits; i++)
        {
            result *= 10;
            result += (x % 10);
            x /= 10;
        }
        return result;
    }
};
