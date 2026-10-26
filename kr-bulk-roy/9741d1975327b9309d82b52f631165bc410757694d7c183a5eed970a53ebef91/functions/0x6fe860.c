
void FUN_006fe860(int param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *local_14;
  
  iVar3 = FUN_006fee30();
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
    FUN_006fb3a0();
  }
  pcVar4 = FUN_0070d680;
  if (iVar3 != 0x1b) {
    pcVar4 = FUN_0070e420;
  }
  iVar3 = (*pcVar4)(param_1,*param_2,param_2 + 1,param_2[4]);
  iVar5 = FUN_006fd730(*(undefined1 *)(iVar3 + 0x48),*(undefined4 *)(param_1 + 0x48));
  iVar7 = 0;
  *(int *)(iVar5 + 0x10) = iVar3;
  if (*(char *)(iVar3 + 0x48) != '\0') {
    local_14 = (undefined4 *)(iVar5 + 0x14);
    do {
      iVar1 = *(int *)(param_1 + 0x10);
      puVar6 = (undefined4 *)(**(code **)(iVar1 + 0xc))(*(undefined4 *)(iVar1 + 0x10),0,0,0x20);
      if (puVar6 == (undefined4 *)0x0) {
        FUN_006fdb40(param_1,4);
        goto LAB_006fe971;
      }
      *(int *)(iVar1 + 0x44) = *(int *)(iVar1 + 0x44) + 0x20;
      iVar1 = *(int *)(param_1 + 0x10);
      *puVar6 = *(undefined4 *)(iVar1 + 0x1c);
      *(undefined4 **)(iVar1 + 0x1c) = puVar6;
      *(byte *)((int)puVar6 + 5) = *(byte *)(iVar1 + 0x14) & 3;
      puVar6[2] = puVar6 + 4;
      *(undefined1 *)(puVar6 + 1) = 10;
      puVar6[6] = 0;
      *local_14 = puVar6;
      iVar7 = iVar7 + 1;
      local_14 = local_14 + 1;
    } while (iVar7 < (int)(uint)*(byte *)(iVar3 + 0x48));
  }
  piVar2 = *(int **)(param_1 + 8);
  *piVar2 = iVar5;
  piVar2[2] = 6;
  if (*(int *)(param_1 + 0x1c) - *(int *)(param_1 + 8) < 0x11) {
    if (0 < *(int *)(param_1 + 0x2c)) {
      FUN_006fdcb0();
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      return;
    }
LAB_006fe971:
    FUN_006fdcb0();
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return;
}

