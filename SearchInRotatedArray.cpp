class Solution {
public:
    int PivotElement(vector<int>& arr, int s, int e) {
        int mid = s + (e - s) / 2;

        while (s < e) {
            if (arr[mid] >= arr[0]) {
                s = mid + 1;
            } else {
                e = mid;
            }
            mid = s + (e - s) / 2;
        }
        return s;
    }

    int BinarySearch(vector<int>& arr, int s, int e, int target) {
        int start = s;
        int end = e;
        int mid = start + (end - start) / 2;

        while (start <= end) {
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
            mid = start + (end - start) / 2;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = PivotElement(nums, 0, n - 1);

        if (target >= nums[pivot] && target <= nums[n - 1]) {
            return BinarySearch(nums, pivot, n - 1, target);
        } else {
            return BinarySearch(nums, 0, pivot - 1, target);
        }
    }
};
