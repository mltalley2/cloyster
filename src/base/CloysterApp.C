#include "CloysterApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<CloysterApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

CloysterApp::CloysterApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  CloysterApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  CloysterApp::associateSyntax(_syntax, _action_factory);
}

CloysterApp::~CloysterApp()
{
}

// External entry point for dynamic application loading
extern "C" void CloysterApp__registerApps() { CloysterApp::registerApps(); }
void
CloysterApp::registerApps()
{
  registerApp(CloysterApp);
}

// External entry point for dynamic object registration
extern "C" void CloysterApp__registerObjects(Factory & factory) { CloysterApp::registerObjects(factory); }
void
CloysterApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void CloysterApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { CloysterApp::associateSyntax(syntax, action_factory); }
void
CloysterApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
