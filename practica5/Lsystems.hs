-- File:    Lsystems.hs
-- Date:    may 2023
-- Coms:    Fichero Lsystems.hs de la práctica 5 de la asignatura Tecnología de Programación. 

module Lsystems where

--Lista de funciones con las reglas de cada imagen
rules :: Char -> String
rules r
 | r == 'F' = "G-F-G"
 | r == 'G' = "F+G+F"
 | otherwise = [r]

aux :: (Char -> String) -> String -> String
aux _ [] = []
aux a (s:ms) = a s ++ aux a ms

--Función Lsystem para generar la cadena para cada imagen
lsystem :: (Char -> String) -> String -> Int -> String
lsystem a rules f
 | f == 0 = rules
 | f >= 1 = lsystem a (aux a rules) (f-1)
 | otherwise = []


-- Curva de Kock
rulesKock :: Char -> String
rulesKock r
 | r == 'F' = "F+F--F+F"
 | otherwise = [r]


-- Curva de Koch cuadrada
rulesKockC :: Char -> String
rulesKockC r
 | r == 'F' = "F+F-F-F+F"
 | otherwise = [r]


-- Koch Snowflake
rulesSnowflake :: Char -> String
rulesSnowflake r
 | r == 'F' = "F-F++F-F"
 | otherwise = [r]


-- Koch Anti-Snowflake
rulesAntiSnowflake :: Char -> String
rulesAntiSnowflake r
 | r == 'F' = "F+F--F+F"
 | otherwise = [r]


-- Isla de Minkowski
rulesIsla :: Char -> String
rulesIsla r
 | r == 'F' = "F+F-F-FF+F+F-F"
 | otherwise = [r]


-- Triángulo de Sierpinsky
rulesTriangulo :: Char -> String
rulesTriangulo r
 | r == 'F' = "F-G+F+G-F"
 | r == 'G' = "GG"
 | otherwise = [r]


-- Sierpinsky Arrowhead
rulesArrowhead :: Char -> String
rulesArrowhead r
 | r == 'F' = "G-F-G"
 | r == 'G' = "F+G+F"
 | otherwise = [r]


-- Curva de Hilbert
rulesHilbert :: Char -> String
rulesHilbert r
 | r == 'f' = "-g>+f>f+>g-"
 | r == 'g' = "+f>-g>g->f+"
 | otherwise = [r]


-- Curva de Gosper
rulesGosper :: Char -> String
rulesGosper r
 | r == 'F' = "F-G--G+F++FF+G-"
 | r == 'G' = "+F-GG--G-F++F+G"
 | otherwise = [r]


