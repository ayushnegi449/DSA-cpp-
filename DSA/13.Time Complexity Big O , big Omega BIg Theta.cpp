//! 3 different Asymptotic Time Complexity analysis of Algorithms :
//* 1. Big Oh(O)
//* 2. Big Omega(Ω)
//* 3. Big Theta(θ)

//*--> We will understand each Complexity by taking its mathematical definition as well as example with graph.
//*--> Lastly we will understand its practical usage & understand why we really need 3 different time complexity measures.

//! Big O  notation -
//* Big O notation specifically describes WORST CASE  scenario.  
//? It represents the upper bound running time complexity of an algorithm.
//? Mathematically -
//? Let f and g be functions of n - where n is natural no denoting size or steps of the algorithm then -
//? f(n) = O(g(n))
//? IFF
//? f(n) <= c.g(n)
//? where n >= n0, c > 0, n0 >= 1

//! Big Omega notation -
//* Big Omega notation specifically describes BEST CASE scenario.
//? It represents the lower bound running time complexity of an algorithm.
//? Basically it tells you what is the fastest time/behavior in which the algorithm can run.
//? f(n) = Ω(g(n))
//? IFF
//? f(n) >= c.g(n)
//? where n >= n0, c > 0, n0 >= 1

//! Big Theta (θ) notation -
//* Big Omega notation specifically describes AVERAGE CASE scenario.
//? It represents the most realistic time complexity of an algorithm.
//? f(n) = θ(g(n))
//? IFF
//? c1.g(n) <= f(n) <= c2.g(n)
//? where n >= n0, c1,c2 > 0, n >= n0, n0 greater = 1

//? Big Ω - Best Case
//? Big O - Worst Case
//? Big θ - Average Case

//! ORDER :
//TODO 1 < log(n) < sqrt(n) < n < n.log(n) < n^2 < n^3 < ..... n^n

//! Closest one is compared or taken into consideration.