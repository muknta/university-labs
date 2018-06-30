print("Вітаємо!\n"
      "Програму створив студент групи КМ-73, Садченко Микита.\n\n"
      "Варіант 25. Умова задачі:\n"
      '"Составить программу, в результате выполнения которой из первой заданной '
      'строки удаляется каждый символ, принадлежащий второй строке."\n')

error = True
while error:
    line1 = input("\nfirst line: ")
    line2 = input("second line: ")
    line3 = []
    for i in line1:
        if line2.find(i) == -1:
            line3.append(i)
    print("unique elements:", ' '.join(line3))
    Exit = input("\nenter 's' to stay, 'e' to exit: ")
    if Exit == 'e':
        error = False
        exit()
