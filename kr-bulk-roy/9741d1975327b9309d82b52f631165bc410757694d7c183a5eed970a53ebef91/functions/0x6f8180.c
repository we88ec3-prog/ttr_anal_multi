
undefined4 FUN_006f8180(char *param_1)

{
  int *piVar1;
  int in_EAX;
  undefined4 uVar2;
  char *pcVar3;
  int in_ECX;
  int iVar4;
  
  iVar4 = 0;
  if (*param_1 == '>') {
    iVar4 = *(int *)(*(int *)(in_ECX + 8) + -0x10);
    param_1 = param_1 + 1;
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + -0x10;
  }
  else if (*(int *)(in_EAX + 0x60) != 0) {
    iVar4 = **(int **)(*(int *)(in_ECX + 0x28) + *(int *)(in_EAX + 0x60) * 0x18 + 4);
  }
  uVar2 = FUN_006f8030();
  pcVar3 = _strchr(param_1,0x66);
  if (pcVar3 != (char *)0x0) {
    if (iVar4 == 0) {
      *(undefined4 *)(*(int *)(in_ECX + 8) + 8) = 0;
    }
    else {
      piVar1 = *(int **)(in_ECX + 8);
      *piVar1 = iVar4;
      piVar1[2] = 6;
    }
    if (*(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 8) < 0x11) {
      FUN_006fdcb0();
    }
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 0x10;
  }
  pcVar3 = _strchr(param_1,0x4c);
  if (pcVar3 != (char *)0x0) {
    FUN_006f7f40(iVar4);
  }
  return uVar2;
}

