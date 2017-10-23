/* As classes devem conter membros que permitam o funcionamento do ciclo básico de um banco de dados, 
ou seja, a localização de dados em memória secundária, cópia para memória principal para processamento e
reescrita para o disco se o dado for alterado. Assim, todas as classes devem considerar as operações 
usuais da DML, ou seja, INSERT, UPDATE, DELETE e SELECT. Além disso, devem considerar que na cláusula
WHERE pode-se usar qualquer combinação de campos, chave ou não. 

A seleção de registros devem considerar o uso de valor único (como em “SELECT * FROM 
Aluno WHERE dre = 109536876”), ou conjunto de valores (com em “SELECT * FROM Aluno WHERE dre 
IN (113456987, 110234987, 112567345)” e por faixa de valores (com em “SELECT * FROM Aluno WHERE 
data_nascimento BETWEEN ‘2000-01-01’ and ‘2010-06-31’ ”).
*/

#include "field.hpp"
#include "table.hpp"
#include <iostream>

// g++ main.cpp -o main.out

int main () 
{
	return 0;
}