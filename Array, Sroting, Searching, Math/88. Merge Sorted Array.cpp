
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;      // nums1's index (actual nums)
    int j = n - 1;      // nums2's index
    int k = m + n - 1;  // nums1's index (next filled position)

    while (j >= 0)
      if (i >= 0 && nums1[i] > nums2[j])
        nums1[k--] = nums1[i--];
      else
        nums1[k--] = nums2[j--];
  }
};





// class Solution {
// public:
//       void merge(vector<int>& ar1, int n, vector<int>& ar2, int m) {
//         int gap = ceil((float)(n + m) / 2);
//   while (gap > 0) {
//     int i = 0;
//     int j = gap;
//     while (j < (n + m)) {
//       if (j < n && ar1[i] > ar1[j]) {
//         swap(ar1[i], ar1[j]);
//       } else if (j >= n && i < n && ar1[i] > ar2[j - n]) {
//         swap(ar1[i], ar2[j - n]);
//       } else if (j >= n && i >= n && ar2[i - n] > ar2[j - n]) {
//         swap(ar2[i - n], ar2[j - n]);
//       }
//       j++;
//       i++;
//     }
//     if (gap == 1) {
//       gap = 0;
//     } else {
//       gap = ceil((float) gap / 2);
//     }
//   }
//     }
// };
        
//         int i, j, gap = n + m;
//          for(gap = ngap(gap); gap>0; gap = ngap(gap)){
             
//              //compairing from array
//              for(i = 0; i + gap < m; i++){
//                  if(nums1[i] > nums1[gap]){
//                      swap(nums1[i], nums1[i + gap]);
//                  }
//              }
             
//              //from first array and gap is in 2nd array
             
//              for(j = (gap>n )? gap - n:0; i<n && j<m; i++,j++){
//                  if(nums1[i] > nums2[j]){
//                      swap(nums1[i], nums2[j]);
//                  }
//              }
             
             
             
//              // if the pointer is in the second array
             
//              if(j < n){
//                  for(j = 0; j + gap < n; j++){
//                      swap(nums2[j], nums2[j + gap]);
//                  }
//              }
         // }
//     }
// };



// my Try :  Find the Error in solution
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int gap = ceil((m + n)/2);
//         while(gap){
            
//             for(int i = 0, j = gap; j < m+n; j++, i++){
//                 if(i<m && j <m){
//                     if(nums1[i] > nums1[j]){
//                         swap(nums1[1], nums1[j]);
//                     }
//                 }else if(i < m && j>=m){
//                     if(nums1[i] > nums2[j]){
//                         swap(nums1[1], nums2[j]);
//                     }
//                 // }else if(i >= m && j >= m){
//                 }else{
//                     if(nums2[i] > nums2[j]){
//                         swap(nums2[1], nums2[j]);
//                     }
//                 }
//             }
//             if(gap == 1){
//                 gap = 0;
//             }else{
//                 gap = ceil(gap/2);
//             }
//         }
        
//     }
// };
