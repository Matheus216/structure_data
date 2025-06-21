using System;

namespace structure_data.Graph;

public class Graph
{
    private Dictionary<string, List<Node>> Hash { get; set; } = [];

    public Node? BreadthFirstSearchIsSale(string startName)
    {
        var nodes = new Queue<Node>(Hash[startName]);
        var processed = new List<Node>();

        while (nodes.Count > 0)
        {
            var search = nodes.Dequeue();
            if (search.IsSale)
                return search;
            Hash[search.Name]
                .Where(x => !processed.Exists(z => z == x))
                .ToList()
                .ForEach(nodes.Enqueue);
            processed.Add(search);
        }

        return null;
    }

    public void AddNode(Node node)
    {
        if (!Hash.ContainsKey(node.Name))
            Hash.Add(node.Name, [node]);
        else
            Hash[node.Name].Add(node);
    }
}

