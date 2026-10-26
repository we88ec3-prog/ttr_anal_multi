
int FUN_008bd2a0(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  code *pcVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return 0x23;
  }
  if (*(uint *)(param_1 + 0x10) <= param_2) {
    return 0x10;
  }
  pcVar1 = *(code **)(*(int *)(*(int *)(param_1 + 0x60) + 0xc) + 0x54);
  if ((pcVar1 != (code *)0x0) && (((param_3 & 3) != 0 || ((param_3 & 0xf0000) == 0x10000)))) {
    iVar2 = (*pcVar1)(param_1,param_2,1,param_3,param_4);
    if (iVar2 == 0) {
      iVar2 = FUN_008ba1b0(param_1,1,param_3);
      return iVar2;
    }
    if ((char)iVar2 != '\a') {
      return iVar2;
    }
  }
  iVar2 = FUN_008bc850(param_1,param_2,1,param_3,param_4);
  return iVar2;
}

