Por el momento se me ocurren tener las siguientes 4 clases:

Piece, Board, Player y Game. Todas abstractas.

- Las piezas deberían saber como moverse, no el tablero.
- Las piezas deberían tener su posición en el tablero.


- Hexagon grid representation: https://www.redblobgames.com/grids/hexagons/

Hola Facundo. Primero deberías diseñar una clase Tablero, que sea virtual pura (una interfaz) y ponerle los métodos que debería implementar cualquier clase que herede de ella (los tableros reales). Estos métodos deberían ser lo que una pieza de ajedrez necesite para moverse, es decir que el Tablero funciona como un contexto para la pieza de ajedrez (que por cierto tamibén es una clase virtual pura para que las clases de piezas reales hereden de ella). Esto lo podés hacer si querés pensando en el juego tradicional, pero sin implementar realmente nada. Por ejemplo, una pieza puede querer moverse en dirección "horizontal", o en "diagonal" a partir de su posición actual. Para esto yo implementaría el concepto de posición dentro de un tablero (en mi cabeza se parece mucho a un iterador sobre un contenedor que este caso es el tablero). Toda pieza de ajedrez tendría su posición. La posición tiene un talbero como contexto . Una posición puede mutar (es lo que hace una pieza de ajedrez cuando se mueve) pero siempre dentro del tablero y de acuerdo a las reglas y limitaciones que este imponga. De esta manera, una pieza de ajedrez puede ir generando todas las posiciones accesibles, de acuerdo a sus moviemientos naturales, a partir de la poscición actual y decidir si esa posición es válida (si no está ocupada por otra pieza propia por ej).  Obviamente yo tengo en mi cabeza lo que sería mi propio diseño, pero no tiene por qué ser el tuyo (TIMTOWTDI)

## Errores

- stringInSet, recibe el set por copia solo para checkear si existe...


## Comentarios de Fabian
- El uso de unicode para imprimir el talbero y las piezas en una terminal embellece el programa, pero también lo hace menos portable (la terminal de Linux maneja bien estos caracteres, pero en Windows es un problema y de hecho no pude hacer que funcione ahi).
- Explota muy poco el polimorfismo (tema central de este ejercicio): en la jerarquia de Piece solo la printPiece lo usa bien, y en la de Board, solo hay una clase derivada.
- La clase Board (y su derivada) no solo representa el tablero, sino que hace todo lo importante, incluso interactúa con el usuario y define la variante del juego (de hecho ChessBoard.cpp tiene mas de 700 lineas de código mientras que los demás .cpp no tienen más de 60)
- La separación entre Board y ChessBoard no está clara. Parte de la representación en Board sólo es usada desde métodos de ChessBoard.
- El numero y tipo de jugadores está hardcodeado en Board (siempre son 2 humanos, blanco y negro e incluso el turno es un bool) y también siempre existen 1 Rey de cada color.
- La implementación es poco eficiente (cada vez que mueve una pieza, destruye y vuelve a reconstruir las posiciones de todas las piezas.)
- Lo que llama allWhiteMoves y allBlackMoves son en realidad sets de posiciones atacadas por alguna pieza del jugador de dicho color. Esta información se usa para saber si el rey está en jaque.
- Incluye los headers de las clases derivadas en los headers de las clases base Board y Piece.

### Diseño e implementación:
- Clase Piece y sus derivadas: 
	- Debería contener la posición de la pieza en el tablero.  
	- El enum State no se para qué es o por qué está en este header.
	- El enum PieceType limita las posibles herencias y hace que el polimorfismo sea innecesario. getPossibleMoves podría no ser virtual y se podría implementar en la clase base ya que esta tiene toda la información, por ej. asi:
	- std::set<std::string> Piece::getPossibleMoves(Board *board, std::string from) { return board->getValidMoves(from, type); }
	- El metodo updateAllValidMoves de ChessBoard recorre el talbero, y para cada pieza pide getPosibleMoves que inmediatamente le vuelve a pedir al tablero getValidMoves...
- Clase Board y su derivada ChessBoard:
	- La clase Board representa al mismo tiempo el tablero y las reglas del juego (el talbero sabe cómo mover las piezas, si hay un ganador, por ejemplo).
	- Los métodos stringInSet y printSet, reciben sets por copia y podrían perfectamente recibir una referencia const.
	- El uso de strings para representar las posiciones fue una buena elección (aunque me hubiera gustado un using para poder distinguir las posiciones de otros strings), ya que no sólo facilita la interfaz con el usuario, sino que también se podría generalizar a otras topologías de tableros.
	- makeMove recibe dos strings por copia, pero internamente solicita al usuario que los ingrese.(???)
	- El único constructor de ChessBoard coloca las piezas en sus posiciones iniciales, pero sólo para algunos pocos casos posibles (limitando innecesariamente las posibilidades).
	- Cada vez que se realiza un movimiento se regeneran todas las posiciones en Board (poco eficiente).
	Clase ChessGame: 
		tienen un puntero a Board, pero en el constructor usa new ChessBoard().
		play() invoca a makeMove de Board, con dos argumentos inútiles y el retorno no lo usa para nada.