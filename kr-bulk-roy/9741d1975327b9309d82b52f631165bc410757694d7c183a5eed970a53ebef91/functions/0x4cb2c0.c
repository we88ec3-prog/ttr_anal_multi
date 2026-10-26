
void FUN_004cb2c0(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  code *pcVar4;
  int *piVar5;
  float10 fVar6;
  
  iVar3 = *(int *)(in_ECX + 4);
  uVar1 = *(uint *)(iVar3 + 0x38c);
  if ((*(int *)(iVar3 + 0x15c) == 0) || (*(int *)(iVar3 + 0x370) == 0)) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(*(int *)(iVar3 + 0x15c) + 0x11c);
  }
  iVar2 = FUN_004c9ed0();
  if (iVar2 != 0) {
    if (iVar3 == 0) {
      return;
    }
    (**(code **)(**(int **)(in_ECX + 4) + 0x68))(8,0x3f800000);
    return;
  }
  if (0xf4 < uVar1) {
    if (iVar3 == 0) {
      return;
    }
    iVar3 = FUN_004c8e80();
    if (iVar3 != 0) {
      return;
    }
    iVar3 = FUN_004c8de0();
    pcVar4 = *(code **)(**(int **)(in_ECX + 4) + 0x68);
    if (iVar3 != 0) {
      (*pcVar4)(2);
      fVar6 = (float10)FUN_004c9a20();
      FUN_004c8d00((float)fVar6);
      return;
    }
LAB_004cb37d:
    (*pcVar4)(1,0x3f800000);
    return;
  }
  if (uVar1 < 0x65) {
    if (uVar1 == 0xf) {
      (**(code **)(**(int **)(in_ECX + 4) + 0x68))(0x11,0x3f800000);
      return;
    }
    if ((uVar1 != 0x11) && (uVar1 != 0x10)) {
      if ((uVar1 == 1) || (uVar1 == 2)) {
        if ((uVar1 != 3) && ((*(int **)(in_ECX + 4))[0x34] < 100)) {
          (**(code **)(**(int **)(in_ECX + 4) + 0x68))(3,0x3f800000);
        }
LAB_004cb43d:
        if (*(int *)(*(int *)(in_ECX + 4) + 0xd0) != 100) {
          return;
        }
        if ((*(int *)(*(int *)(in_ECX + 4) + 0x418) == 0) && (iVar3 = FUN_004c8de0(), iVar3 != 0)) {
          if (uVar1 == 2) {
            return;
          }
          (**(code **)(**(int **)(in_ECX + 4) + 0x68))(2,0x3f800000);
          return;
        }
        if (uVar1 == 1) {
          return;
        }
        piVar5 = *(int **)(in_ECX + 4);
      }
      else {
        if (uVar1 == 3) goto LAB_004cb43d;
        piVar5 = *(int **)(in_ECX + 4);
        if (piVar5[0x106] == 0) {
          iVar3 = FUN_004c8de0();
          pcVar4 = *(code **)(**(int **)(in_ECX + 4) + 0x68);
          if (iVar3 != 0) {
            (*pcVar4)(2,0x3f800000);
            return;
          }
          goto LAB_004cb37d;
        }
      }
      iVar3 = *piVar5;
      goto LAB_004cb492;
    }
  }
  if (iVar3 == 0) {
    return;
  }
  iVar3 = **(int **)(in_ECX + 4);
LAB_004cb492:
  (**(code **)(iVar3 + 0x68))(1,0x3f800000);
  return;
}

