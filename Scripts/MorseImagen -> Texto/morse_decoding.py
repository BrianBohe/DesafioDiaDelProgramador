from PIL import Image

blanco=(255,255,255)
negro=(0,0,0)

punto = [blanco,negro,blanco]
barra = [negro,negro,negro]
fin_letra = [blanco,blanco,blanco]

morseAlphabet ={
        "A" : ".-",
        "B" : "-...",
        "C" : "-.-.",
        "D" : "-..",
        "E" : ".",
        "F" : "..-.",
        "G" : "--.",
        "H" : "....",
        "I" : "..",
        "J" : ".---",
        "K" : "-.-",
        "L" : ".-..",
        "M" : "--",
        "N" : "-.",
        "O" : "---",
        "P" : ".--.",
        "Q" : "--.-",
        "R" : ".-.",
        "S" : "...",
        "T" : "-",
        "U" : "..-",
        "V" : "...-",
        "W" : ".--",
        "X" : "-..-",
        "Y" : "-.--",
        "Z" : "--..",
        " " : "/",
        "?" : "..--..",
        "*" : ".-.-.-",
        "," : "--..--",
        "0" : "-----",
        "1" : ".----",
		"2" : "..---",
		"3" : "...--",
		"4" : "....-",
		"5" : ".....",
		"6" : "-....",
		"7" : "--...",
		"8" : "---..",
		"9" : "----."
}
inverseMorseAlphabet = dict((v,k) for (k,v) in morseAlphabet.items())

im = Image.open("desafioprogramador.png") #Can be many different formats.
pix = im.load()
width, heigth = im.size
tipos_de_pixels = []

def indice_mas_a_la_izquierda(anImage):
	primera_linea = heigth
	ultima_linea = 0
	mas_a_la_izquierda = width
	mas_a_la_derecha = 0

	vi_la_primer_linea = False
	for j in range(0,heigth):
		vi_al_primer_punto_negro = False
		encontre_algo = False

		for i in range(0,width):
			if negro == pix[i,j]:

				mas_a_la_izquierda = min(i, mas_a_la_izquierda)

				primera_linea = min( j, primera_linea)

				mas_a_la_derecha = max( mas_a_la_derecha, i)

				ultima_linea = j

	return primera_linea, ultima_linea, mas_a_la_izquierda, mas_a_la_derecha


i_arriba,i_abajo,i_izq,i_der = indice_mas_a_la_izquierda(im)

contador_entero=0
for fila in range(0,heigth):
	for columna in range(0,width):
		if negro == pix[columna,fila]:
			contador_entero+=1

contador_recortado=0
texto = ""

letra_en_progreso = ""
espacios = 0
for fila in range(i_arriba,i_abajo+1,3):
	columna = i_izq

	if letra_en_progreso != "":
		texto += (inverseMorseAlphabet[letra_en_progreso])
		letra_en_progreso = ""
	
	espacios=0

	while columna < i_der+1:

		if punto == [pix[columna,fila],pix[columna+1,fila],pix[columna+2,fila]]:
			letra_en_progreso += "."
			contador_recortado +=1
			espacios=0

		if barra == [pix[columna,fila],pix[columna+1,fila],pix[columna+2,fila]]:
			letra_en_progreso += "-"
			contador_recortado += 3
			espacios=0

		if fin_letra == [pix[columna,fila],pix[columna+1,fila],pix[columna+2,fila]]:
			espacios +=1

			if 1 < espacios and letra_en_progreso != "":
				texto += (inverseMorseAlphabet[letra_en_progreso])
				letra_en_progreso = ""
			if 2 < espacios and espacios < 4:
				texto += " "

		columna +=4


print(texto)
#Queria estar seguro de haber visto la misma cantidad de pixeles negros
print (contador_recortado)
print (contador_entero)