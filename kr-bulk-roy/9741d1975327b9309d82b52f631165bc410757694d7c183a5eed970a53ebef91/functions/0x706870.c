
int FUN_00706870(int param_1)

{
  char *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int local_8;
  
  puVar2 = *(undefined4 **)(param_1 + 0xc);
  if (puVar2 < *(undefined4 **)(param_1 + 8)) {
    if ((puVar2 != &DAT_00c0bfc8) && (puVar2[2] == 5)) goto LAB_007068d4;
    if ((*(undefined4 **)(param_1 + 8) <= puVar2) ||
       ((puVar2 == &DAT_00c0bfc8 || (puVar2[2] == -1)))) goto LAB_007068a6;
    pcVar1 = (&PTR_DAT_00c0be1c)[puVar2[2]];
  }
  else {
LAB_007068a6:
    pcVar1 = "no value";
  }
  FUN_006f5580(param_1,"%s expected, got %s","table",pcVar1);
  FUN_006f5da0(1);
LAB_007068d4:
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
  if (((puVar2 < *(undefined4 **)(param_1 + 8)) && (puVar2 != &DAT_00c0bfc8)) &&
     (0 < *(int *)(*(int *)(param_1 + 0xc) + 0x18))) {
    local_8 = FUN_006f6370(param_1,2);
  }
  else {
    local_8 = 1;
  }
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x20);
  if (((puVar2 < *(undefined4 **)(param_1 + 8)) && (puVar2 != &DAT_00c0bfc8)) &&
     (0 < *(int *)(*(int *)(param_1 + 0xc) + 0x28))) {
    iVar3 = FUN_006f6370(param_1,3);
  }
  else {
    iVar3 = FUN_006f5460();
  }
  iVar6 = (iVar3 - local_8) + 1;
  if (0 < iVar6) {
    iVar4 = FUN_006f5170();
    if (iVar4 == 0) {
      FUN_006f5f30(param_1,"stack overflow (%s)","table too big to unpack");
    }
    for (; local_8 <= iVar3; local_8 = local_8 + 1) {
      puVar2 = *(undefined4 **)(param_1 + 8);
      puVar5 = (undefined4 *)FUN_006f9b70(local_8);
      *puVar2 = *puVar5;
      puVar2[1] = puVar5[1];
      puVar2[2] = puVar5[2];
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    }
    return iVar6;
  }
  return 0;
}

