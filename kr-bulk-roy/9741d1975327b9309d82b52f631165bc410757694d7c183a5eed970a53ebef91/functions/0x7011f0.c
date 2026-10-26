
int FUN_007011f0(int param_1)

{
  undefined4 *puVar1;
  int in_EAX;
  int *piVar2;
  int iVar3;
  
  FUN_006f6370();
  puVar1 = *(undefined4 **)(in_EAX + 0xc);
  if (((*(undefined4 **)(in_EAX + 8) <= puVar1) || (puVar1 == &DAT_00c0bfc8)) || (puVar1[2] != 6)) {
    FUN_006f5580();
    FUN_006f5da0(1);
  }
  piVar2 = *(int **)(in_EAX + 0xc);
  if (*(int **)(in_EAX + 8) <= piVar2) {
    piVar2 = &DAT_00c0bfc8;
  }
  if ((piVar2[2] != 6) || (*(char *)(*piVar2 + 6) == '\0')) {
    if (param_1 == 0) {
      iVar3 = FUN_006f5cf0();
    }
    else {
      iVar3 = FUN_006f5c70();
    }
    if (iVar3 != 0) {
      FUN_006f5510(iVar3);
      FUN_006f52b0();
      return param_1 + 1;
    }
  }
  return 0;
}

