import matplotlib.pyplot as plt

archivo = open("datos.txt", "r")

lineas = archivo.readlines()

archivo.close()

x1 = []
y1 = []

x2 = []
y2 = []

x3 = []
y3 = []

x4 = []
y4 = []

for linea in lineas:

    datos = linea.split()

    if len(datos) > 0:

        idParticula = int(datos[1])

        x = float(datos[2])
        y = float(datos[3])

        if idParticula == 1:
            x1.append(x)
            y1.append(y)

        elif idParticula == 2:
            x2.append(x)
            y2.append(y)

        elif idParticula == 3:
            x3.append(x)
            y3.append(y)

        elif idParticula == 4:
            x4.append(x)
            y4.append(y)

plt.plot(x1, y1, label="Particula 1")
plt.plot(x2, y2, label="Particula 2")
plt.plot(x3, y3, label="Particula 3")
plt.plot(x4, y4, label="Particula 4")

plt.xlabel("Posicion X")
plt.ylabel("Posicion Y")

plt.title("Simulacion de Particulas")

plt.legend()

plt.grid()

plt.show()

input("Presione enter para cerrar")