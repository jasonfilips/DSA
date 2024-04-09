#include "Serialization.h"
#include <span>

bool binarySearch(std::span<BookData> books, std::string_view searchItem) {
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