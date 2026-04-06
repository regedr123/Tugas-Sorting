import time

def get_input():
    n = int(input("Masukkan jumlah data: "))
    data = []
    print("Masukkan data satu per satu:")
    for i in range(n):
        val = int(input(f"  Data ke-{i+1}: "))
        data.append(val)
    return data

def print_array(arr, label=""):
    if label:
        print(f"  {label}: {arr}")
    else:
        print(f"  {arr}")

# ─────────────────────────────────────────
# 1. BUBBLE SORT
# ─────────────────────────────────────────
def bubble_sort(arr):
    a = arr.copy()
    n = len(a)
    print("\n── Bubble Sort ──")
    for i in range(n - 1):
        swapped = False
        for j in range(n - 1 - i):
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]
                swapped = True
        print_array(a, f"Iterasi {i+1}")
        if not swapped:
            break
    print(f"  Hasil: {a}")
    return a

# ─────────────────────────────────────────
# 2. SELECTION SORT
# ─────────────────────────────────────────
def selection_sort(arr):
    a = arr.copy()
    n = len(a)
    print("\n── Selection Sort ──")
    for i in range(n - 1):
        min_idx = i
        for j in range(i + 1, n):
            if a[j] < a[min_idx]:
                min_idx = j
        a[i], a[min_idx] = a[min_idx], a[i]
        print_array(a, f"Iterasi {i+1}")
    print(f"  Hasil: {a}")
    return a

# ─────────────────────────────────────────
# 3. INSERTION SORT
# ─────────────────────────────────────────
def insertion_sort(arr):
    a = arr.copy()
    n = len(a)
    print("\n── Insertion Sort ──")
    for i in range(1, n):
        key = a[i]
        j = i - 1
        while j >= 0 and a[j] > key:
            a[j + 1] = a[j]
            j -= 1
        a[j + 1] = key
        print_array(a, f"Iterasi {i}")
    print(f"  Hasil: {a}")
    return a

# ─────────────────────────────────────────
# 4. QUICK SORT
# ─────────────────────────────────────────
_quick_step = 0

def _quick_sort(a, low, high):
    global _quick_step
    if low < high:
        pivot = a[high]
        i = low - 1
        for j in range(low, high):
            if a[j] <= pivot:
                i += 1
                a[i], a[j] = a[j], a[i]
        a[i + 1], a[high] = a[high], a[i + 1]
        pi = i + 1
        _quick_step += 1
        print_array(a[:], f"Langkah {_quick_step} (pivot={pivot})")
        _quick_sort(a, low, pi - 1)
        _quick_sort(a, pi + 1, high)

def quick_sort(arr):
    global _quick_step
    _quick_step = 0
    a = arr.copy()
    print("\n── Quick Sort ──")
    _quick_sort(a, 0, len(a) - 1)
    print(f"  Hasil: {a}")
    return a

# ─────────────────────────────────────────
# 5. MERGE SORT
# ─────────────────────────────────────────
_merge_step = 0

def _merge(a, left, mid, right):
    global _merge_step
    L = a[left:mid + 1]
    R = a[mid + 1:right + 1]
    i = j = 0
    k = left
    while i < len(L) and j < len(R):
        if L[i] <= R[j]:
            a[k] = L[i]; i += 1
        else:
            a[k] = R[j]; j += 1
        k += 1
    while i < len(L):
        a[k] = L[i]; i += 1; k += 1
    while j < len(R):
        a[k] = R[j]; j += 1; k += 1
    _merge_step += 1
    print_array(a[:], f"Merge {_merge_step} (L={L}, R={R})")

def _merge_sort(a, left, right):
    if left < right:
        mid = (left + right) // 2
        _merge_sort(a, left, mid)
        _merge_sort(a, mid + 1, right)
        _merge(a, left, mid, right)

def merge_sort(arr):
    global _merge_step
    _merge_step = 0
    a = arr.copy()
    print("\n── Merge Sort ──")
    _merge_sort(a, 0, len(a) - 1)
    print(f"  Hasil: {a}")
    return a

# ─────────────────────────────────────────
# MENU UTAMA
# ─────────────────────────────────────────
def menu():
    print("=" * 45)
    print("   PROGRAM SORTING - Python")
    print("=" * 45)
    data = get_input()
    print(f"\nData awal: {data}")

    print("\nPilih algoritma sorting:")
    print("  1. Bubble Sort")
    print("  2. Selection Sort")
    print("  3. Insertion Sort")
    print("  4. Quick Sort")
    print("  5. Merge Sort")
    print("  6. Semua algoritma")
    pilihan = input("Pilihan (1-6): ").strip()

    algorithms = {
        "1": bubble_sort,
        "2": selection_sort,
        "3": insertion_sort,
        "4": quick_sort,
        "5": merge_sort,
    }

    if pilihan == "6":
        for fn in algorithms.values():
            fn(data)
    elif pilihan in algorithms:
        algorithms[pilihan](data)
    else:
        print("Pilihan tidak valid.")

if __name__ == "__main__":
    menu()
