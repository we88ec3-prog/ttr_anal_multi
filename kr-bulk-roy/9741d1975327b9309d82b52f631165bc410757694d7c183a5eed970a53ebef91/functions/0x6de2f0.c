
byte * FUN_006de2f0(byte *param_1,byte *param_2)

{
  int iVar1;
  int in_ECX;
  
  if (param_1 != param_2) {
    do {
      iVar1 = __Tolower((uint)*param_1,(_Ctypevec *)(in_ECX + 8));
      *param_1 = (byte)iVar1;
      param_1 = param_1 + 1;
    } while (param_1 != param_2);
  }
  return param_1;
}

