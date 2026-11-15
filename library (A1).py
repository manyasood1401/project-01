books = ("abc", "def", "ghi", "jkl", "mno")
counts = {b: 0 for b in books}
members = nobook = total = 0

while True:
    ch = input("\n1. Enter Data  2. Show Summary  3. Exit\nChoice: ")

    if ch == "1":
        members = int(input("Members: "))
        counts = {b: 0 for b in books}
        nobook = total = 0

        for i in range(1, members + 1):
            n = int(input(f"Books taken by user {i}: "))
            if n == 0:
                nobook += 1
            for _ in range(n):
                if total >= 50:
                    print("Limit reached!")
                    break
                b = input("Book name: ").strip()
                if b in counts:
                    counts[b] += 1
                    total += 1
                else:
                    print("Invalid book!")

    elif ch == "2":
        if members == 0:
            print("Enter data first!")
            continue
        while True:
            sub = input(
                "\n1.Total 2.Avg 3.No-book 4.Highest 5.Lowest 6.Mode 7.Back\nChoice: "
            )
            if sub == "1":
                print("Total:", total)
            elif sub == "2":
                print("Average:", round(total / members, 2))
            elif sub == "3":
                print("No books:", nobook)
            elif sub in ("4", "6"):
                m = max(counts, key=counts.get)
                print("Highest/Mode:", m, counts[m])
            elif sub == "5":
                m = min(counts, key=counts.get)
                print("Lowest:", m, counts[m])
            elif sub == "7":
                break

    elif ch == "3":
        break