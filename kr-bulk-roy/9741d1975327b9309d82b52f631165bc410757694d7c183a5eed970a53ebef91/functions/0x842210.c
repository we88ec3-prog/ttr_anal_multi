
int FUN_00842210(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_58 [21];
  
  iVar2 = (param_2 - param_1) / 0x50;
  if (1 < iVar2) {
    puVar3 = (undefined4 *)(param_2 + -0x50);
    do {
      puVar4 = puVar3;
      puVar5 = local_58;
      for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      FUN_00842ea0(puVar3,local_58,param_3,param_4,param_5);
      puVar3 = puVar3 + -0x14;
      iVar1 = (0x50 - param_1) + (int)puVar3;
      iVar2 = iVar1 * 0x66666667;
    } while (1 < iVar1 / 0x50);
  }
  return iVar2;
}

