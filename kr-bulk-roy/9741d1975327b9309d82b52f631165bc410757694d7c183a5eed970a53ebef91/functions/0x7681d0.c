
void FUN_007681d0(void)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x24) != 0) &&
     ((((piVar1 = *(int **)(*(int *)(in_ECX + 0x24) + 0x165b4), piVar1 == (int *)0x0 ||
        (cVar3 = (**(code **)(*piVar1 + 0x1c))(), cVar3 != '\0')) &&
       (iVar2 = *(int *)(in_ECX + 0x24), *(int *)(in_ECX + 0x110) != *(int *)(in_ECX + 0x114))) &&
      (*(int *)(in_ECX + 0xf4) != 0)))) {
    if (*(int *)(iVar2 + 0xfc) == 1) {
      FUN_007686a0();
    }
    else if (*(int *)(iVar2 + 0xfc) == 3) {
      FUN_00768840();
    }
    if (((*(int *)(iVar2 + 0x3a0) == 1) || (*(int *)(iVar2 + 0x3a0) == 2)) ||
       ((*(int *)(iVar2 + 0x5a0) == 1 || (*(int *)(iVar2 + 0x5a0) == 2)))) {
      if (*(int *)(iVar2 + 0x3a4) == 1) {
        FUN_007674e0();
        return;
      }
      cVar3 = *(char *)(in_ECX + 0xca);
      if (cVar3 != '\0') {
        if (*(int *)(iVar2 + 0x3e4) == 1) {
          FUN_007675d0();
          return;
        }
        if (cVar3 != '\0') {
          if (*(int *)(iVar2 + 0x3e0) == 1) {
            FUN_007676f0();
            return;
          }
          if ((cVar3 != '\0') && (*(int *)(iVar2 + 1000) == 1)) {
            FUN_00767740();
            return;
          }
        }
      }
    }
  }
  return;
}

