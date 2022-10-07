#!/usr/bin/python3

def products(*iterables):
    """This works exactly like the product function in itertools
    it maps each element of each iterable with each element of other iterables
    example: product('ABCD', '12') --> A1 A2 B1 B2 C1 C2 D1 D2
    Example Explanation: product('ABCD', '12')
    n = 2
    length = []
    remaining = [1]
    for i in range(1, -1, -1):
        <when i == 1>
        m = len('12') = 2
        length = [2]
        remaining = [2]

        <when i == 0>
        m = len('ABCD') = 4
        length = [4, 2]
        remaining = [8, 2]
    product = 8
    for p in range(8):
        <when p == 0>
        var = []
        for i in range(2):
        <when i == 0>
            j = 0/8 % 4 == 0
            var.append(iterable[0][0] = A)

        <when i == 1>
            j = 0/2 % 2 == 0
            var.append(iterable[1][0] = 1)
            var = [A1]...
    """

    sol_list = []
    n = len(iterables)
    length = []
    remaining = [1]
    for i in range(n - 1, -1, -1):
        m = len(iterables[i])
        length.insert(0, m)
        remaining.insert(0, m * remaining[0])
    product = remaining.pop(0)

    for p in range(product):
        val = []
        for i in range(n):
            j = p // (remaining[i]) % length[i]
            val.append(iterables[i][j])
        sol_list.append(val)
    return sol_list
