
void FUN_00682180(int param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  if ((*(char *)(in_ECX + 200) != '\0') && (*(int **)(in_ECX + 0x44) != (int *)0x0)) {
    (**(code **)(**(int **)(in_ECX + 0x44) + 0x15c))(param_1);
  }
  iVar2 = *(int *)(param_1 + 0x10);
  if (iVar2 == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x118) + 0x20)) {
      piVar1 = (int *)(in_ECX + 0x120);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 < 0) {
        *(undefined4 *)(in_ECX + 0x120) = 0;
      }
      FUN_00682290();
      return;
    }
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x11c) + 0x20)) {
      FUN_00682250();
      return;
    }
  }
  else {
    if (iVar2 == 0xf43ab) {
      FUN_006823c0(in_ECX,param_1);
      return;
    }
    if (iVar2 == 0xf43ac) {
      if (*(int *)(param_1 + 0x14) == 0x6a7) {
        FUN_00682a00();
        return;
      }
    }
    else if ((iVar2 == 0xf43a4) && (*(int *)(param_1 + 0x14) == 0xf43a5)) {
      FUN_00682640(*(undefined4 *)(*(int *)(param_1 + 0x1c) + 4),*(undefined4 *)(param_1 + 0x18));
    }
  }
  return;
}

