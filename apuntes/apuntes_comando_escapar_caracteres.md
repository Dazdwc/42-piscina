# 🧩 Escapar caracteres en Bash — Controlar cómo se interpreta el texto

## 🧠 Concepto
En Bash, **escapar** significa decirle a la terminal que **no interprete un carácter de forma especial**.  
Esto es fundamental porque muchos símbolos (`$`, `"`, `'`, `*`, `|`, `>`, etc.) tienen **significado propio** en la shell.  

Si no los escapas correctamente, Bash puede ejecutar cosas que no querías o mostrar errores.

---

## ⚙️ Símbolos especiales más comunes

| Carácter  | Uso normal | Qué pasa si no lo escapas |
|-----------|-------------|---------------------------|
| `$`       | Llama a variables | Bash intenta expandir el nombre (`$USER`, `$HOME`) |
| `*`       | Comodín (todos los archivos) | Muestra o usa todos los archivos coincidentes |
| `?`       | Comodín (un solo carácter) | Coincide con cualquier archivo de un carácter |
| `\|`      | Pipe | Conecta comandos |
| `>` / `<` | Redirecciones | Sobrescribe o lee archivos |
| `&`       | Ejecuta en segundo plano | El comando no espera |
| `!`       | Historial o negación | Puede expandir comandos anteriores |
| `#`       | Comentario | Ignora el resto de la línea |

---

## 📘 Formas de escapar caracteres

### 1️⃣ Barra invertida `\` — Escapa un solo carácter
```bash
echo "El símbolo del dólar se escribe así: \$"
```
➡️ Resultado:
```
El símbolo del dólar se escribe así: $
```
💡 `\` le dice a Bash: “trata el siguiente carácter como texto literal”.

---

### 2️⃣ Comillas simples `' '` — Nada se interpreta dentro
```bash
echo 'Mi usuario es $USER'
```
➡️ Resultado literal:
```
Mi usuario es $USER
```
🧱 Dentro de `' '`, Bash **no interpreta variables ni comandos**.

---

### 3️⃣ Comillas dobles `" "` — Se interpretan variables y comandos
```bash
echo "Mi usuario es $USER"
```
➡️ Resultado:
```
Mi usuario es dani.z
```
🧩 Dentro de `" "`, Bash **sí expande** variables (`$USER`), pero sigue respetando espacios y la mayoría de caracteres.

---

### 4️⃣ Escapar dentro de comillas dobles
```bash
echo "Esto cuesta \$42"
```
➡️ Resultado:
```
Esto cuesta $42
```
💡 Dentro de `" "`, solo necesitas escapar algunos caracteres especiales (`$`, `"`, `` ` `` y `\`).

---

### 5️⃣ Evitar que el asterisco se expanda
```bash
echo \*
```
📁 Muestra literalmente `*` en lugar de listar todos los archivos del directorio.

---

### 6️⃣ Escapar espacios en rutas
```bash
cd Mi\ Carpeta/
```
💡 El espacio se interpreta como parte del nombre del archivo o carpeta.

Alternativamente:
```bash
cd "Mi Carpeta/"
```

---

### 7️⃣ Escapar saltos de línea (comandos largos)
```bash
echo "Esto es una frase muy larga y quiero seguir en la misma línea"
```
➡️ La barra invertida `\` al final **une las dos líneas** en una sola.

---

## ⚙️ Diferencias entre comillas simples y dobles

| Tipo | Expande variables | Respeta espacios | Escapa caracteres | Ejemplo |
|------|-------------------|------------------|-------------------|----------|
| `'texto'` | ❌ No | ✅ Sí | No se necesita | `'Hola $USER'` → `Hola $USER` |
| `"texto"` | ✅ Sí | ✅ Sí | Necesario para `$`, `"`, `\` | `"Hola $USER"` → `Hola dani.z` |
| Sin comillas | ✅ Sí | ❌ No | ❌ | `echo Hola mundo` → separa en dos argumentos |

---

## ⚠️ Errores comunes

🚫 **“command not found” o “No such file”**  
> Los espacios no escapados separan los argumentos.  
💡 Usa comillas o `\` para unirlos:  
`cd "Mi Carpeta"` ✅

🚫 **“ambiguous redirect”**  
> Bash interpreta mal un `>` o `<` por falta de escape.  
💡 Usa comillas o espacios para separar correctamente.

🚫 **Variable no expandida**  
> Usaste comillas simples `' '` en lugar de dobles `" "`.  
💡 Dentro de `' '`, nada se interpreta.

---

## 🪄 Tips y buenas prácticas

- Siempre que tengas dudas, **usa comillas dobles** `" "` para proteger cadenas con espacios o variables.  
- Si necesitas escribir algo tal cual, sin interpretación, usa **comillas simples** `' '`.  
- Para rutas o nombres con espacios, comillas o `\` son imprescindibles.
- Puedes comprobar cómo Bash interpreta una línea con:
  ```bash
  echo "Comando interpretado:"
  set -x
  echo "Mi carpeta es $HOME/Documentos"
  set +x
  ```

---

## 🎯 Resumen

| Caso | Forma recomendada | Resultado |
|------|--------------------|------------|
| Mostrar `$` literal | `echo "\$"` | `$` |
| Mostrar variable expandida | `echo "$USER"` | `dani.z` |
| Texto con espacios | `echo "Hola Mundo"` | `Hola Mundo` |
| Rutas con espacios | `cd "Mi Carpeta/"` | Accede correctamente |
| No expandir variables | `echo '$USER'` | `$USER` |
| Saltos de línea largos | `\` al final | Une en una línea |

---

> 💬 *“Escapar es hablar el idioma secreto de Bash: le dices cuándo pensar… y cuándo callar.”* 🧠  
> Domina esto, y tus comandos nunca volverán a fallar por un simple espacio.
