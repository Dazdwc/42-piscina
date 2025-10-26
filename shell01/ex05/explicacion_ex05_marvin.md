# 🧩 explicacion_ex05_marvin.md

Este ejercicio consiste en crear un archivo con un **nombre lleno de caracteres especiales** que contenga únicamente el texto `42`.

---

## 🧠 Objetivo

Aprender a **escapar correctamente caracteres especiales** en Bash (`"`, `'`, `$`, `*`, `?`, `\`), y a crear un archivo con contenido exacto.

---

## 🧰 Herramientas utilizadas

| Herramienta | Función |
|--------------|----------|
| `touch` | Crea un archivo vacío |
| `echo` | Escribe texto en el archivo |
| *(concepto)* `escapar caracteres` | Permite que el shell no interprete símbolos especiales |

---

## 🧩 Desarrollo paso a paso

### 1️⃣ Crear a Marvin

Usamos `touch` para crear el archivo con el nombre exacto pedido:

```bash
touch "\"\?\$*'MaRViN'*\$?\\\""
```

💡 **Importante:**  
Cada carácter especial debe ir escapado con `\` o dentro de comillas dobles.  
Esto evita que Bash interprete cosas como `$`, `?` o `*` como variables o comodines.

Resultado esperado al listar:
```bash
ls -l
-rw-r--r-- 1 user user 0 Oct 26 14:42 ""\?$*'MaRViN'*\$?\""
```

---

### 2️⃣ Darle vida a Marvin (escribir `42`)

Ahora usamos `echo` para escribir el texto dentro del archivo sin salto de línea:

```bash
echo -n "42" > "\"\?\$*'MaRViN'*\$?\\\""
```

🔹 `-n` → evita añadir el salto de línea al final.  
🔹 `>` → redirige la salida del comando al archivo Marvin.

---

### 3️⃣ Verificar que Marvin está bien creado

```bash
cat -e "\"\?\$*'MaRViN'*\$?\\\""
```

Salida esperada:
```text
42$
```
(`$` indica el final de la línea, no forma parte del archivo).

---

## ✅ Resultado final

- Archivo creado:  
  `"\?$*'MaRViN'*\$?\"`  
- Contenido exacto:  
  `42` (sin salto de línea)
