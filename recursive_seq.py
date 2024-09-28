# program to compute f(100000) of f(n) = f(n/2)+f(n/3)
import math
def f(n):
    # base condition
    if n==1 or n==0:
        return n
    else:
        # compute f(n/2)
        nby2=math.floor(n/2)
        # compute f(n/3)
        nby3=math.floor(n/3)
       # recursive call
        return f(nby2)+f(nby3)
        
def main():
    sum=f(100000)
    print("f(100000) =  "+str(sum))
    
main()