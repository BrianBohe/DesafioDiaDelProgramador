
X = 540992328500517893750391624101174224
otraCadena = "673dbc07b736642ba64d2da5557056377674"

X_en_str = str(X)
X_en_lista = ["0x"+X_en_str[i*2]+X_en_str[i*2+1] for i in range(18)]

otraCadena_en_str = str(otraCadena)
otraCadena_en_lista = ["0x"+otraCadena_en_str[i*2]+otraCadena_en_str[i*2+1] for i in range(18)]


resultado = [int(otraCadena_en_lista[i],16)^int(X_en_lista[i],16) for i in range(18)]
resultado_hex = [hex(int(otraCadena_en_lista[i],16)^int(X_en_lista[i],16)) for i in range(18)]

#print(resultado)
#print(resultado_hex)

resultado_corrido=""
resultado_hex_corrido=""

for i in range(18):
	resultado_corrido+=str(resultado[i])
	resultado_hex_corrido += str(resultado_hex[i])[2:]

print("Resultado secuencia en int {}".format(resultado_corrido))
print("Resultado secuencia en hex {}".format(str(resultado_hex_corrido)))

print("Y ahora a String esto es: ")

print ([bytes.fromhex(resultado_hex[i][2:]).decode('utf-8') for i in range(18)])
print (bytes.fromhex(resultado_hex_corrido))