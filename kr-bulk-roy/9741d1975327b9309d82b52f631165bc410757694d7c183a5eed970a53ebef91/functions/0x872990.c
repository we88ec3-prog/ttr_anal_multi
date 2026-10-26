
undefined4 FUN_00872990(uint param_1)

{
  int *piVar1;
  int in_ECX;
  int iVar2;
  
  piVar1 = (int *)(in_ECX + 0x184);
  if (param_1 < (uint)(*(int *)(in_ECX + 0x188) - *piVar1 >> 2)) {
    iVar2 = *piVar1;
    if (0 < (int)param_1) {
      iVar2 = iVar2 + param_1 * 4;
    }
    FUN_00872f20(piVar1,&param_1,iVar2);
    return 1;
  }
  return 0;
}

