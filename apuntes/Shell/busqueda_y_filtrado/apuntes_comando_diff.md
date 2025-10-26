# 🔍 Comando `diff` — Comparar archivos línea a línea

## 🧠 Concepto
El comando **`diff`** sirve para **comparar el contenido de dos archivos** y mostrar en qué se diferencian.  
Es una herramienta muy usada en programación para comprobar si el resultado que has generado es igual al esperado por el ejercicio.

En la Piscina, `diff` es clave para verificar si tu salida es idéntica a la del ejemplo del PDF o al archivo de corrección.

---

## ⚙️ Sintaxis general

```bash
diff [opciones] archivo1 archivo2
```

---

## 📘 Ejemplos paso a paso

### 1️⃣ Comparar dos archivos simples
```bash
diff mi_salida.txt salida_correcta.txt
```
🔎 Muestra las diferencias entre ambos archivos línea por línea.

📤 Si no hay salida, significa que **los archivos son iguales**.

---

### 2️⃣ Entender el resultado de `diff`

Ejemplo:
```bash
1c1
< Hola Mundo
---
> Hola mundo
```
📖 Significa:
- En la **línea 1** hay una **diferencia** (`c` = change).  
- `<` indica lo que hay en tu archivo.  
- `>` indica lo que hay en el archivo correcto.

💡 En este caso, la diferencia está en la mayúscula: “Mundo” ≠ “mundo”.

---

### 3️⃣ Mostrar diferencias en formato unificado (más legible)
```bash
diff -u mi_salida.txt salida_correcta.txt
```
📋 Muestra las líneas que cambian con un poco de contexto antes y después.

Ejemplo:
```diff
--- mi_salida.txt
+++ salida_correcta.txt
@@ -1 +1 @@
-Hola Mundo
+Hola mundo
```

---

### 4️⃣ Guardar solo las líneas diferentes en un archivo
```bash
diff --unchanged-line-format="" --old-line-format="" --new-line-format="%L" A total > B
```
🧩 Este comando crea un archivo `B` con solo las líneas nuevas de `total` que no estaban en `A`.

---

### 5️⃣ Ignorar espacios o mayúsculas/minúsculas
```bash
diff -iw a.txt b.txt
```
- `-i` → ignora diferencias entre mayúsculas y minúsculas  
- `-w` → ignora espacios en blanco

💡 Muy útil cuando los archivos son iguales “lógicamente”, pero difieren en formato.

---

## ⚙️ Opciones comunes

| Opción | Descripción |
|--------|--------------|
| `-u` | Formato unificado (más limpio) |
| `-i` | Ignora diferencias de mayúsculas/minúsculas |
| `-w` | Ignora espacios en blanco |
| `--side-by-side` | Muestra los archivos en dos columnas |
| `--color=auto` | Muestra diferencias en color (si tu terminal lo permite) |

---

## ⚠️ Errores comunes

🚫 **Error: “No such file or directory”**  
> Uno de los archivos no existe o la ruta está mal escrita.  
💡 Comprueba con `ls` o usa rutas relativas correctas (`./ex00/mi_archivo.txt`).

🚫 **El resultado muestra cambios raros**  
> Puede que tus archivos tengan diferencias invisibles como tabulaciones o espacios.  
💡 Usa `cat -A archivo` para ver todos los caracteres ocultos.

---

## 🪄 Tips y buenas prácticas

- Si quieres saber **solo si son iguales o diferentes**, usa:
  ```bash
  diff -q archivo1 archivo2
  ```
  Mostrará solo si hay diferencias o no.
- Si quieres guardar el resultado en un archivo:
  ```bash
  diff -u a b > diferencias.txt
  ```
- Úsalo en combinación con `cat` o `echo` para comparar salidas de programas:
  ```bash
  ./a.out > salida.txt
  diff salida.txt salida_correcta.txt
  ```

---

## 🎯 Resumen

| Acción | Comando | Descripción |
|--------|----------|-------------|
| Comparar archivos | `diff a b` | Muestra las diferencias |
| Comparar sin mostrar iguales | `diff -q a b` | Indica solo si son distintos |
| Formato limpio | `diff -u a b` | Unifica diferencias |
| Ignorar espacios/mayúsculas | `diff -iw a b` | Evita falsos positivos |
| Mostrar en columnas | `diff --side-by-side a b` | Muestra ambos archivos a la vez |

---

> 💬 *“`diff` no te dice solo qué está mal, sino dónde y por qué.”*  
> Es tu espejo más honesto durante la Piscina. 🪞
