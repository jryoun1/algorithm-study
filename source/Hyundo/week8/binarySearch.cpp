
int BinarySearch(int key, int arr[])
{
	int left, right = arr.length() - 1, mid;
	while (low <= high) {
		mid = (left + right) / 2;
		if (iKey == arr[mid])
			break;
		if (iKey < arr[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
}