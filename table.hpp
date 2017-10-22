/*
TABLE: Tabela ou relação, como o seu esquema (lista de campos ou colunas) e a lista de linhas, 
ou registros que a compõem em um determinado momento. 

Pode possuir uma chave primária (formado por um ou mais campos), 
ou relações de dependência com outras tabelas (entidade fraca ou relacionamento M-N)

Além do nome, a tabela possui estatísticas associadas, tais como timestamps da criação/modificação (do esquema), 
número de linhas, tamanho do arquivo em disco etc. 
Deve-se prever a existência de índices (INDEX) envolvendo um ou mais campos da tabela.
*/

#pragma once

#include "field.hpp"
#include <vector>
#include <ctime>

class Record;

class Index 
{
	// visible as Index::Parameters
	struct Parameters
	{
		std::string type;
		bool ascendig;
		bool clustered;
	};
	
	public:
	Index()
	{
	}
	private:
	std::vector<Field *> fields;
	std::vector<Parameters> params;
}

class Table 
{
 public:
  Table()
  {
  	this->schema_creation_date = std::time(nullptr);
  }
 private:
  uint32_t lines;
  double   file_size;

  std::string name;
  std::vector<Field *> fields;
  std::vector<Record *> records;
  std::vector<Index *> indexes;

  std::time_t schema_creation_date;
  std::time_t schema_last_update;

  bool add_record(Record *);
  bool remove_record(Record *);
  bool update_schema(std::string new_name = null,
				     std::vector<Field *> new_fields = null,
				     std::vector<Record *> new_records = null,
				     std::vector<Index *> new_indexes = null);
};