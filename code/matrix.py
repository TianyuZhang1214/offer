
def print_matrix(matrix):
    result = []
    i = 0
    j = 0
    start_x = 0
    start_y = 0
    count = 0
    max_x = len(matrix)
    max_y = len(matrix[0])

    while(count < max_x*max_y):
        i = start_y
        j = start_x
        while(j < max_x):
            result.append(matrix[i][j])
            ++j
            ++count
            print j
        ++i;
        while(i < max_y):
            result.append(matrix[i][j])
            ++i
            ++count
        
        --j
        while(j >= start_x):
            result.append(matrix[i][j])
            --j
            ++count
        
        --i;
        while(i > start_y):
            result.append(matrix[i][j])
            --i
            ++count
        
        ++start_x
        ++start_y
        --max_x
        --max_y
    
    return result;

if __name__ == "__main__":
    array = [([0] * (4) ) for i in range(4)]
    for i in range(len(array)):
        for j in range(len(array[0])):
            array[i][j] = 4*i+j

    result = print_matrix(array)
