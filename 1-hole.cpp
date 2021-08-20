<div><p>If we did not have the choice to remove an element, we would have applied Kadane's Algorithm and that was all.</p></div>

<div><p>The additional choice can be taken care of by using two arrays, a forward array fw in which fw[i] would store maximum subarray sum from 0 to ith index, and a backward array bw in which bw[i] would store maximum subarray sum from ith to (n-1)th index.</p></div>

<div><p>Now for every ith element, we can find the maximum subarray sum after removing it which will be fw[i-1] + bw[i+1].</p></div>

<div><p>Our time complexity is O(n) and space complexity is O(n).</p></div>

<div><p><b>Official Solution:</b> <pre class="line-numbers language-cpp"><code class=" language-cpp">
#include &lt;bits/stdc++.h&gt;
using namespace std;
 
int maxSumSubarrayRemovingOneEle(int arr[], int n)
{
    // Maximum sum subarrays in forward and backward directions
    int fw[n], bw[n];
 
    // Initialize current max and max so far.
    int cur_max = arr[0], max_so_far = arr[0];
 
    // calculating maximum sum subarrays in forward
    // direction
    fw[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        cur_max = max(arr[i], cur_max + arr[i]);
        max_so_far = max(max_so_far, cur_max);
 
        // storing current maximum till ith, in
        // forward array
        fw[i] = cur_max;
    }
 
    // calculating maximum sum subarrays in backward
    // direction
    cur_max = max_so_far = bw[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--)
    {
        cur_max = max(arr[i], cur_max + arr[i]);
        max_so_far = max(max_so_far, cur_max);
 
        // storing current maximum from ith, in
        // backward array
        bw[i] = cur_max;
    }
 
    /* Initializing final ans by max_so_far so that,
        case when no element is removed to get max sum
        subarray is also handled */
    int fans = max_so_far;
 
    // choosing maximum ignoring ith element
    for (int i = 1; i &lt; n - 1; i++)
        fans = max(fans,max(0, fw[i - 1]) +max(0, bw[i + 1]));
  // In this condition we are checking when removing the ith element
  //so checking the max(0,left)+max(0,right), because maybe left<0 || right<0 so it wont contribute to the answer
    if(fans==0)
         // if no positive element in array so return max_element
        return *max_element(arr,arr+n);
        
    return fans;
 
}
 
// Driver code to test above methods
int main()
{
    int n; 
    cin>>n;
    int arr[n] ;
    for(int i=0;i&lt;n;i++)
        cin&gt;&gt;arr[i];
    cout&lt;&lt;maxSumSubarrayRemovingOneEle(arr, n);
    return 0;
}
</code></pre></p></div>  