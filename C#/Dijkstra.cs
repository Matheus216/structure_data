using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Reflection;
using static structure_data.Node;

namespace structure_data;

public record NodeInformation(Node Node, int Weight);

public class Dijkstra : IShortestPathFinder
{
    readonly Dictionary<Node, Node> Parents = [];
    readonly Dictionary<Node, int> Costs = [];
    readonly List<NodeInformation> Pendings = [];
    readonly List<Node> Processed = [];

    public NodeInformation GetNodeToVisited()
    {
        var ordered = from node in Pendings
                      orderby node.Weight
                      select node;
        var response = ordered.FirstOrDefault();

        Pendings.Remove(response!);

        return response!;
    }

    public bool HasPending => Pendings.Count > 0;

    public void UpdateCosts(NeighborhoodInfo info, Node parent)
    {
        Costs.TryAdd(info.Node, info.Weight);
        Parents.TryAdd(info.Node, parent);

        Console.WriteLine($"Add: {info.Node.Label} weight: {info.Weight} Parent: {parent.Label}");
    }

    public int QueryWeight(Node node)
    {
        int result = int.MaxValue;
        if (Costs.TryGetValue(node, out var weight))
        {
            result = weight;
        }
        else
        {
            Costs.Add(node, result); 
        }

        return result;
    }

    public Node[] Find(Node from, Node to)
    {
        Pendings.Add(new NodeInformation(from, 0));
        Costs.Add(from, 0);

        while (HasPending)
        {
            var mainInformation = GetNodeToVisited();
            var main = mainInformation.Node;
            var mainWeight = QueryWeight(main);
            Processed.Add(main);

            Console.WriteLine($"Processing: {main.Label} Weight: {mainInformation.Weight}");

            foreach (var neighbor in main.Neighbors)
            {
                if (!Processed.Contains(neighbor.Node))
                {
                    Pendings.Add(new NodeInformation(neighbor.Node, neighbor.Weight));
                }

                var sum = neighbor.Weight + Costs[main];

                Console.WriteLine($"Sum: {sum} Between: {neighbor.Node.Label} and {main.Label}");

                var neighborWeight = QueryWeight(neighbor.Node);

                if (neighborWeight > sum)
                {
                    Costs[neighbor.Node] = sum;
                    //Parents[neighbor.Node] = main;

                    Console.WriteLine($"Update: {neighbor.Node.Label} to cost: {sum} and parent{main.Label} to {main.Label}");
                }
            }
        }

        return [.. Costs
            .OrderBy(x => x.Value)
            .Select(x => x.Key)];
    }
}
