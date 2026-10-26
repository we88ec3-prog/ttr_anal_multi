
/* Library Function - Single Match
    public: __thiscall std::_Lockit::_Lockit(int)
   
   Library: Visual Studio 2010 Release */

_Lockit * __thiscall std::_Lockit::_Lockit(_Lockit *this,int param_1)

{
  *(int *)this = param_1;
  if (param_1 < 4) {
    __Mtxlock((_Rmtx *)(&DAT_00f8c7a0 + param_1 * 0x18));
  }
  return this;
}

