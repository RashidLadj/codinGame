const n = parseInt(readline());

var temperatures = readline().split(' ').map(x => parseInt(x));

var result = 5526;

temperatures.forEach(temp => {
    if (Math.abs(temp) < Math.abs(result))
        result = temp;
    if (Math.abs(temp) === Math.abs(result))
        result = Math.max(result, temp);
});

console.log(n == 0 ? 0 : result) ;
