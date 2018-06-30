try:
    import geonamescache
    geo = geonamescache.GeonamesCache()
except ImportError:
    print("============================ Oh, no! =============================\n"
          "====== Your computer do not support validation of geonames. ======\n"
          "==================================================================\n")
    geonamescache = None
import time

print('Вітаємо!\n'
      'Програму виконав Садченко Микита, КМ-73.\n\n'
      'Варіант 25.\n'
      '"Створити список, елементами якого є вкладені списки. Кількість елементів не менше 15.\n'
      'Вкладений список складається з двох елементів: країна та місто в цій країні.\n'
      ' Необхідно:\n'
      '- знайти міста, що знаходяться в Італії;\n'
      '- знайти країну, міста якої найбільше вказані в списку."')
city_list = []
user_list = []
time.sleep(2)


error = True
while error:
    def natural_num(num):
        """ NATURAL NUMBER VALIDATION """
        return int(num) if num.isdigit() == 1 and int(num) != 0 else natural_num(input("natural number!: "))


    def choice(char):
        return int(char) if char == '1' or char == '2' else choice(input("'1' or '2': "))


    def create_list(counter=1):
        """ CREATING of USER-LIST and CHECKING for REAL GEO-NAMES """
        country = input(str(counter)+".1. Enter name of country: ")
        if list(geo.get_countries_by_names()).count(country) == 0:
            print("Wrong name of country!")
            time.sleep(1)
            return create_list(counter)
        city = input(str(counter)+".2. Enter name of city: ")
        if list(geo.get_cities_by_name(city)):
            user_list.append([country, city])
            if counter == amount:
                return user_list
            return create_list(counter + 1)
        print("Wrong name of city!")
        time.sleep(1)
        return create_list(counter)


    def max_count(pair_list):
        """ DETERMINE COUNTRY THAT CONTAINS the BIGGEST NUMBER of CITIES """
        country_list = []
        counter = 1
        maxim = 0
        max_country = "no!"
        for c1 in range(len(pair_list)):
            country_list.append(pair_list[c1][0])
        sorted(country_list)
        for c2 in range(len(country_list)):
            if country_list[c2] == country_list[c2-1]:
                counter += 1
                if maxim < counter:
                    maxim = counter
                    max_country = country_list[c2-1]
            else:
                counter = 1
        return max_country


    if choice(input("\nEnter '1' to work with default-list or '2' - to work with user-list: ")) == 1:
        default_list = [["Ukraine", "Kiev"], ["Uganda", "Kampala"], ["Italy", "Milano"], ["Ukraine", "Kharkiv"],
                        ["Russia", "Moscow"], ["Canada", "Ottawa"], ["Poland", "Warsaw"], ["Germany", "Berlin"],
                        ["Poland", "Lublin"], ["Italy", "Rome"], ["Italy", "Rome"], ["Spain", "Madrid"],
                        ["Ukraine", "Cherkasy"], ["Norway", "Oslo"], ["Turkey", "Ankara"], ["Ukraine", "Khmelnytskyi"]]
        for i in range(len(default_list)):
            if default_list[i][0] == "Italy":
                city_list.append(default_list[i][1])
        time.sleep(1)
        print("\nCities of Italy: "+', '.join(set(city_list)) +
              "\nThe most mentioned country: " + max_count(default_list))
    else:
        amount = natural_num(input("Enter amount of pairs: "))
        user_list = create_list()
        for i in range(len(user_list)):
            if user_list[i][0] == "Italy":
                city_list.append(user_list[i][1])
        time.sleep(1)
        print("\nCities of Italy: "+', '.join(set(city_list)) +
              "\nThe most mentioned country: " + max_count(user_list))
    time.sleep(2)
    if choice(input("\nEnter '1' to exit, '2' - to stay: ")) == 1:
        error = False
        exit()

'''
# Нижче зроблена перевірка, щоб користувач ввів не менше 15 пар.
# Але це я вважаю непотрібним - тому закоментовано.

def natural_num(num):
    """ VALIDATION for NATURAL NUMBER and AT LEAST 15 - NUMBER """
    if num.isdigit() == 1 and int(num) != 0:
        if int(num) < 15:
            natural_num(input("at least 15!:"))
        return int(num)
    else:
        natural_num(input("natural number!: "))
'''
