# Tarea 2. Análisis de Algoritmos

---

##### Integrantes:
1. Esteban Manrique de Lara Sirvent - A01027077 - Campus Santa Fe
2. Miguel Ángel Hernández Maldonado - A01022398 - Campus Santa Fe
3. Luis Emilio Alcántara Guzmán - A01027304 - Campus Santa Fe
4. Fernando Hurtado Chaurand - A01026025 - Campus Santa Fe
5. *[Poner aquí Nombre y Apellidos del integrante 5]* - *[Poner aquí su Matrícula]* - *[Poner aquí su campus]*

---
## 1. Aspectos generales

Las orientaciones de la tarea se encuentran disponibles en la plataforma **Canvas**.

Este documento es una guía sobre qué información debe entregar como parte de la tarea, qué requerimientos técnicos debe cumplir y la estructura que debe seguir para organizar su entrega.


### 1.1 Requerimientos técnicos

A continuación se mencionan los requerimientos técnicos mínimos de la tarea, favor de tenerlos presente para que cumpla con todos.

* El código debe desarrollarse en C++, cumpliendo con el último estándar [C++17](https://isocpp.org/std/the-standard).
* Toda la programación debe realizarse utilizando Programación Genérica.
* Deben utilizarse las [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md).
* Todo el código debe estar correctamente documentado, siguiendo los lineamientos que aparecen en [Documenting C++ Code](https://developer.lsst.io/cpp/api-docs.html).
* Todo el código de la tarea debe alojarse en este repositorio de GitHub.
* Debe configurar su repositorio para que utilice el sistema de Integración Continua [Travis CI](https://travis-ci.org/).

### 1.2 Estructura del repositorio

El proyecto debe seguir la siguiente estructura de carpetas:
```
- / 			        # Raíz del repositorio
    - README.md			# Archivo con la información general de la actividad (este archivo)
    - sources  			# Códigos fuente con la solución
    - examples			# Archivos de ejemplo que pueden utilizarse para verificar que la solución funciona.
```

## 2. Solución

*[Incluya aquí una explicación de la solución implementada]*

### 2.1 Pasos a seguir para utilizar la aplicación

1.	Clonar el repositorio de GitHub
   
    a.	Pegar la liga en el navegador
   
        i.      https://github.com/tec-csf/tc2017-t2-primavera-2020-equipo-3-1.git
   
    b.	Dar Click en el botón verde “Clone or Download”
        
        i.      Seleccionar “Open in Desktop”
        ii.     Se descagará un archivo .ZIP
        iii.    “tc2017-t2-primavera-2020-equipo-3-1-master”
   
    c.	Descomprimir el archivo .zip
        
        i.	    Se creara la carpeta “tc2017-t2-primavera-2020-equipo-3-1-master”
        
2.	Abrir el compilador Visual Studio Code en su Servidor

    a.	Abrir la carpeta clonada “tc2017-t2-primavera-2020-equipo-3-1-master"
    
    b.	Abrir el archivo “Arboles.cpp”
    
        i.      Modificar la cantidad de números que se quiere analizar
        ii.     Linea 1276 --> tree.completeImplementation(10, btree);
        ii.     (10, btree) modificar el "número" a la cantidad deseada 10, 100, 10000, 100000, etc.
        
    
    c.	Abrir la terminal del Visual Studio Code
        
        i.	    “Ctrl+ñ”
    
    d.	Compilar el archivo "Arboles.cpp" 
        
        i.      "bash"
        ii.     "g++ Arboles.cpp -o arboles
        iii.    "./arboles"
        iiii.   Se crearán y guardarán varios archivos
    
    e. Verficar los archivos creados que contienen los tiempos de cada implementación
    
    f. Abrir el archivo "Grafica.py"
    
    g. Compilar el archivo "Grafica.py"
        
        i.      Sombrear todo el código
        ii.     presionar "Ctrl+alt+F5"
        iii.    Se crearán y guardarán varias imágenes
        
    h. Verificar que se crearon las imagenes de las gráficas
        
    i.	Analizar resultados de los tiempos en las gráficas



## 3. Referencias

*[Incluya aquí las referencias a sitios de interés y cualquier otra información que haya utilizado para realizar la actividad y que le puedan ser de utilidad a otras personas que quieran usarlo como referencia]*
