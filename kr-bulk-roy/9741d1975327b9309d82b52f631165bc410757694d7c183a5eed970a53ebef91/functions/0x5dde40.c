
undefined4 FUN_005dde40(int *param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  
  if ((*(char *)((int)in_ECX + 0x2a1) == '\0') && ((char)in_ECX[0xb3] == '\0')) {
    piVar1 = (int *)param_1[1];
    if (piVar1 != in_ECX) {
      if ((piVar1 != (int *)0x0) && (*param_1 == 100)) {
        iVar3 = (**(code **)(*piVar1 + 8))();
        if (iVar3 == 0xf4245) {
          iVar3 = FUN_005de120();
          iVar4 = FUN_00891268(0x20);
          if (iVar4 != 0) {
            FUN_00753e30(0xf436d,*(int *)(iVar3 + 0x20) + 1,in_ECX[8] + 1);
            FUN_00748900();
            return 1;
          }
          FUN_00748900();
          return 1;
        }
      }
      cVar2 = FUN_00755c10(0xf4246);
      if (cVar2 == '\0') {
        cVar2 = FUN_00755c10(0xf424b);
        if (cVar2 != '\0') {
          iVar3 = FUN_005de120();
          if (iVar3 != 0) {
            FUN_005d8750();
            return 1;
          }
        }
      }
      else {
        iVar3 = FUN_005de120();
        if (iVar3 != 0) {
          FUN_005ddb70(in_ECX[0xb4],in_ECX[8] + 1);
          return 1;
        }
      }
    }
    return 0;
  }
  return 0;
}

