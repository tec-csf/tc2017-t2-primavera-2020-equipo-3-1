# Tarea 2. Análisis de Algoritmos

---

##### Integrantes:
1. Esteban Manrique de Lara Sirvent - A01027077 - Campus Santa Fe
2. Miguel Ángel Hernández Maldonado - A01022398 - Campus Santa Fe
3. Luis Emilio Alcántara Guzmán - A01027304 - Campus Santa Fe
4. Fernando Hurtado Chaurand - A01026025 - Campus Santa Fe
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
Se presenta una solución compuesta por 3 archvios: Arboles.cpp, BtreeAux.cpp y Graphics.py. Arboles.cpp plantea el desarrollo completo de las estructuras AVL y B; para ambos árboles, se desarrollaron métodos auxiliares diversos (división de nodos, lectura y escritura en disco, obtención de factor de balanceo, rotaciones, entre otros) que ayudan a concretar las 3 oepraciones básicas de estos: Inserción, Búsqueda y Eliminación. Asimismo, se desarrolló un método único que permite la implementación a la par de ambas estructuras (completeImplementation()). El árbol AVL se programó para que trabaje con memoria RAM, mientras que el B fue desarrollado para use la memoria secundaria del dispositivo en el que sea corrido (en este caso, una Rasberry Pi). El archivo Arboles.cpp genera archivos .txt con toda la información pertinente a los tiempos transcurridos durnate cada operación realizada sobre los dos árboles. En relación con el archivo BtreeAux.cpp, este sirve como un archivo auxiliar en donde se establecieron las estructuras y métodos a ser utilizados por Arboles.cpp para implementar los árboles B. Finalmente, Graphics.py genera mapas de calor de las mediciones de tiempo generadas por cada una de las operaciones de los árboles previamente mencionados; estas son luego mostradas al usuario como archivos PNG para una mejor visualización. Es importante recalcar que el archivo Arboles.cpp debe ser EJECUTADO ANTES que el Graphics.py para que las gráficas puedan ser generadas con información adecuada y actualizada. A continuación, se presentan instrucciones más claras de como utilizar la solución propuesta en este apartado.

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

Edpresso. (2020). What is an AVL?. Retrieved 22 March 2020, from https://www.educative.io/edpresso/what-is-an-avl

Morris, J. (1998). Data Structures and Algorithms: AVL Trees. Retrieved 22 March 2020, from https://www.cs.auckland.ac.nz/software/AlgAnim/AVL.htm

lTutorial Points. (2020). Data Structure and Algorithms - AVL Trees - Tutorialspoint. Retrieved 22 March 2020,from https://www.tutorialspoint.com/data_structures_algorithms/avl_tree_algorithm.html

Old Dominion University. (2012). 2.6. Complexity. Retrieved 22 March 2020, from https://www.cs.odu.edu/~zeil/cs361/web/website/Lectures/avl/pages/avlcomplexity.html

GeeksforGeeks. (2020). Complexity of different operations in Binary tree, Binary Search Tree and AVL tree -GeeksforGeeks. Retrieved 22 March 2020, from https://www.geeksforgeeks.org/complexity-different-operations-binary-tree-binary-search-tree-avl-tree/

Lippmann, J. (1998). 5.4.1 Definition of B-Trees. Retrieved 22 March 2020, from http://lcm.csa.iisc.ernet.in/dsa/node122.html

Java Point. (2018). B Tree - javatpoint. Retrieved 22 March 2020, from https://www.javatpoint.com/b-tree

Cornell.  (2012).  B-trees.  Retrieved  22  March  2020,  from  https://www.cs.cornell.edu/courses/cs3110/2012sp/recitations/rec25-B-trees/rec25.html

C++.(2020). Reference - cplusplus. Retrieved 22 March 2020, from http://www.cplusplus.com/reference/

