
void FUN_007034f0(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  undefined4 extraout_EDX;
  undefined1 *puVar5;
  undefined4 uVar6;
  int iVar7;
  undefined1 local_208 [512];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if (puVar1 < *(undefined4 **)(param_1 + 8)) {
    if ((puVar1 == &DAT_00c0bfc8) || (puVar1[2] != 6)) {
      if ((*(undefined4 **)(param_1 + 8) <= puVar1) ||
         ((puVar1 == &DAT_00c0bfc8 || (puVar1[2] == -1)))) goto LAB_00703533;
      pcVar3 = (&PTR_DAT_00c0be1c)[puVar1[2]];
      goto LAB_00703541;
    }
  }
  else {
LAB_00703533:
    pcVar3 = "no value";
LAB_00703541:
    FUN_006f5580(param_1,"%s expected, got %s","function",pcVar3);
    FUN_006f5da0(1);
  }
  if (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x10U) {
    do {
      *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    } while (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x10U);
  }
  piVar2 = *(int **)(param_1 + 0xc);
  puVar5 = local_208;
  *(int **)(param_1 + 8) = piVar2 + 4;
  uVar6 = 0;
  iVar7 = param_1;
  if ((piVar2[2] == 6) && (*(char *)(*piVar2 + 6) == '\0')) {
    iVar4 = FUN_006f9050(param_1);
    if (iVar4 == 0) goto LAB_007035df;
  }
  FUN_006f5f30(param_1,"unable to dump given function");
LAB_007035df:
  FUN_006f6af0();
  FUN_006f5bb0();
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,extraout_EDX,puVar5,uVar6,iVar7);
  return;
}

