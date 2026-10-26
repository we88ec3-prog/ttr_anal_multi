
undefined4 FUN_00705df0(int param_1)

{
  char *pcVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0xc);
  if (puVar2 < *(undefined4 **)(param_1 + 8)) {
    if ((puVar2 != &DAT_00c0bfc8) && (puVar2[2] == 5)) goto LAB_00705e4e;
    if ((*(undefined4 **)(param_1 + 8) <= puVar2) ||
       ((puVar2 == &DAT_00c0bfc8 || (puVar2[2] == -1)))) goto LAB_00705e22;
    pcVar1 = (&PTR_DAT_00c0be1c)[puVar2[2]];
  }
  else {
LAB_00705e22:
    pcVar1 = "no value";
  }
  FUN_006f5580(param_1,"%s expected, got %s","table",pcVar1);
  FUN_006f5da0(1);
LAB_00705e4e:
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
  if (((*(undefined4 **)(param_1 + 8) <= puVar2) || (puVar2 == &DAT_00c0bfc8)) ||
     (*(int *)(*(int *)(param_1 + 0xc) + 0x18) == -1)) {
    FUN_006f5da0(2);
  }
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x20);
  if (((*(undefined4 **)(param_1 + 8) <= puVar2) || (puVar2 == &DAT_00c0bfc8)) ||
     (*(int *)(*(int *)(param_1 + 0xc) + 0x28) == -1)) {
    FUN_006f5da0(3);
  }
  if (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x30U) {
    do {
      *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    } while (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x30U);
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 0xc) + 0x30;
  FUN_006f57f0(param_1);
  return 1;
}

