# program to find bijective a^x mod 101
def check_if_bijective(a):
    set_of_vals = set()
    for x in range(1, 101):
        fx = (a * x) % 101
        if fx in set_of_vals:
            return False
        set_of_vals.add(fx)
    return True

def main():
    set_of_bijective = []
    for a in range(1, 101):
        if check_if_bijective(a):
            set_of_bijective.append(a)
    print("Values of 'a' for which a^x mod 101 is bijective are :")
    print(set_of_bijective)

main()
