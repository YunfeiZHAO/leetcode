
class Node():
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right


def array_to_tree(array):
    n = len(array)
    if n>0:
        root = Node(array[0].value)

    def dfs(node, index):
        # if index >= n:
        #     return
        # else:
        if 2*(index+1) -1 <= n:
            node.left = array[2*(index+1) -1]
            dfs(node.left, 2*(index+1) -1)
        if 2*(index+1) <= n:
            node.right = array[2*(index+1)]
            dfs(node.right, 2*(index+1))
        return
    dfs(root, 0)
    return root


def print_tree_bfs(root):
    


def findClosestValueInBst(tree, target):
    distance = abs(tree.value - target)
    value = tree.value
    
    def dfs(node):
        # stop condition
        if(node.value == target):
            return target
        if(abs(node.value - target) > distance or (node.left==None and node.right==None)):
            return value

        value = node.value
        distance = abs(node.value - target)

        # recursion part
        if(node.value > target):
            return dfs(node.left)
        elif(node.value < target):
            return dfs(node.right)

    return dfs(tree)


if __name__ == '__main__':
    array = [5,3,10,2,4,8] + [None]*6 + [9] + [None]*2
    root = array_to_tree(array)
    

