
bool FUN_0045a050(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined4 uVar3;
  
  if (*(char *)(in_ECX + 0x2a4) != '\0') {
    return false;
  }
  if ((param_1[1] != 0) && (*param_1 == 100)) {
    iVar1 = (**(code **)(*(int *)param_1[1] + 8))();
    if (iVar1 == 0xf4245) {
      iVar1 = *(int *)(param_1[1] + 0x2d0);
      iVar2 = FUN_00404ba0();
      if ((iVar1 == 1) && (*(int *)(iVar2 + 0x6920) != -0x16f8)) {
        iVar1 = FUN_00508da0();
        if (iVar1 != 0) {
          uVar3 = *(undefined4 *)(iVar1 + 0xc);
          FUN_00459c20(uVar3);
          iVar1 = FUN_00824e30(uVar3);
          return 0 < iVar1;
        }
      }
      return false;
    }
  }
  return false;
}

