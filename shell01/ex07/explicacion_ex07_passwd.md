# 🧩 explicacion_ex07_passwd.md

Este ejercicio consiste en procesar el archivo `/etc/passwd` mediante una serie de comandos encadenados en **bash**, aplicando varios filtros y transformaciones.

---

## 🧠 Objetivo

Mostrar el resultado del comando `cat /etc/passwd`, **quitando los comentarios**, mostrando **una de cada dos líneas** (empezando por la segunda), **invirtiendo los nombres de usuario**, **ordenando alfabéticamente en orden inverso**, **filtrando entre dos líneas dadas por variables de entorno**, y finalmente **uniendo los resultados separados por comas y terminando en punto**.

---

## 🧰 Herramientas utilizadas

| Comando | Función |
|----------|----------|
| `Variables de entorno` | Para definir los valores usados en el filtrado (`FT_LINE1` y `FT_LINE2`) |
| `cat` | Muestra el contenido de `/etc/passwd` |
| `grep` | Filtra los comentarios |
| `awk` | Aplica filtros y permite seleccionar líneas pares |
| `cut` | Muestra solo el usuario (campo 1 del fichero) |
| `rev` | Invierte el nombre de usuario |
| `sort` | Ordena los resultados alfabéticamente (en este caso, en orden inverso) |
| `sed` | Aplica filtros con variables y da formato final (espacios y punto) |
| `paste` | Une todos los resultados en una sola línea separándolos por comas |

---

## 🧩 Desarrollo paso a paso

### 1️⃣ Quitar los comentarios
```bash
  cat /etc/passwd | grep -v "^#"
```

### 2️⃣ Mostrar una de cada dos líneas, empezando por la segunda
```bash
  awk 'NR%2==0'
```

### 3️⃣ Mostrar solo el nombre de usuario e invertirlo
```bash
  cut -d: -f1 | rev
```

### 4️⃣ Ordenar alfabéticamente en orden inverso
```bash
  sort -r
```

### 5️⃣ Filtrar por rango de líneas usando variables de entorno
```bash
  export FT_LINE1=7
  export FT_LINE2=15
  sed -n "${FT_LINE1},${FT_LINE2}p"
```

### 6️⃣ Unir todos los resultados y separarlos por comas
```bash
  paste -sd "," -
```

### 7️⃣ Añadir un espacio después de cada coma y un punto final
```bash
  sed -e 's/,/, /g;s/$/./'
```

---

## ⚙️ Script completo

Una vez verificado cada paso, podemos crear un script ejecutable con:

```bash
  vim r_dwssap.sh
```

Contenido del archivo:

```bash
  #!/bin/bash
  cat /etc/passwd | grep -v "^#" | awk 'NR%2==0' | cut -d: -f1 | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | paste -sd "," - | sed -e 's/,/, /g;s/$/./'
```

---

## 🧪 Notas

> Si al ejecutar obtienes un error del tipo  
> `sed: -e expresión #1, carácter 1: orden desconocida: «,»`  
> asegúrate de tener las variables de entorno definidas:

```bash
  export FT_LINE1=7
  export FT_LINE2=15
```

Después, ejecuta el script:

```bash
  bash script.sh
```

---

## ✅ Resultado esperado

Una sola línea con los nombres de usuario procesados, separados por coma y espacio, terminando en punto.

**Ejemplo:**
```
zorba, yoshi, user42, toto, root.
```
