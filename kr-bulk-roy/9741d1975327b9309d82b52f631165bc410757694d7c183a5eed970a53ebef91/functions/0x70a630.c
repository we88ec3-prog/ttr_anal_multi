
undefined4 FUN_0070a630(int param_1)

{
  undefined4 *puVar1;
  char *_Str;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  _Str = (char *)FUN_006f6210(param_1);
  pcVar2 = _strchr(_Str,0x2e);
  if (pcVar2 == (char *)0x0) {
    return 0;
  }
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
    FUN_006fb3a0();
  }
  puVar1 = *(undefined4 **)(param_1 + 8);
  uVar3 = FUN_006fec70(param_1,_Str,(int)pcVar2 - (int)_Str);
  *puVar1 = uVar3;
  puVar1[2] = 4;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  iVar4 = *(int *)(param_1 + 8);
  if (*(int *)(iVar4 + -8) != 4) {
    iVar4 = FUN_006fb5d0();
    if (iVar4 == 0) {
      iVar4 = 0;
      goto LAB_0070a6ca;
    }
    if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    iVar4 = *(int *)(param_1 + 8);
  }
  iVar4 = *(int *)(iVar4 + -0x10) + 0x10;
LAB_0070a6ca:
  iVar4 = FUN_0070a230(iVar4,"cpath");
  if (iVar4 != 0) {
    uVar3 = FUN_0070a560();
    iVar5 = FUN_0070a0a0(iVar4,uVar3);
    if (iVar5 != 0) {
      if (iVar5 != 2) {
        FUN_0070a470(iVar4);
      }
      FUN_006f5580(param_1,"\n\tno module \'%s\' in file \'%s\'",_Str,iVar4);
    }
  }
  return 1;
}

