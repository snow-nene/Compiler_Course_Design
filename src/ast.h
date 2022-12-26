#pragma once
#include<memory>
#include<iostream>
// 所有 AST 的基类
class BaseAST {
 public:
  virtual ~BaseAST() = default;

  virtual void Dump() const = 0;
};


class CompUnitAST : public BaseAST {
 public:
  std::unique_ptr<BaseAST> func_def;

  void Dump() const override {
    std::cout << "CompUnitAST { ";
    func_def->Dump();
    std::cout << " }";
  }
};
class FuncDefAST : public BaseAST {
 public:
  std::unique_ptr<BaseAST> func_type;
  std::string ident;
  std::unique_ptr<BaseAST> block;

  void Dump() const override {
    std::cout << "FuncDefAST { ";
    func_type->Dump();
    std::cout << ", " << ident << ", ";
    block->Dump();
    std::cout << " }";
  }
};
class FuncTypeAST:public BaseAST{
  public:
    std::string type;
  
  void Dump() const override {
      std::cout << " { ";
      std::cout<<type;
      std::cout << " } ";
  }

};
class BlockAST:public BaseAST{
   public:
    std::unique_ptr<BaseAST> stmt;
  
  void Dump() const override {
      std::cout << " BlockAST { ";
      stmt->Dump();
      std::cout << " } ";
  }
};
class StmtAST:public BaseAST{
   public:
    int num;
  void Dump() const override {
      std::cout<<num;
  }
};
