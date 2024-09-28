# program to compute if S={1 2 3 4} is transitive but not reflexive
import math
def check_reflexive(R,S):
    for x in range(len(S)):
        for y in range(len(S)):
            if x == y and R[x][y] != 1:
                return False
    return True
def check_transitive(R,S):
    for x in range(len(S)):
        for y in range(len(S)):
            if x != y:
                for z in range(len(S)):
                    if y != z:
                        if R[x][y] == 1 and R[y][z] == 1:
                            if R[x][z] != 1:
                                return False
        return True
    
S = [1, 2, 3, 4]
R = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 0, 0], [0, 0, 0, 1]]
if check_transitive and not check_reflexive(R,S):
    print("True")
else:
    print("False")