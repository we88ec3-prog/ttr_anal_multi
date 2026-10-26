
/* Library Function - Single Match
    public: __thiscall std::locale::id::operator unsigned int(void)
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release */

uint __thiscall std::locale::id::operator_unsigned_int(id *this)

{
  id *local_8;
  
  if (*(int *)this == 0) {
    local_8 = this;
    _Lockit::_Lockit((_Lockit *)&local_8,0);
    if (*(int *)this == 0) {
      DAT_00f8c848 = DAT_00f8c848 + 1;
      *(int *)this = DAT_00f8c848;
    }
    FUN_0087dd6f();
  }
  return *(uint *)this;
}

