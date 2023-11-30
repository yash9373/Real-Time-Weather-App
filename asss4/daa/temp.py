class Node:
    def __init__(self, node_id, neighbors=None, color=None):
        self.node_id = node_id
        self.neighbors = neighbors if neighbors else []
        self.color = color


def graph_coloring(graph):
    colors = []
    colored_nodes = []
    uncolored_nodes = [node for node in graph]

    while uncolored_nodes:
        current_node = uncolored_nodes.pop()

        available_colors = set()

        for neighbor in current_node.neighbors:
            if neighbor in colored_nodes:
                available_colors.add(neighbor.color)

        color_to_assign = 1
        while color_to_assign in available_colors:
            color_to_assign += 1

        current_node.color = color_to_assign
        colored_nodes.append(current_node)
        colors.append(color_to_assign)

    return colors


# Input: Define the graph
node1 = Node(1)
node2 = Node(2)
node3 = Node(3)
node4 = Node(4)
node5 = Node(5)

node1.neighbors = [node2, node3]
node2.neighbors = [node1, node3]
node3.neighbors = [node1, node2, node4]
node4.neighbors = [node3, node5]
node5.neighbors = [node4]

graph = [node1, node2, node3, node4, node5]

# Run the graph coloring algorithm
result = graph_coloring(graph)

# Output: Display the colored nodes
for i, color in enumerate(result, start=1):
    print(f"Node {i}: Color {color}")
