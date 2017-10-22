/*
TABLE: Tabela ou relação, como o seu esquema (lista de campos ou colunas) e a lista de linhas, 
ou registros que a compõem em um determinado momento. 

Pode possuir uma chave primária (formado por um ou mais campos), 
ou relações de dependência com outras tabelas (entidade fraca ou relacionamento M-N). 

Além do nome, a tabela possui estatísticas associadas, tais como timestamps da criação/modificação (do esquema), 
número de linhas, tamanho do arquivo em disco etc. 
Deve-se prever a existência de índices (INDEX) envolvendo um ou mais campos da tabela.
*/

#pragma once

#include "field.hpp"
#include <vector>
#include <ctime>

class Record;

class Table {
 private:
  uint32_t lines;
  double   fileSize;

  std::string name;
  std::vector<Field *> pks;
  std::vector<Field *> fields;
  std::vector<Record *> records;

  std:time_t schemaCreationDate;
  std:time_t schemaLastUpdateDate;

  bool add_record(Record *);
  bool remove_record(Record *);
};
