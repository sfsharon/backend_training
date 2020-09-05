"""
A simulation to find the probability for cutting a single stick in two places (uniformaly probability), and 
getting three parts of a stick that can be used to create a triangle.
The simulation shows that the probability is 0.25 , which fits the description in the "Young Mechanic" book. The book shows a geometric solution 
(using an equal sides triangle with orthogonal lines).
"""
import random

TOTAL_CNT = 100000

triangle_cnt = 0

for i in range(TOTAL_CNT) :
    pnt1 = random.uniform(0,1)
    pnt2 = random.uniform(0,1)
    size1 = 0
    size2 = 0
    size3 = 0
    if pnt1 > pnt2 :
        size1 = pnt2
        size2 = pnt1 - pnt2
        size3 = 1 - pnt1
    else :
        size1 = pnt1
        size2 = pnt2 - pnt1
        size3 = 1 - pnt2
    
    # Check if got a triangle
    if  (size1 + size2 > size3) and \
        (size2 + size3 > size1) and \
        (size1 + size3 > size2):
            triangle_cnt += 1
    
print("Probability for triangle :" + str(triangle_cnt / TOTAL_CNT))
