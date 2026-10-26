
void FUN_0076d030(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  FUN_00754430();
  if (*(int **)(in_ECX + 0xd4) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0xd4) + 0xbc))
              (*(undefined4 *)(in_ECX + 0xa4),*(undefined4 *)(in_ECX + 0xa8),
               *(undefined4 *)(in_ECX + 0xac),*(undefined4 *)(in_ECX + 0xb0));
    FUN_0076cc50();
  }
  piVar1 = *(int **)(in_ECX + 0xd0);
  if ((piVar1 == (int *)0x0) || (iVar3 = *(int *)(in_ECX + 0xd4), iVar3 == 0)) goto LAB_0076d132;
  iVar2 = *(int *)(in_ECX + 0xcc);
  if (iVar2 == 0) {
    iVar2 = *piVar1;
    if (*(int *)(iVar3 + 0xb8) - *(int *)(iVar3 + 0xb0) <=
        *(int *)(in_ECX + 0xb0) - *(int *)(in_ECX + 0xa8)) {
LAB_0076d12a:
      (**(code **)(iVar2 + 0xd4))();
      goto LAB_0076d132;
    }
    (**(code **)(iVar2 + 0xd0))();
    iVar2 = *(int *)(in_ECX + 0xd0);
    iVar3 = *(int *)(in_ECX + 0xa4);
    if (iVar3 <= *(int *)(iVar2 + 0x10) - *(int *)(iVar2 + 8)) {
      *(int *)(in_ECX + 0xac) =
           *(int *)(in_ECX + 0xac) - (*(int *)(iVar2 + 0x10) - *(int *)(iVar2 + 8));
      goto LAB_0076d132;
    }
  }
  else {
    if (iVar2 != 1) {
      if (iVar2 != 2) goto LAB_0076d132;
      iVar2 = *piVar1;
      goto LAB_0076d12a;
    }
    (**(code **)(*piVar1 + 0xd0))();
    iVar2 = *(int *)(in_ECX + 0xd0);
    iVar3 = *(int *)(in_ECX + 0xa4);
    if (iVar3 <= *(int *)(iVar2 + 0x10) - *(int *)(iVar2 + 8)) {
      iVar3 = *(int *)(iVar2 + 0x10) - *(int *)(iVar2 + 8);
    }
  }
  *(int *)(in_ECX + 0xac) = *(int *)(in_ECX + 0xac) - iVar3;
LAB_0076d132:
  FUN_0076d1b0();
  if (*(int **)(in_ECX + 0xd4) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0xd4) + 0xbc))
              (*(undefined4 *)(in_ECX + 0xa4),*(undefined4 *)(in_ECX + 0xa8),
               *(undefined4 *)(in_ECX + 0xac),*(undefined4 *)(in_ECX + 0xb0));
  }
  return;
}

