class Solution
{
public
    int Solve(int[] arr)
    {
        var currentHeight = arr[0];
        var max = 0;
        var prevPeak = 0;
        var i = 0;
        var goingUp = false;
        var currentPeakStart = 0;
        while (i < arr.Length - 1)
        {
            if ((!goingUp && currentHeight >= arr[i + 1]) || (goingUp && currentHeight <= arr[i + 1]))
            {
                if (goingUp && currentHeight < arr[i + 1])
                {
                    currentPeakStart = i + 1;
                }
                currentHeight = arr[i + 1];
                i++;
            }
            else if (!goingUp)
            {
                goingUp = true;
            }
            else if (goingUp)
            {
                var distance = i - prevPeak;
                max = Math.Max(max, distance);
                if (i != currentPeakStart)
                {
                    prevPeak = currentPeakStart;
                }
                else
                {
                    prevPeak = i;
                }
                goingUp = false;
            }
        }
        var d = i - prevPeak;
        max = Math.Max(max, d);
        return max;
    }
}