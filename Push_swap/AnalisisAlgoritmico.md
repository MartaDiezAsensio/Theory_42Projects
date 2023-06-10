
ANÁLISIS DE ALGORITMOS

- EFICIENCIA

Para medir qué tan eficiente es un algoritmo nos queremos basar en datos teóricos. El motivo
de ello es que el tiempo que tardará en ejecutarse un programa no solo depende del código
sinó también del hardware.

Para medir teóricamente la eficiencia de un programa usamos la notación asintótica.

- NOTACIÓN ASINTÓTICA

Cuando queremos realizar un análisis teórico de algoritmos es común calcular su complejidad
en un sentido asintotico, es decir, para un tamaño de entrada suficientemente grande o 
infinito. La cota superior asintótica, y las notaciones omega (cota inferior) y theta (caso
promedio) se usan con esta finalildad. 

Por ejemplo, la búsqueda binária decimos que se ejecuta en una cantdad de pasos proporcional
a un logaritmo, en O(log(n)), coloquialmente "En tiempo logarítmico". Normalmente, las 
estimaciones asintóticas se utilizan dado que diferentes implementaciones del mismo algoritmo
no tienen por qué tener la misma eficiéncia.

- ORDENES DE CRECIMIENTO

De manera informal, se puede decir que un algoritmo exhibe una tase de crecimiento del orden
de una función matemática si más allá de cierto tamaño de entrada n, a función f(n) multiplicada
por una constante positiva proporciona un límite superior o límite para el tiempo de ejecución 
de un algoritmo.

Es decir, para un tamaño de entrada dado n mayor que algn