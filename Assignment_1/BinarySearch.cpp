#include "Serialization.h"
#include <vector>

bool binarySearch(const std::vector<BookData>& books, const std::string& searchItem) {
	int low = 0, high = books.size() - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (books[mid].title == searchItem) {
			return true;
		}
		else if (books[mid].title < searchItem) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	return false;
}