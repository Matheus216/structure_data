public class Service 
{
   public string ReversePrefixString(string word, char c)
   {
      var i = word.IndexOf(c);  
      return string.Join("", word.Substring(0,i+1).ToCharArray().Reverse()) + word.Substring(i+1); 
   }
}