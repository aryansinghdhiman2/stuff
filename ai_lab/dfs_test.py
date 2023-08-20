visited = []
def dfs_iter(adj_matrix:list[list[int]],start_index:int,depth:int) -> list[int]:
    stack = [start_index]
    children = []
    number_of_children = 0
    while(stack):
        curr_index = stack[0]
        if(stack[0] not in visited):
            visited.append(stack[0])
        stack.pop(0)
        depth-=1   

        if(number_of_children != 0):number_of_children-=1   
        if(len(children)>=2):
            if(children[-1]<=number_of_children):     
                children.append(number_of_children)
            else: children[-1]=number_of_children
            # children[-1]-=1
            if(children[-1]<=children[-2]):
                depth+=1
                children.pop()   
        else:
            children.append(number_of_children)  
        if(depth>0):
            for i in reversed(range(len(adj_matrix[curr_index]))):
                if(adj_matrix[curr_index][i]==1 and i not in visited):
                    stack.insert(0,i)
                    number_of_children+=1