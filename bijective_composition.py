# program to find n-fold composition is bijective
x =[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
fx = [1,2,3,4,5,0,7,8,9,10,11,12,6,14,15,16,17,18,19,20,13]
fn = []
n_max = 1000
for n in range(1,n_max+1):
    for f in fx:
        fn.append(f**n)
        
print('for n = {}'.format(n_max))
print('The number of generated f^n = 21n : {}'.format(len(fn)))
print('distinct f^n: {}'.format(len(set(fn))))