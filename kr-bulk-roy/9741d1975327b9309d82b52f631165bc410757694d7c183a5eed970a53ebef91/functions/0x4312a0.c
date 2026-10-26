
bool FUN_004312a0(ushort param_1,wchar_t param_2)

{
  ushort uVar1;
  int in_ECX;
  
  uVar1 = __Getwctype(param_2,(_Ctypevec *)(in_ECX + 8));
  return (param_1 & uVar1) != 0;
}

