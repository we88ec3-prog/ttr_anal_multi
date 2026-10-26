
undefined4 FUN_00705d10(int param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1 + 0xc);
  if (puVar3 < *(undefined4 **)(param_1 + 8)) {
    if ((puVar3 != &DAT_00c0bfc8) && (puVar3[2] == 5)) goto LAB_00705d6e;
    if ((*(undefined4 **)(param_1 + 8) <= puVar3) ||
       ((puVar3 == &DAT_00c0bfc8 || (puVar3[2] == -1)))) goto LAB_00705d42;
    pcVar2 = (&PTR_DAT_00c0be1c)[puVar3[2]];
  }
  else {
LAB_00705d42:
    pcVar2 = "no value";
  }
  FUN_006f5580(param_1,"%s expected, got %s","table",pcVar2);
  FUN_006f5da0(1);
LAB_00705d6e:
  puVar3 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
  if (((*(undefined4 **)(param_1 + 8) <= puVar3) || (puVar3 == &DAT_00c0bfc8)) ||
     (*(int *)(*(int *)(param_1 + 0xc) + 0x18) == -1)) {
    FUN_006f5da0(2);
  }
  if (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x20U) {
    do {
      *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    } while (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x20U);
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 0xc) + 0x20;
  puVar3 = (undefined4 *)FUN_006f9c50();
  iVar1 = *(int *)(param_1 + 8);
  *(undefined4 *)(iVar1 + -0x10) = *puVar3;
  *(undefined4 *)(iVar1 + -0xc) = puVar3[1];
  *(undefined4 *)(iVar1 + -8) = puVar3[2];
  return 1;
}

