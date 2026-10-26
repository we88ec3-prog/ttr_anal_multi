
int FUN_008bb920(undefined4 param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *in_EDX;
  
  uVar1 = *in_EDX;
  iVar2 = FUN_008bb8b0();
  if (iVar2 != 0) {
    FUN_008b9f80(uVar1);
    return iVar2;
  }
  if (param_2 != 0) {
    FUN_008b8f30();
  }
  iVar2 = FUN_008bd6d0();
  if (iVar2 == 0) {
    *(uint *)(*param_3 + 8) = *(uint *)(*param_3 + 8) & 0xfffffbff;
    return 0;
  }
  FUN_008b97c0(0);
  FUN_008b9f80(uVar1,0);
  return iVar2;
}

