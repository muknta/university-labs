print("--------------------------------------------")
print("-----------------VITAEMO!!!-----------------")
print("--------------------------------------------")
print("-----Programu vykonav Sadchenko Mykyta.-----")
print("--------------------------------------------")
print("-----------------Pochnemo.------------------")
print("--------------------------------------------\n")

import time, math

time.sleep(2)

while True:
    while True:
        try:
            a = float(input("Vvedit' rebro kuba: "))
            if a<=0:
                print("\nPotribno DODATNE CHYSLO")
                continue
        except Exception:
            print("\nVy vvely nepravyl'nyi format")
            continue
        break

    while True:
        try:
            h = float(input("Vvedit' vysotu cylindra: "))
            if h<=0:
                print("\nPotribno DODATNE CHYSLO")
                continue
        except Exception:
            print("\nVy vvely nepravyl'nyi format")
            continue
        break

    while True:
        try:
            r = float(input("Vvedit' radius cylindra: "))
            if r<=0:
                print("\nPotribno DODATNE CHYSLO")
                continue
        except Exception:
            print("\nVy vvely nepravyl'nyi format")
            continue
        break

    while True:
        try:
            m = float(input("Vvedit' ob'em ridyny: "))
            if m<=0:
                print("\nPotribno DODATNE CHYSLO")
                continue
        except Exception:
            print("\nVy vvely nepravyl'nyi format")
            continue
        break

    v1 = float(a**3)
    v2 = float(math.pi * r**2 * h)

    time.sleep(2)

    if((v1>=m) & (v2>=m)):
        print("\nRidyna vhodyt' u obydvi emnosti.\n\n")
    elif((v1>=m) & (v2<m)):
        print("\nRidyna vhodyt' til'ky u kub.\n\n")
    elif((v1<m) & (v2>=m)):
        print("\nRidyna vhodyt' til'ky u cylindr.\n\n")
    else:
        print("\nRidyna nikudy ne vhodyt'.\n\n")

    time.sleep(2)

    end = input("Hochete prodovzhyty? \nVvedit' 'tak' abo 'ni': ")
    if end == ("ni"):
        exit()
    else:
        print("\n\n")


