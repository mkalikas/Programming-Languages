#pragma once

enum type_kind
{
  ty_int,
  ty_bool,
  ty_arrow,
  ty_tuple,
  ty_record
};

struct type
{
  type(type_kind k) : kind(k) {}

  type_kind kind;
};

struct int_type : type 
{
  int_type() : type(ty_int) {}
};

struct bool_type : type 
{
  bool_type() : type(ty_bool) {}
};

struct arrow_type : type 
{
  arrow_type(type* t1, type* t2) : type(ty_arrow), args(t1), ret(t2)
  {}

  type* args;
  type* ret;
};

struct tuple_type : type 
{

};

struct record_type : type
{
  
};