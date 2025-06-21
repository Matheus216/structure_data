using System;
using System.Collections.Concurrent;

namespace structure_data;


public record Menu(IEnumerable<Dishe> Dishes)
{
    public void PrintDishes()
    {
        foreach (var dishe in Dishes)
        {
            Console.WriteLine(dishe.ToString());
        }
    }

    public void PrintDishesWith(IEnumerable<string> ingredients)
    {
        foreach (var dishe in this.Dishes
            .Where(x => x.Ingredients.Any(x => ingredients.Contains(x.Name)))
            .Select(x => x.Name))
        {
            Console.WriteLine(dishe);
        }
    }
   
}
public record Dishe(string Name, IEnumerable<Ingredients> Ingredients, int Price)
{
    public override string ToString()
        => $"Nome: {Name} Price: ${Price} Ingredients: ${Ingredients}";
    
}
public record Ingredients(string Name);
