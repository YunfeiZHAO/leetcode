def bestSumKStar(g_nodes, g_from, g_to, values, k):
    max = 0
    children_value_dict = {}
    for g in range(1, g_nodes+1):
        children_value_dict[g] = []

    for g in range(1, g_nodes+1):

        for i, e in enumerate(g_from):
            if e == g:
                if values[g_to[i] - 1] > 0:
                    children_value_dict[g].append(values[g_to[i] - 1])
                if values[g - 1] > 0:
                    children_value_dict[g_to[i]].append(values[g - 1])

    for node, children in children_value_dict.items():
        children_value_dict[node] = sorted(children, reverse=True)
    
    print(children_value_dict)

    for node, children in children_value_dict.items():
        new_sum = values[node - 1] + sum(children[0:k])
        if new_sum > max:
            max = new_sum
    return max

def bestSumKStar2(g_nodes, g_from, g_to, values, k):
    max = 0
    children_value_dict = {}
    for g in range(1, g_nodes+1):
        children_value_dict[g] = []

    for g in range(1, g_nodes+1):

        for i, e in enumerate(g_from):
            if e == g:
                if values[g_to[i] - 1] > 0:
                    children_value_dict[g].append(values[g_to[i] - 1])
                if values[g - 1] > 0:
                    children_value_dict[g_to[i]].append(values[g - 1])

    for node, children in children_value_dict.items():
        children_value_dict[node] = sorted(children, reverse=True)
    
    print(children_value_dict)

    for node, children in children_value_dict.items():
        new_sum = values[node - 1] + sum(children[0:k])
        if new_sum > max:
            max = new_sum
    return max


def max_profit(k, indicators, profits):
    max = 0
    n = len(indicators)
    for p1 in range(n - 1):
        for p2 in range(p1+1, n):
            if indicators[p1] | indicators[p2] <= k:
                new_sum = profits[p1] + profits[p2]
                if new_sum > max:
                    max = new_sum
    return max


if __name__ == '__main__':
    # g_nodes = 5
    # g_from = [3,3,3,3]
    # g_to = [1,2,4,5]
    # values = [10,20,30,40,50]

    # g_nodes = 7
    # g_from = [1,2,2,4,4,4]
    # g_to = [2,3,4,5,6,7]
    # values = [1,2,3,4,10,-10,-20]

    # print(bestSumKStar(g_nodes, g_from, g_to, values, k=2))

    n = 3
    k = 6
    indicators = [3,4,2]
    profits = [3,4,5]
    print(max_profit(k, indicators, profits))
