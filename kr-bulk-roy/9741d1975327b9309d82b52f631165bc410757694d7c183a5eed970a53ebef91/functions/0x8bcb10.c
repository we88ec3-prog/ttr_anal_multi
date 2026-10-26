
int FUN_008bcb10(undefined4 *param_1,int param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int extraout_EDX;
  
  puVar2 = param_1;
  puVar1 = param_1 + 3;
  uVar5 = param_1[0x15] + param_1[0xc] + param_2;
  uVar3 = *param_1;
  param_1 = (undefined4 *)0x0;
  iVar4 = 0;
  if (*puVar1 < uVar5) {
    uVar5 = uVar5 + 1 & 0xfffffffe;
    uVar3 = FUN_008bc7d0(uVar3,0x20,*puVar1,uVar5,puVar2[0xd],&param_1);
    puVar2[0xd] = uVar3;
    iVar4 = (int)param_1;
    if (param_1 == (undefined4 *)0x0) {
      puVar2[3] = uVar5;
      FUN_008b8340();
      iVar4 = extraout_EDX;
    }
  }
  return iVar4;
}

