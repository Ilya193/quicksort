#include <iostream>
#include <vector>

std::vector<int> operator+(std::vector<int> a, std::vector<int> b) {
    std::vector<int> c;

    if (a.size() == 0) {
        c = std::move(b);
        return c;
    }
    else if (b.size() == 0) {
        c = std::move(a);
        return c;
    }

    for (size_t i = 0; i < a.size(); i++)
        c.push_back(a[i]);

    for (size_t i = 0; i < b.size(); i++)
        c.push_back(b[i]);

    return c;
}

std::vector<int> quicksort(std::vector<int> arr) {
    if (arr.size() < 2)
        return arr;
    else {
        int num = arr[0];
        std::vector<int> less;
        std::vector<int> more;

        for (size_t i = 1; i < arr.size(); i++) {
            if (arr[i] <= num) less.push_back(arr[i]);
            else more.push_back(arr[i]);
        }

        return quicksort(less) + quicksort(std::vector<int>{num}) + quicksort(more);
    }
}


int main()
{
    std::vector<int> obj{10, 5, 2, 3, 0, 0, 0};
    std::vector<int> res = quicksort(obj);

    for (auto& elem: res) std::cout << elem << std::endl;

    return 0;
}

