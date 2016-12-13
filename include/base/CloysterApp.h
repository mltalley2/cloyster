#ifndef CLOYSTERAPP_H
#define CLOYSTERAPP_H

#include "MooseApp.h"

class CloysterApp;

template<>
InputParameters validParams<CloysterApp>();

class CloysterApp : public MooseApp
{
public:
  CloysterApp(InputParameters parameters);
  virtual ~CloysterApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* CLOYSTERAPP_H */
