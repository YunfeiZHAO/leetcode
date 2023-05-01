def branchSums(root):
    result = []
    def dfs(node, sum):
        if node is None:
            return
        sum = sum + node.value
        if node.left is None and node.right is None:
            result.append(sum)
        else:
            dfs(node.left, sum)    
            dfs(node.right, sum)

    dfs(root, 0)
    return result
