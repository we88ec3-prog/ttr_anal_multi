
undefined4 FUN_00700a40(int param_1)

{
  undefined4 *puVar1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xc);
  puVar1 = (undefined4 *)(iVar3 + 0x10);
  if (puVar1 < *(undefined4 **)(param_1 + 8)) {
    if ((puVar1 != &DAT_00c0bfc8) && (*(int *)(iVar3 + 0x18) == 5)) goto LAB_00700aa2;
    if ((*(undefined4 **)(param_1 + 8) <= puVar1) ||
       ((puVar1 == &DAT_00c0bfc8 || (*(int *)(iVar3 + 0x18) == -1)))) goto LAB_00700a74;
    pcVar2 = (&PTR_DAT_00c0be1c)[*(int *)(iVar3 + 0x18)];
  }
  else {
LAB_00700a74:
    pcVar2 = "no value";
  }
  FUN_006f5580(param_1,"%s expected, got %s","table",pcVar2);
  FUN_006f5da0(2);
LAB_00700aa2:
  if (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x20U) {
    do {
      *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    } while (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x20U);
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 0xc) + 0x20;
  iVar3 = FUN_006f59b0();
  if (iVar3 == 0) {
    FUN_006f5f30(param_1,"\'setfenv\' cannot change environment of given object");
  }
  return 1;
}

