
/* Library Function - Single Match
    public: __thiscall std::bad_cast::bad_cast(char const *)
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

bad_cast * __thiscall std::bad_cast::bad_cast(bad_cast *this,char *param_1)

{
  exception::exception((exception *)this,&param_1);
  *(undefined ***)this = vftable;
  return this;
}

