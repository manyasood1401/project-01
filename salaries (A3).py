def selection_sort(salaries):
	arr = salaries.copy()
	n = len(arr)
	for i in range (n):
		min_idx = i
		for j in range (i+1,n):
			if arr[j] < arr[min_idx]:
				min_idx = j
		arr[i], arr[min_idx] = arr[min_idx], arr[i]
	return arr


def bubble_sort(salaries):
	arr = salaries.copy()
	n = len(arr)
	for i in range (n-1):
		for j in range (0, n-i-1):
			if arr[j] > arr[j+1]:
				arr[j], arr[j+1] = arr[j+1], arr[j]
	return arr

def main():
	n = int(input("Enter Number of Employees"))
	salaries = []
	print("Enter salaries:")
	for i in range (n):
		salaries.append(float(input(f"Salaries")))

	sel_sorted = selection_sort(salaries)
	bub_sorted = bubble_sort(salaries)

	print("Selection Sorted Salaries:" , sel_sorted)
	print("Bubble Sorted Salaries:" , bub_sorted)

	top_5 = sel_sorted[-5:][::-1]
	print("Top 5 salaries:", top_5)

main()
