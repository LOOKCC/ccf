x = int(input())
question = [[] for i in range(x)]
for i in range(x):
    for j in range(3):
        temp = input()
        temp = [int(m) for m in temp.split(' ')]
        question[i].append(temp)

def q_split(q):
    return [
            [q[0][0], q[0][1], q[0][2]], 
            [q[1][0], q[1][1], q[1][2]], 
            [q[2][0], q[2][1], q[2][2]],
            [q[0][0], q[1][0], q[2][0]], 
            [q[0][1], q[1][1], q[2][1]], 
            [q[0][2], q[1][2], q[2][2]], 
            [q[0][0], q[1][1], q[2][2]],
            [q[0][2], q[1][1], q[2][0]],
            ]


def cal_3(q):
    lines = q_split(q)
    for i in range(8):
        if q[i][0] == q[i][1] && q[i][0] == q[i][2] && q[i][0] == 1:
            return 1
        if q[i][0] == q[i][1] && q[i][0] == q[i][2] && q[i][0] == 2:
            return 2
    return 0

def cal_2():
    lines = q_split(q)
    count_X = 0
    count_O = 0
    have_2_X = [
        [1, 1, 0],
        [1, 0, 1],
        [0, 1, 1]]
    have_2_O = [    
        [2, 2, 0],
        [2, 0, 2],
        [0, 2, 2]]
    for i in range(8):
        for j in range(8):
            if q[i][0] == have_2_X[j][0] && q[i][0] == have_2_X[j][0] && q[i][0] == have_2_X[j][0]:
                count_X += 1
            if q[i][0] == have_2_O[j][0] && q[i][0] == have_2_O[j][0] && q[i][0] == have_2_O[j][0]:
                count_O += 1
    return count_X, count_O



def process(q):
    count_XO  = 0
    for i in range(3):
        for j in range(3):
            if q[i][j] != 0:
                count_XO += 1
    if count_XO == 0:
        return 0
    if count_XO == 2:
        return 0
    if count_XO == 4:
        count_X, count_O = cal_2(q)

            


    if count_XO == 8:

            

if __name__ == "__main__":
    
    