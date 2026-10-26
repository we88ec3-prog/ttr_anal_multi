
/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Multiple Matches With Same Base Name
    protected: void __thiscall std::time_get<char,class std::istreambuf_iterator<char,struct
   std::char_traits<char> > >::_Init(class std::_Locinfo const &)
    protected: void __thiscall std::time_get<unsigned short,class std::istreambuf_iterator<unsigned
   short,struct std::char_traits<unsigned short> > >::_Init(class std::_Locinfo const &)
    protected: void __thiscall std::time_get<wchar_t,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::_Init(class std::_Locinfo const &)
   
   Library: Visual Studio 2010 Release */

void Init(_Locinfo *param_1)

{
  char *pcVar1;
  int iVar2;
  int in_ECX;
  _Collvec _Var3;
  undefined4 uVar4;
  undefined4 uVar5;
  _Collvec *p_Var6;
  _Collvec *p_Var7;
  
  _Var3 = __Getcoll();
  p_Var7 = (_Collvec *)(in_ECX + 0x14);
  uVar4 = 0;
  *p_Var7 = _Var3;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  p_Var6 = p_Var7;
  pcVar1 = std::_Locinfo::_Getdays(param_1);
  uVar4 = FUN_004302b0(pcVar1,uVar4,p_Var6);
  uVar5 = 0;
  *(undefined4 *)(in_ECX + 8) = uVar4;
  pcVar1 = std::_Locinfo::_Getmonths(param_1);
  uVar4 = FUN_004302b0(pcVar1,uVar5,p_Var7);
  *(undefined4 *)(in_ECX + 0xc) = uVar4;
  iVar2 = __Getdateorder();
  *(int *)(in_ECX + 0x10) = iVar2;
  return;
}

