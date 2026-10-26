
/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Multiple Matches With Same Base Name
    protected: void __thiscall std::numpunct<unsigned short>::_Init(class std::_Locinfo const
   &,bool)
    protected: void __thiscall std::numpunct<wchar_t>::_Init(class std::_Locinfo const &,bool)
   
   Library: Visual Studio 2010 Release */

void Init(undefined4 param_1,char param_2)

{
  undefined2 uVar1;
  lconv *plVar2;
  undefined4 uVar3;
  int in_ECX;
  _Collvec _Var4;
  _Collvec local_24;
  _Collvec local_1c [2];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x8815ed;
  plVar2 = _localeconv();
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  local_8 = 0;
  if (param_2 == '\0') {
    local_1c[0]._LocaleName = (wchar_t *)plVar2->grouping;
  }
  else {
    local_1c[0]._LocaleName = L"";
  }
  __Getcoll();
  uVar3 = FUN_00430270(local_1c[0]._LocaleName,0,&local_24);
  *(undefined4 *)(in_ECX + 8) = uVar3;
  local_1c[0] = __Getcoll();
  uVar3 = _Maklocstr<>("false",0,local_1c);
  *(undefined4 *)(in_ECX + 0x10) = uVar3;
  _Var4 = __Getcoll();
  local_1c[0] = _Var4;
  uVar3 = _Maklocstr<>(&DAT_00bf943c,0,local_1c);
  *(undefined4 *)(in_ECX + 0x14) = uVar3;
  local_24 = __Getcoll();
  uVar1 = _Maklocchr<>(*plVar2->decimal_point,0,&local_24);
  *(undefined2 *)(in_ECX + 0xc) = uVar1;
  _Var4 = __Getcoll();
  local_24 = _Var4;
  uVar1 = _Maklocchr<>(*plVar2->thousands_sep,0,&local_24);
  *(undefined2 *)(in_ECX + 0xe) = uVar1;
  if (param_2 != '\0') {
    _Var4 = __Getcoll();
    local_24 = _Var4;
    uVar1 = _Maklocchr<>(0x2e,0,&local_24);
    *(undefined2 *)(in_ECX + 0xc) = uVar1;
    _Var4 = __Getcoll();
    local_24 = _Var4;
    uVar1 = _Maklocchr<>(0x2c,0,&local_24);
    *(undefined2 *)(in_ECX + 0xe) = uVar1;
  }
  return;
}

