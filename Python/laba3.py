print("Вітаємо!\n")

import time
time.sleep(1)

while True:
    while True:
        try:
            m = int(input("Введіть кількість рядків: "))
            break
        except Exception:
            print("\nНеобхідно число")
            time.sleep(1)
            continue

    slog = input("Введіть склад: ")

    print()   #ПРОСТО АБЗАЦ

    i=0
    k=0
    while i<m:
        i += 1
        word = input("Введіть слово: ")
        k += word.count(slog)

    print("\nКількість зустрічей заданого складу у словах:",k)
    time.sleep(2)
    print('\n')

    end = input("Хочете продовжити? \nВведіть 'так' або 'ні': ")
    if end == ("ні"):
        exit()
    else:
        print("\n")


