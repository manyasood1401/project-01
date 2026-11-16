# Selection Sort & Bubble Sort on Employee Salaries


def selection_sort(salaries):
    arr = salaries.copy()
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr


def bubble_sort(salaries):
    arr = salaries.copy()
    n = len(arr)
    for i in range(n - 1):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr


def main():
    n = int(input("Enter number of employees: "))
    salaries = []
    print("Enter floating-point salaries:")
    for i in range(n):
        salaries.append(float(input(f"Salary {i + 1}: ")))

    # Sort using algorithms
    sel_sorted = selection_sort(salaries)
    bub_sorted = bubble_sort(salaries)

    print("\nSorted Salaries (Selection Sort):", sel_sorted)
    print("Sorted Salaries (Bubble Sort):", bub_sorted)

    # Top 5 highest salaries
    top_5 = bub_sorted[-5:][::-1] if len(bub_sorted) >= 5 else bub_sorted[::-1]
    print("\nTop 5 Highest Salaries:", top_5)


if __name__ == "__main__":
    main()