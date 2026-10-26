
void FUN_00471530(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int *piVar3;
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  int iStack_18;
  int iStack_10;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_20;
  FUN_00754430();
  if ((*(int **)(in_ECX + 0xcc) == (int *)0x0) ||
     (piVar3 = *(int **)(in_ECX + 0xd0), piVar3 == (int *)0x0)) goto LAB_00471612;
  iVar2 = *(int *)(in_ECX + 0xd4);
  if (iVar2 == 0) {
    (**(code **)(**(int **)(in_ECX + 0xcc) + 0x174))(auStack_1c);
    piVar3 = *(int **)(in_ECX + 0xd0);
    if (iStack_10 - iStack_18 <= *(int *)(in_ECX + 0xb0) - *(int *)(in_ECX + 0xa8)) {
LAB_00471608:
      (**(code **)(*piVar3 + 0xd4))();
      goto LAB_00471612;
    }
    (**(code **)(*piVar3 + 0xd0))();
    iVar1 = *(int *)(in_ECX + 0xd0);
    iVar2 = *(int *)(in_ECX + 0xa4);
    if (iVar2 <= *(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 8)) {
      *(int *)(in_ECX + 0xac) =
           *(int *)(in_ECX + 0xac) - (*(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 8));
      goto LAB_00471612;
    }
  }
  else {
    if (iVar2 != 1) {
      if (iVar2 != 2) goto LAB_00471612;
      goto LAB_00471608;
    }
    (**(code **)(*piVar3 + 0xd0))();
    iVar1 = *(int *)(in_ECX + 0xd0);
    iVar2 = *(int *)(in_ECX + 0xa4);
    if (iVar2 <= *(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 8)) {
      iVar2 = *(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 8);
    }
  }
  *(int *)(in_ECX + 0xac) = *(int *)(in_ECX + 0xac) - iVar2;
LAB_00471612:
  FUN_005f6700(in_ECX);
  if (*(int **)(in_ECX + 0xcc) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0xcc) + 0xbc))
              (*(undefined4 *)(in_ECX + 0xa4),*(undefined4 *)(in_ECX + 0xa8),
               *(undefined4 *)(in_ECX + 0xac),*(undefined4 *)(in_ECX + 0xb0));
    FUN_00749920(*(undefined4 *)(in_ECX + 0xcc));
  }
  __security_check_cookie(local_c ^ (uint)auStack_20);
  return;
}

