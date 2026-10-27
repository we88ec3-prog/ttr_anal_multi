
undefined4 FUN_004c8360(void)

{
  int in_ECX;
  int iVar1;
  int *piVar2;
  
  if (*(int *)(in_ECX + 0x15c) != 0) {
    (**(code **)(*(int *)(*(int *)(in_ECX + 0x15c) + 8) + 8))();
  }
  if ((*(int *)(in_ECX + 0x364) != 0) && (*(int *)(*(int *)(in_ECX + 0x364) + 0x24) != 0)) {
    FUN_007be5f0();
  }
  piVar2 = (int *)(in_ECX + 0x164);
  iVar1 = 0x80;
  do {
    if ((*piVar2 != 0) && (*(int *)(*piVar2 + 0x24) != 0)) {
      FUN_007be5f0();
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return 0;
}

