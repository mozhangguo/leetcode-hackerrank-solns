const gridTraveler = (m, n) => { 
    
    const table = Array(m + 1).fill().map(() => Array(n + 1).fill(0));
    table[1][1] = 1; // Base Case

    for (let i = 0; i <= m; i++) {
        for (let j = 0; j <= n; j++) {
            const current = table[i][j];

            if (j + 1 <= n) table[i][j+1] += current;
            if (i + 1 <= m) table[i+1][j] += current;
        }
    }

    return table[m][n];
}

console.log(gridTraveler(2,3))
console.log("he")

// visualize the problem as a table
// size the tasble based on the inputs
// initialize the table with default values
// seed the trivival answers into the table