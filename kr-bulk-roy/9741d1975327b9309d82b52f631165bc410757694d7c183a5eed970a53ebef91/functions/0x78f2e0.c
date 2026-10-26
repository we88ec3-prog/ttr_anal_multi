
int FUN_0078f2e0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int in_ECX;
  int iVar3;
  undefined1 local_40 [60];
  
  iVar3 = in_ECX - in_EAX;
  iVar1 = iVar3 / 0x3c;
  iVar2 = iVar1;
  while (1 < iVar2) {
    FUN_007866a0();
    FUN_00789f20();
    iVar3 = iVar3 + -0x3c;
    FUN_00790010(iVar3 / 0x3c,local_40,param_1);
    iVar1 = iVar3 * -0x77777777;
    iVar2 = iVar3 / 0x3c;
  }
  return iVar1;
}

