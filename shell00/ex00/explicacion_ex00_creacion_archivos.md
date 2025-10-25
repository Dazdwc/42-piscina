# 🧩 EX00 - creación de archivos

Para este ejercicio vamos a necesitar entender algo muy básico de **bash**:  
la **creación y visualización de archivos**.  

Para ello nos serviremos de **dos comandos esenciales** 👇

> 📝 **`vim`** → para crear el archivo con el contenido que nos indique el enunciado.  
> 👀 **`cat`** → para comprobar qué contiene el archivo.

---

## 🚀 Pasos a seguir

### 1️⃣ Una vez descargado el repositorio y creada la carpeta `ex00`:
Abrimos un archivo nuevo con:
```bash
  vim z
```
Esto abrirá el editor **Vim** dentro de la terminal.

---

### 2️⃣ Dentro de Vim:
> 1. Pulsa la tecla **`a`** para entrar en *modo inserción* ✍️  
>    - Ahora podrás escribir texto dentro del archivo.
>    (En este caso, escribe la letra **Z**).
>
> 2. Una vez escrita, presiona **`Esc`** para salir del modo inserción.  
>
> 3. Guarda los cambios y sal con:
>    ```vim
>    :wq
>    ```
>    o alternativamente:
>    ```vim
>    :x
>    ```

💡 *El ejercicio pide un salto de línea al final del archivo, pero Vim ya lo añade automáticamente por defecto.*  

---

### 3️⃣ Comprobar el contenido del archivo
Una vez guardado, puedes verificar que el archivo contiene exactamente la letra **Z** con:

```bash
cat z
```

📄 Deberías ver como salida:
```
Z
```

---

> 💬 *Consejo:* si el archivo no se muestra correctamente o no ves la Z, asegúrate de haber salido del modo inserción (`Esc`) antes de guardar.
