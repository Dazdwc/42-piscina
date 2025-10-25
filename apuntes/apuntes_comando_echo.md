# 🗣️ Comando `echo` — Mostrar texto y variables

## 🧠 Concepto
El comando **`echo`** sirve para **imprimir texto o valores en la terminal**.  
Es uno de los comandos más utilizados en scripting, debugging y ejercicios de la piscina 🏊‍♂️.

Con `echo` puedes mostrar mensajes, valores de variables, rutas, y también redirigir salidas a archivos.

---

## ⚙️ Sintaxis general

```bash
echo [opciones] [texto o variable]
```

---

## 📘 Ejemplos paso a paso

### 1️⃣ Mostrar un texto simple
```bash
echo "Hola Mundo"
```
🪶 Muestra:  
```
Hola Mundo
```

💡 Usa comillas si el texto contiene espacios.

---

### 2️⃣ Mostrar el valor de una variable
```bash
echo $USER
```
👤 Muestra el nombre de tu usuario actual (por ejemplo, `dani`).  
Perfecto para ejercicios donde debas imprimir información del entorno.

---

### 3️⃣ Mostrar el resultado de un comando
```bash
echo "Estoy en: $(pwd)"
```
📍 Combina `echo` con otros comandos usando `$()`.

Salida:
```
Estoy en: /home/dani/piscina/shell00
```

---

### 4️⃣ Evitar salto de línea al final
```bash
echo -n "Sin salto de línea"
```
🧱 La opción `-n` evita que `echo` añada un salto de línea al final.

---

### 5️⃣ Mostrar caracteres especiales o tabulaciones
```bash
echo -e "Primera línea\nSegunda línea"
```
🧩 La opción `-e` interpreta secuencias de escape (`\n`, `\t`, etc.).

Resultado:
```
Primera línea
Segunda línea
```

---

## ⚙️ Opciones comunes

| Opción | Descripción |
|--------|--------------|
| `-n` | No añade salto de línea final |
| `-e` | Interpreta secuencias de escape |
| `-E` | Desactiva las secuencias de escape (por defecto) |

---

## 🧩 Secuencias de escape útiles

| Secuencia | Efecto | Ejemplo |
|------------|--------|----------|
| `\n` | Nueva línea | `echo -e "Hola\nAdiós"` |
| `\t` | Tabulación | `echo -e "Col1\tCol2"` |
| `\a` | Alerta sonora (beep) | `echo -e "\a"` |
| `\\` | Barra invertida | `echo -e "Ruta: C:\\archivos"` |

---

## ⚠️ Errores comunes

🚫 **“$variable vacía”**  
> Si la variable no está definida, no mostrará nada.  
💡 Usa comillas dobles para evitar errores con espacios o vacíos.

🚫 **Texto sin comillas y con caracteres especiales**  
> `echo Hola Mundo!` puede romperse con `!` o `*` según la shell.  
💡 Usa `"comillas"` o `'comillas simples'`.

🚫 **Sin `-e` al usar `\n` o `\t`**  
> No se interpretarán los saltos o tabulaciones.  
💡 Recuerda siempre `echo -e` cuando uses secuencias.

---

## 🪄 Tips y buenas prácticas

- Usa `echo` para **debuggear scripts** o mostrar mensajes intermedios.  
- Combínalo con redirección para guardar en archivos:
  ```bash
  echo "Hola desde la piscina" > mensaje.txt
  ```
- Puedes añadir líneas a un archivo con `>>`:
  ```bash
  echo "Nueva línea" >> mensaje.txt
  ```
- Para imprimir variables en contexto:
  ```bash
  echo "Estás en $(pwd) y tu usuario es $USER"
  ```

---

## 🎯 Resumen

| Acción | Comando | Descripción |
|--------|----------|-------------|
| Mostrar texto | `echo "Hola"` | Muestra texto literal |
| Mostrar variable | `echo $USER` | Imprime valor de variable |
| Combinar comandos | `echo $(pwd)` | Inserta salida de otro comando |
| Sin salto de línea | `echo -n "texto"` | Evita salto al final |
| Con saltos o tabs | `echo -e "A\nB\tC"` | Interpreta secuencias |

---

> 💬 *“echo es tu voz en la terminal: habla, imprime y explica lo que pasa en tu código.”* 🗣️
