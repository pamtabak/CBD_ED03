/*
1. FIELD: 
Atributo de uma relação, ou coluna de uma tabela, ou campo de um registro. 

Define um item de dado como sendo uma sequencia de um ou mais bytes que possui um significado. 

Seus possíveis valores definem o “Domínio” do campo:
- Podem ser de tamanho fixo ou variável, por exemplo, strings ou campos binários longos: OK
- Os campos também, por sua vez, podem representar uma estrutura (tipo ou classe de objetos), 
ou ser multivalorados (sequência como um array ou lista de valores): OK
- Deve prever restrições de integridade associada ao campo, tais como:
  Ser chave primária (ou parte da chave) : OK
  Unicidade de valor (UNIQUE): OK
  Indeterminação (NULL/UNKNOW): OK
  Se é uma chave estrangeira: OK
  Se possui um padrão de formação (associado ao domínio), 
  Valor padrão (default): OK
  Restrições quanto ao UPDATE de certo valor para outro (por exemplo, de um estado civil para outro): OK
*/

#pragma once

#include <iostream>
#include <stdint.h>

class Field 
{
 public:
  Field(bool unique, bool nullable, bool mandatory, bool updatable, bool primary_key,
    bool foreign_key, uint16_t size, uint16_t max_size, const std::string &name) :
      unique_(unique),
      nullable_(nullable),
      mandatory_(mandatory),
      updatable_(updatable),
      primary_key_(primary_key),
      foreign_key_(foreign_key),
      size_(size),
      max_size_(max_size),
      name_(name) {}
 private:
  bool unique_;
  bool nullable_;
  bool mandatory_;
  bool updatable_;
  bool primary_key_;
  bool foreign_key_;
  uint16_t size_;
  uint16_t max_size_;
  std::string name_;
};

template <class T> class ValueField : Field 
{
 public:
  ValueField(T value, T default_value, bool unique, bool nullable,
             bool mandatory, bool updatable, bool primary_key, bool foreign_key, 
             uint16_t size, uint16_t max_size, const std::string &name) :
      Field(unique, nullable, mandatory, updatable, size, max_size, name),
      value_(value),
      default_value_(default_value) {}
  void Print();
 private:
  T value_;
  T default_value_;
};

template <class T> void ValueField<T>::Print() 
{
  std::cout << value_ << std::endl;
}
