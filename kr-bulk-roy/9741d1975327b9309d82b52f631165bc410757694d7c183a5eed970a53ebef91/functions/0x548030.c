
undefined4 FUN_00548030(void)

{
  undefined4 uVar1;
  int *in_ECX;
  int iVar2;
  int *piVar3;
  
  if (in_ECX[1] == 0) {
    return 0;
  }
  uVar1 = FUN_00545ba0();
  if (in_ECX[3] != 0) {
    (**(code **)(**(int **)in_ECX[0x2e] + 8))();
  }
  piVar3 = in_ECX + 0x2f;
  iVar2 = 3;
  do {
    in_ECX = in_ECX + 3;
    if ((*in_ECX != 0) && (*piVar3 != 0)) {
      (**(code **)(*(int *)(*piVar3 + 0x38) + 8))();
    }
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return uVar1;
}

