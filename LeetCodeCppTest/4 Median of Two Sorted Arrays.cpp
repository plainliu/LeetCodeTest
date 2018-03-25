//2018.03.24
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = 0, n = 0;
		double re = 0;
		m = nums1.size();
		n = nums2.size();
		vector<int>rez(m + n, 0);
		for (int i = 0, j = 0, k = 0; (i<m || j<n) && k <= (m + n) / 2;){
			if (i >= m)
				rez[k++] = nums2[j++];
			else if (j >= n)
				rez[k++] = nums1[i++];
			else
				nums1[i]<nums2[j] ? rez[k++] = nums1[i++] : rez[k++] = nums2[j++];
		}
		(m + n) % 2 == 0 ? re = (double(rez[(m + n) / 2]) + double(rez[(m + n) / 2 - 1])) / 2 : re = double(rez[(m + n) / 2]);
		return re;
	}
};
