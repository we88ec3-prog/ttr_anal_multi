
undefined4 FUN_00701510(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  char *pcVar4;
  undefined4 *puVar5;
  int iVar6;
  code *pcVar7;
  undefined4 local_8;
  
  iVar1 = param_1;
  piVar2 = *(int **)(param_1 + 0xc);
  if (((piVar2 < *(int **)(param_1 + 8)) && (piVar2 != &DAT_00c0bfc8)) && (piVar2[2] == 8)) {
    iVar6 = 1;
    if (*(int **)(param_1 + 8) <= piVar2) {
      piVar2 = &DAT_00c0bfc8;
    }
    if (piVar2[2] == 8) {
      param_1 = *piVar2;
    }
    else {
      param_1 = 0;
    }
  }
  else {
    iVar6 = 0;
  }
  puVar3 = (undefined4 *)FUN_006f50f0();
  if ((puVar3 == &DAT_00c0bfc8) || ((int)puVar3[2] < 1)) {
    FUN_006f5220();
    pcVar7 = (code *)0x0;
    iVar6 = 0;
    local_8 = 0;
  }
  else {
    FUN_006f6210(iVar1);
    puVar3 = (undefined4 *)FUN_006f50f0();
    if ((puVar3 == &DAT_00c0bfc8) || (puVar3[2] != 6)) {
      puVar3 = (undefined4 *)FUN_006f50f0();
      if ((puVar3 == &DAT_00c0bfc8) || (puVar3[2] == -1)) {
        pcVar4 = "no value";
      }
      else {
        pcVar4 = (&PTR_DAT_00c0be1c)[puVar3[2]];
      }
      FUN_006f5580(iVar1,"%s expected, got %s","function",pcVar4);
      FUN_006f5da0(iVar6 + 1);
    }
    puVar3 = (undefined4 *)FUN_006f50f0();
    if ((puVar3 == &DAT_00c0bfc8) || ((int)puVar3[2] < 1)) {
      local_8 = 0;
    }
    else {
      local_8 = FUN_006f6370(iVar1,iVar6 + 3);
    }
    pcVar7 = FUN_00701320;
    iVar6 = FUN_00701400(local_8);
  }
  FUN_00701450();
  piVar2 = *(int **)(iVar1 + 8);
  *piVar2 = param_1;
  piVar2[2] = 2;
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 0x10;
  puVar5 = (undefined4 *)FUN_006f50f0();
  puVar3 = *(undefined4 **)(iVar1 + 8);
  *puVar3 = *puVar5;
  puVar3[1] = puVar5[1];
  puVar3[2] = puVar5[2];
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 0x10;
  FUN_006f57f0(iVar1);
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + -0x10;
  if ((pcVar7 == (code *)0x0) || (iVar6 == 0)) {
    iVar6 = 0;
    pcVar7 = (code *)0x0;
  }
  *(code **)(param_1 + 0x44) = pcVar7;
  *(char *)(param_1 + 0x38) = (char)iVar6;
  *(undefined4 *)(param_1 + 0x3c) = local_8;
  *(undefined4 *)(param_1 + 0x40) = local_8;
  return 0;
}

