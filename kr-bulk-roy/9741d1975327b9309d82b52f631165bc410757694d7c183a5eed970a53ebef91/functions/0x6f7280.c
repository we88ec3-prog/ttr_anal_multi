
void FUN_006f7280(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x10);
  FUN_006f7200();
  uVar2 = FUN_006f99a0(param_1,0,2);
  *(undefined4 *)(param_1 + 0x48) = uVar2;
  *(undefined4 *)(param_1 + 0x50) = 5;
  iVar3 = *(int *)(param_1 + 0x10);
  uVar2 = FUN_006f99a0(param_1,0,2);
  *(undefined4 *)(iVar3 + 0x60) = uVar2;
  *(undefined4 *)(iVar3 + 0x68) = 5;
  FUN_006feb00(param_1,0x20);
  FUN_006fea00();
  FUN_006ff030();
  iVar3 = FUN_006fec70(param_1,"not enough memory",0x11);
  *(byte *)(iVar3 + 5) = *(byte *)(iVar3 + 5) | 0x20;
  *(int *)(iVar1 + 0x40) = *(int *)(iVar1 + 0x44) * 4;
  return;
}

