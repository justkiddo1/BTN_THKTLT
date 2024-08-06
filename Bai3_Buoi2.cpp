#include <iostream>  
#include <algorithm> // cho std::sort  
#include <limits.h> // cho INT_MAX, INT_MIN  
using namespace std;

const int MAX_SIZE = 100;

void inputArray(int arr[], int& n) {
    srand(time(NULL));
    cout << "Nhap so phan tu cua mang (toi da " << MAX_SIZE << "): ";
    cin >> n;

    if (n > MAX_SIZE) {
        cout << "So phan tu vuot qua gioi han, gan n = " << MAX_SIZE << endl;
        n = MAX_SIZE;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    cout << "Mang da sinh: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void listPrimes(int arr[], int n) {
    cout << "Cac so nguyen to trong mang: ";
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int sumDigitsWithFirstOdd(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int firstDigit = abs(arr[i]);
        while (firstDigit >= 10) {
            firstDigit /= 10;
        }
        if (firstDigit % 2 == 1) {
            sum += arr[i];
        }
    }
    return sum;
}

void countOccurrences(int arr[], int n) {
    int count[MAX_SIZE] = { 0 };
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    cout << "So lan xuat hien cua cac phan tu: " << endl;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (count[i] > 0) {
            cout << i << ": " << count[i] << " lan" << endl;
        }
    }
}

void sortEvenOdd(int arr[], int n) {
    int even[MAX_SIZE], odd[MAX_SIZE];
    int evenCount = 0, oddCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even[evenCount++] = arr[i];
        }
        else {
            odd[oddCount++] = arr[i];
        }
    }

    sort(even, even + evenCount);
    sort(odd, odd + oddCount, greater<int>());

    for (int i = 0; i < evenCount; i++) {
        arr[i] = even[i];
    }
    for (int i = 0; i < oddCount; i++) {
        arr[evenCount + i] = odd[i];
    }
}

int longestDecreasingSubsequence(int arr[], int n) {
    int lis[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        lis[i] = 1; // Mỗi phần tử tối thiểu là 1  
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] < arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        maxLength = max(maxLength, lis[i]);
    }

    return maxLength;
}

int secondSmallest(int arr[], int n) {
    int first = INT_MAX, second = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] < first) {
            second = first;
            first = arr[i];
        }
        else if (arr[i] < second && arr[i] != first) {
            second = arr[i];
        }
    }

    return (second == INT_MAX) ? -1 : second;
}

void findMatchingDigits(int arr[], int n, int x) {
    cout << "Cac phan tu thoa man: ";
    for (int i = 0; i < n; i++) {
        if ((abs(arr[i]) / 10) == (x / 10) && (abs(arr[i]) % 10) == (x % 10)) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

void sortEvensAndRetainOdds(int arr[], int n) {
    int evens[MAX_SIZE];
    int evenCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            evens[evenCount++] = arr[i];
        }
    }

    sort(evens, evens + evenCount);

    int index = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            arr[i] = evens[index++];
        }
    }
}

void sortOddFirstEvenLast(int arr[], int n) {
    int odd[MAX_SIZE], even[MAX_SIZE];
    int oddCount = 0, evenCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            odd[oddCount++] = arr[i];
        }
        else {
            even[evenCount++] = arr[i];
        }
    }

    for (int i = 0; i < oddCount; i++) {
        arr[i] = odd[i];
    }
    for (int i = 0; i < evenCount; i++) {
        arr[oddCount + i] = even[i];
    }
}

int main() {
    int arr[MAX_SIZE], n;
    inputArray(arr, n);

    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Liet ke cac so nguyen to\n";
        cout << "2. Tinh tong cac phan tu co chu so dau la so le\n";
        cout << "3. Dem so lan xuat hien cua tung phan tu\n";
        cout << "4. Sap xep mang co so chan tang dan, so le giam dan\n";
        cout << "5. Tim day con giam dai nhat\n";
        cout << "6. Tim so nho thu hai trong mang\n";
        cout << "7. Nhap x va tim cac phan tu thoa man\n";
        cout << "8. Sap xep mang: so chan tang dan, so le giu nguyen vi tri\n";
        cout << "9. Sap xep mang: so le o dau, so chan o cuoi\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            listPrimes(arr, n);
            break;
        case 2:
            cout << "Tong cac phan tu co chu so dau la so le: " << sumDigitsWithFirstOdd(arr, n) << endl;
            break;
        case 3:
            countOccurrences(arr, n);
            break;
        case 4:
            sortEvenOdd(arr, n);
            cout << "Mang sau khi sap xep: ";
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        case 5:
            cout << "Do dai day con giam dai nhat: " << longestDecreasingSubsequence(arr, n) << endl;
            break;
        case 6:
        {
            int secondSmall = secondSmallest(arr, n);
            if (secondSmall == -1) {
                cout << "Khong co so nho thu hai trong mang." << endl;
            }
            else {
                cout << "So nho thu hai trong mang: " << secondSmall << endl;
            }
        }
        break;
        case 7:
        {
            int x;
            cout << "Nhap x (so co 2 chu so): ";
            cin >> x;
            findMatchingDigits(arr, n, x);
        }
        break;
        case 8:
            sortEvensAndRetainOdds(arr, n);
            cout << "Mang sau khi sap xep: ";
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        case 9:
            sortOddFirstEvenLast(arr, n);
            cout << "Mang sau khi sap xep: ";
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        case 0:
            cout << "Thoat chuong trinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
        }
    } while (choice != 0);

    return 0;
}