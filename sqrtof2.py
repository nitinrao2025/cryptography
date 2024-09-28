# program to find accurate sqrt of 2
def lerr():
    lp = 1
    lq = 1
    lerr = 100
    for q in range(2,100000):
        p_start = int(1.4*q) #start value
        p_end = int(1.5*q) #end value
        for p in range(p_start-1,p_end+1):
            err = abs((p/q) - 2**0.5)
            #print("err = ", err)
            if (err < lerr):
                lerr = err
                lp = p
                lq = q
                #print("p,q,err ",lp,lq,lerr)
    return lp,lq,lerr
p,q,err = lerr()
print("Best Approximation of Sqrt(2) = ", p,q)
          
        
