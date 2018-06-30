print('Вітаємо!\n'
      'Програму виконав Садченко Микита, КМ-73.\n\n'
      'Варіант 25.\n'
      '"Виконати обробку елементів прямокутної матриці A, що має N рядків і M стовпців.\n'
      'Визначити, скільки нульових елементів міститься в кожному стовпці і в кожному рядку матриці.\n'
      'Результат оформити у вигляді матриці з N + 1 рядків і M + 1 стовпців."')

matrix = []
mat = []
amount = 0


def valid(num):
    return int(num) if num.isdigit() == 1 and int(num) != 0 else valid(input("enter natural number: "))


error = True
while error is True:
    n = valid(input("\nvalue of rows: "))
    m = valid(input("value of columns: "))

    for i in range(n):
        matrix.append(input("enter value of row: ").split())

    for g in range(m):
        col = 0
        for gg in matrix[:n]:
            col += gg[g].count('0')
        mat.append(str(col))
    matrix += [mat]

    for j in range(n):
        row = 0
        for jj in range(m):
            row += matrix[j][jj].count('0')
        amount += row
        matrix[j].append(str(row))
    matrix[-1].append(str(amount))

    for elem in matrix:
        print(' '.join(elem))
    if input("enter 'e' to exit, 's' - to stay: ") == 'e':
        error = False
        exit()
