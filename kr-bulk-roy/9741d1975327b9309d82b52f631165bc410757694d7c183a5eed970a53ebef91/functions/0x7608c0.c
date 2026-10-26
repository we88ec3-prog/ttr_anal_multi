
void FUN_007608c0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  undefined4 uVar4;
  
  FUN_00754430();
  piVar1 = *(int **)(in_ECX + 0xd8);
  if ((piVar1 != (int *)0x0) && (*(int *)(in_ECX + 0xdc) != 0)) {
    iVar2 = *(int *)(in_ECX + 0xd4);
    if (iVar2 == 0) {
      if (piVar1[0x30] < 1) {
LAB_00760987:
        (**(code **)(*piVar1 + 0xd4))();
      }
      else {
        (**(code **)(*piVar1 + 0xd0))();
LAB_0076090e:
        iVar2 = *(int *)(in_ECX + 0xd8);
        if (*(int *)(in_ECX + 200) == 0) {
          iVar3 = *(int *)(in_ECX + 0xb0);
          if ((*(int *)(iVar2 + 0x14) - *(int *)(iVar2 + 0xc)) + *(int *)(in_ECX + 0xa8) <= iVar3) {
            iVar3 = (*(int *)(iVar2 + 0x14) - *(int *)(iVar2 + 0xc)) + *(int *)(in_ECX + 0xa8);
          }
          *(int *)(in_ECX + 0xa8) = iVar3;
        }
        else {
          iVar3 = *(int *)(in_ECX + 0xb0);
          if (iVar3 < (*(int *)(iVar2 + 0xc) - *(int *)(iVar2 + 0x14)) + iVar3) {
            *(int *)(in_ECX + 0xb0) = iVar3;
          }
          else {
            *(int *)(in_ECX + 0xb0) = (*(int *)(iVar2 + 0xc) - *(int *)(iVar2 + 0x14)) + iVar3;
          }
        }
      }
    }
    else {
      if (iVar2 == 1) {
        (**(code **)(*piVar1 + 0xd0))();
        goto LAB_0076090e;
      }
      if (iVar2 == 2) goto LAB_00760987;
    }
  }
  piVar1 = *(int **)(in_ECX + 0xd8);
  if (piVar1 != (int *)0x0) {
    if (*(int *)(in_ECX + 200) == 0) {
      (**(code **)(*piVar1 + 0xbc))
                (0,0,*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 8),piVar1[5] - piVar1[3]);
      uVar4 = *(undefined4 *)(in_ECX + 0xd8);
    }
    else {
      if (*(int *)(in_ECX + 200) != 1) goto LAB_00760a2f;
      (**(code **)(*piVar1 + 0xbc))
                (0,*(undefined4 *)(in_ECX + 0xb0),*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 8),
                 (piVar1[5] - piVar1[3]) + *(int *)(in_ECX + 0xb0));
      uVar4 = *(undefined4 *)(in_ECX + 0xd8);
    }
    FUN_00749920(uVar4);
  }
LAB_00760a2f:
  if (*(int **)(in_ECX + 0xdc) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0xdc) + 0xbc))
              (*(undefined4 *)(in_ECX + 0xa4),*(undefined4 *)(in_ECX + 0xa8),
               *(undefined4 *)(in_ECX + 0xac),*(undefined4 *)(in_ECX + 0xb0));
  }
  return;
}

