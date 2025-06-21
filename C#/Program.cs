
using structure_data;

var dishes = new List<Dishe>
{
    new("Coffee", [new("sugar"), new("watter")], 12),
    new ("Cake",[new("sugar"), new("farinha")], 13),
    new ("Rice",[new("coentro"), new("Oleo")], 12),
    new ("Beans",[new("sugar"), new("Verdura")], 43),
    new ("Potatos",[new("farinha"), new("Azeite")], 21),
    new ("Pizza",[new("Abobora"), new("Tomate")], 11),
    new ("Rondeli",[new("feijao"), new("Macarrao")], 33),
};

var menu = new Menu(dishes);

menu.PrintDishes();

Console.WriteLine("----------------------");

menu.PrintDishesWith([new("sugar")]);
