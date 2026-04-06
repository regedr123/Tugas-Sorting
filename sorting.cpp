#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ─────────────────────────────────────────
// Helper: cetak array
// ─────────────────────────────────────────
void printArray(const vector<int>& arr, const string& label = "") {
    if (!label.empty()) cout << "  " << label << ": ";
    else cout << "  ";
    cout << "[";
    for (int i = 0; i < (int)arr.size(); i++) {
        cout << arr[i];
        if (i < (int)arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// ─────────────────────────────────────────
// 1. BUBBLE SORT
// ─────────────────────────────────────────
void bubbleSort(vector<int> arr) {
    int n = arr.size();
    cout << "\n-- Bubble Sort --" << endl;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        printArray(arr, "Iterasi " + to_string(i + 1));
        if (!swapped) break;
    }
    cout << "  Hasil: "; printArray(arr);
}

// ─────────────────────────────────────────
// 2. SELECTION SORT
// ─────────────────────────────────────────
void selectionSort(vector<int> arr) {
    int n = arr.size();
    cout << "\n-- Selection Sort --" << endl;
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx]) minIdx = j;
        swap(arr[i], arr[minIdx]);
        printArray(arr, "Iterasi " + to_string(i + 1));
    }
    cout << "  Hasil: "; printArray(arr);
}

// ─────────────────────────────────────────
// 3. INSERTION SORT
// ─────────────────────────────────────────
void insertionSort(vector<int> arr) {
    int n = arr.size();
    cout << "\n-- Insertion Sort --" << endl;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printArray(arr, "Iterasi " + to_string(i));
    }
    cout << "  Hasil: "; printArray(arr);
}

// ─────────────────────────────────────────
// 4. QUICK SORT
// ─────────────────────────────────────────
int quickStep = 0;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    quickStep++;
    printArray(arr, "Langkah " + to_string(quickStep) + " (pivot=" + to_string(pivot) + ")");
    return i + 1;
}

void _quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        _quickSort(arr, low, pi - 1);
        _quickSort(arr, pi + 1, high);
    }
}

void quickSort(vector<int> arr) {
    quickStep = 0;
    cout << "\n-- Quick Sort --" << endl;
    _quickSort(arr, 0, arr.size() - 1);
    cout << "  Hasil: "; printArray(arr);
}

// ─────────────────────────────────────────
// 5. MERGE SORT
// ─────────────────────────────────────────
int mergeStep = 0;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);
    int i = 0, j = 0, k = left;
    while (i < (int)L.size() && j < (int)R.size()) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < (int)L.size()) arr[k++] = L[i++];
    while (j < (int)R.size()) arr[k++] = R[j++];

    mergeStep++;
    // Print L and R
    cout << "  Merge " << mergeStep << " (L=[";
    for (int x = 0; x < (int)L.size(); x++) { cout << L[x]; if (x < (int)L.size()-1) cout << ","; }
    cout << "], R=[";
    for (int x = 0; x < (int)R.size(); x++) { cout << R[x]; if (x < (int)R.size()-1) cout << ","; }
    cout << "]): "; printArray(arr);
}

void _mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        _mergeSort(arr, left, mid);
        _mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergeSort(vector<int> arr) {
    mergeStep = 0;
    cout << "\n-- Merge Sort --" << endl;
    _mergeSort(arr, 0, arr.size() - 1);
    cout << "  Hasil: "; printArray(arr);
}

// ─────────────────────────────────────────
// MENU UTAMA
// ─────────────────────────────────────────
int main() {
    cout << "=============================================" << endl;
    cout << "   PROGRAM SORTING - C++" << endl;
    cout << "=============================================" << endl;

    int n;
    cout << "Masukkan jumlah data: ";
    cin >> n;

    vector<int> data(n);
    cout << "Masukkan data satu per satu:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "  Data ke-" << (i + 1) << ": ";
        cin >> data[i];
    }

    cout << "\nData awal: "; printArray(data);

    cout << "\nPilih algoritma sorting:" << endl;
    cout << "  1. Bubble Sort" << endl;
    cout << "  2. Selection Sort" << endl;
    cout << "  3. Insertion Sort" << endl;
    cout << "  4. Quick Sort" << endl;
    cout << "  5. Merge Sort" << endl;
    cout << "  6. Semua algoritma" << endl;
    cout << "Pilihan (1-6): ";

    int pilihan;
    cin >> pilihan;

    switch (pilihan) {
        case 1: bubbleSort(data); break;
        case 2: selectionSort(data); break;
        case 3: insertionSort(data); break;
        case 4: quickSort(data); break;
        case 5: mergeSort(data); break;
        case 6:
            bubbleSort(data);
            selectionSort(data);
            insertionSort(data);
            quickSort(data);
            mergeSort(data);
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
    }

    return 0;
}
