-- File:    BinaryTree.hs
-- Date:    may 2023
-- Coms:    Práctica 6 de la asignatura Tecnología de Programación. 
--          Fichero que incluye la función BinaryTree.
module BinaryTree where
import Data.List

--como dijo yolanda que hay que crear un arbol vacío
-- print $ empty no compila (solo para arbol vacio)
-- print $ (empty::Tree Int)
-- print $ (empty::Tree())

-- Definimos el tipo de datos BinaryTree.
data BinaryTree a = Empty
                  | Leaf a
                  | Tree a (BinaryTree a) (BinaryTree a)


instance Show a => Show (BinaryTree a) where
  show = showBinaryTree 0

-- La función showBinaryTree 
showBinaryTree :: Show a => Int -> BinaryTree a -> String
showBinaryTree _ Empty = "<>"
showBinaryTree _ (Leaf x) = show x
showBinaryTree n (Tree x l r) =
  show x ++ "\n" ++
  indent (n+1) ++ "|─ " ++ showBinaryTree (n+1) l ++ "\n" ++
  indent (n+1) ++ "|─ " ++ showBinaryTree (n+1) r

-- La función indent es una función auxiliar utilizada
-- para tabular la impresión de los árboles binarios.
indent :: Int -> String
indent 0 = ""
indent n = "  " ++ indent (n-1)

-- La función empty crea un árbol binario vacío.
empty :: BinaryTree a
empty = Empty

-- La función leaf crea una hoja con el valor indicado (a).
leaf :: a -> BinaryTree a
leaf = Leaf

-- La función tree crea un árbol binario.
tree :: a -> BinaryTree a -> BinaryTree a -> BinaryTree a
tree = Tree

-- La función size permite calcular el tamaño de un árbol binario.
size :: BinaryTree a -> Int
size Empty = 0
size (Leaf _) = 1
size (Tree _ lc rc) = 1 + size lc + size rc

-- La función add permite añadir un valor a un árbol binario.
add :: Ord a => BinaryTree a -> a -> BinaryTree a
add Empty x = Leaf x
add (Leaf l) x
  | x <= l = Tree l (Leaf x) Empty
  | otherwise = Tree l Empty (Leaf x)
add (Tree a lc rc) x
  | x <= a = Tree a (add lc x) rc
  | otherwise = Tree a lc (add rc x)

-- La función build construye un árbol binario a partir de una lista.
build :: Ord a => [a] -> BinaryTree a
build = foldl add empty

-- La función buildBalanced construye un árbol binario 
-- balanceado a partir de una lista dada.
buildBalanced :: Ord a => [a] -> BinaryTree a
buildBalanced [] = Empty
buildBalanced xs = buildBalanced' (sort xs)
  where
    buildBalanced' :: [a] -> BinaryTree a
    buildBalanced' [] = Empty
    buildBalanced' [x] = Leaf x
    buildBalanced' xs = Tree node (buildBalanced' left) (buildBalanced' right)
      where
        mid = length xs `div` 2
        (left, node:right) = splitAt mid xs

-- La función preorder devuelve los valores de un árbol binario
-- en preorden.
preorder :: BinaryTree a -> [a]
preorder Empty = []
preorder (Leaf x) = [x]
preorder (Tree x lc rc) = [x] ++ preorder lc ++ preorder rc

-- La función postorder devuelve los valores de un árbol binario
-- en postorden.
postorder :: BinaryTree a -> [a]
postorder Empty = []
postorder (Leaf x) = [x]
postorder (Tree x lc rc) = postorder lc ++ postorder rc ++ [x]

-- La función inorder devuelve los valores de un árbol binario
-- en orden ascendente.
inorder :: BinaryTree a -> [a]
inorder Empty = []
inorder (Leaf x) = [x]
inorder (Tree x lc rc) = inorder lc ++ [x] ++ inorder rc

-- La función balance recibe un árbol binario de búsqueda y
-- devuelve un árbol binario de búsqueda balanceado.
balance :: Ord a => BinaryTree a -> BinaryTree a
balance t = buildBalanced (inorder t)

-- La función between devuelve los valores de un árbol binario 
-- que estén entre los dos valores dados (xmin y xmax).
between :: Ord a => BinaryTree a -> a -> a -> [a]
between Empty _ _ = []
between (Leaf x) xmin xmax
  | x >= xmin && x <= xmax = [x]
  | otherwise = []
between (Tree x lc rc) xmin xmax
  | x < xmin = between rc xmin xmax
  | x > xmax = between lc xmin xmax
  | x >= xmin && x <= xmax = [x] ++ between lc xmin xmax ++ between rc xmin xmax
  | otherwise = between lc xmin xmax ++ between rc xmin xmax



