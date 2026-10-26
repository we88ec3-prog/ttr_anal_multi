
/* Library Function - Single Match
    public: __thiscall std::exception::exception(char const * const &,int)
   
   Library: Visual Studio 2010 Release */

void __thiscall std::exception::exception(exception *this,char **param_1,int param_2)

{
  *(undefined ***)this = vftable;
  *(char **)(this + 4) = *param_1;
  this[8] = (exception)0x0;
  return;
}

