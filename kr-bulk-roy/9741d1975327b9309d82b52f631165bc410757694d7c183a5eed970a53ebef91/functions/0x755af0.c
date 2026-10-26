
void FUN_00755af0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x3c) != 0) && ((*(uint *)(in_ECX + 0x28) & 0x40000) == 0)) {
    FUN_00746bd0();
  }
  if ((((*(int *)(in_ECX + 0x24) != 0) &&
       (piVar1 = *(int **)(*(int *)(in_ECX + 0x24) + 0x1c), piVar1 != (int *)0x0)) &&
      (iVar2 = *(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 8), 0 < iVar2)) &&
     ((*(int *)(in_ECX + 0x14) != *(int *)(in_ECX + 0xc) &&
       -1 < *(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0xc) &&
      ((*(uint *)(in_ECX + 0x28) >> 0xe & 1) != 0)))) {
    (**(code **)(*piVar1 + 0x5c))
              (piVar1,iVar2,*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0xc),1,1,0x15,0,
               (undefined4 *)(in_ECX + 0x84),0);
    piVar1 = *(int **)(in_ECX + 0x84);
    (**(code **)(*piVar1 + 0x48))(piVar1,0,in_ECX + 0x88);
  }
  return;
}

