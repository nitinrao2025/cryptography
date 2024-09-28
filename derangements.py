# program to compute 5 bit derangements of u v x y z
import math
for u in range(5):
    for v in range(5):
        for x in range(5):
            for y in range(5):
                for z in range(5):
                    der ={u, v, x, y, z}
                    if (u != 0 and v != 1 and x != 2 and y != 3 and z != 4):
                        print(u, v, x, y, z)
                        