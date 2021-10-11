using System;
using System.Linq;

class Solution{
    static void Main(){
        var n = Console.ReadLine();
        var min = 5526;
        if (n!="0"){
            var datas = Console.ReadLine().Split(' ').ToHashSet().ToArray();
            foreach (var data in datas){
                var d = int.Parse(data);
                if(Math.Abs(d) < Math.Abs(min) || (Math.Abs(d) == Math.Abs(min) && d > min))
                    min = d;
            }
        }
        Console.Write(n=="0"?0:min);
    }
}