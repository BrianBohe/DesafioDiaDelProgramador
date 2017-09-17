import fileinput

tope = 11501

primos_hasta_11500 = [0 for i in range(tope)]

## necesito generar el 0
combinaciones = [ [0 for i in range(tope)], [0 for i in range(tope)]]

for i in range(0, tope):
	primos_hasta_11500[i] = 0
	combinaciones[0][i] = 0
	combinaciones[1][i] = 0

combinaciones[0][0]=1
combinaciones[1][0]=1
lista_de_primos = []

for line in fileinput.input():
	num = int(line)
	lista_de_primos.append(num)
	primos_hasta_11500[num]=1

swap_row=0

for i in range(len(lista_de_primos)):

	swap_row = swap_row^1

	for j in range(1, lista_de_primos[i]):
		combinaciones[swap_row][j] = combinaciones[swap_row^1][j]

	for j in range(lista_de_primos[i], tope):
		combinaciones[swap_row][j] = combinaciones[swap_row^1][j] + combinaciones[swap_row^1][j-lista_de_primos[i]]
		#if combinaciones[swap_row][j] != combinaciones[swap_row^1][j]:
		#	print("{}={}+{}".format(j,j-lista_de_primos[i],lista_de_primos[i]))


acum = 0
primos_hasta_11500[0] = 1
for i in range(tope):
	acum += combinaciones[swap_row][i] - primos_hasta_11500[i]

#print(primos_hasta_11500[0:12])
#print(combinaciones[swap_row][0:30])
#print(swap_row)
print (acum)
##print(lista_de_primos[i])

##print (primos_hasta_11500)
#print (combinaciones)
