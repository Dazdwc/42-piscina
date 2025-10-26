# 🧩 explicacion_ex04_mac_address.md

Este ejercicio consiste en mostrar la **dirección MAC** (hardware address) de las interfaces de red de la máquina.

---

## 🧠 Objetivo

Extraer la dirección MAC usando comandos de red y filtrado de texto en shell.

---

## 🧰 Herramientas utilizadas

| Comando    | Función                                                                 |
|------------|-------------------------------------------------------------------------|
| `ifconfig` | Muestra la configuración de las interfaces de red                      |
| `grep`     | Filtra líneas que contienen cierto texto                               |
| `awk`      | Permite seleccionar columnas concretas del resultado línea a línea     |

> Nota: en algunas máquinas modernas `ifconfig` no está instalado y se usa `ip link`.  
> Pero en la piscina de 42 normalmente se permite `ifconfig` para este tipo de ejercicio.

---

## 🧩 Desarrollo paso a paso

### 1️⃣ Obtener la info de red
```bash
  ifconfig
```
Esto saca todas las interfaces (lo, eth0, enp0s3, wlan0, etc.) con datos como IP, máscara, broadcast y dirección física (MAC).  
La MAC suele aparecer en una línea que contiene la palabra `ether`.

Ejemplo típico de trozo de salida:
```text
enp0s3: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 10.0.2.15  netmask 255.255.255.0  broadcast 10.0.2.255
        ether 08:00:27:4a:5b:6c  txqueuelen 1000  (Ethernet)
```

### 2️⃣ Filtrar solo las líneas con `ether`
```bash
  ifconfig | grep ether
```
Salida aproximada:
```text
ether 08:00:27:4a:5b:6c  txqueuelen 1000  (Ethernet)
ether a4:b1:c2:d3:e4:f5  txqueuelen 1000  (Ethernet)
```

### 3️⃣ Quedarnos solo con la MAC
En esa línea, la dirección MAC es la **segunda columna**.

Usamos `awk '{print $2}'`:
```bash
  ifconfig | grep ether | awk '{print $2}'
```
Salida esperada:
```text
08:00:27:4a:5b:6c
a4:b1:c2:d3:e4:f5
```

💡 Si tu máquina solo tiene una interfaz activa, verás una sola línea.

---

## ⚙️ Script final

Vamos a crear un script llamado `MAC.sh` (en tu borrador ponías `count_files.sh`, pero eso era del ex03 😜).

```bash
  vim MAC.sh
```

Contenido del archivo:
```bash
  #!/bin/bash
  ifconfig | grep ether | awk '{print $2}'
```

Guardas y sales (`:wq`).  
Luego le das permisos de ejecución:

```bash
  chmod +x MAC.sh
```

Y lo ejecutas:
```bash
  ./MAC.sh
```

---

## ✅ Resultado esperado

Una o varias direcciones MAC en formato estándar:
```text
08:00:27:4a:5b:6c
```
