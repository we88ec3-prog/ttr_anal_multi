
void FUN_0042b6b0(int param_1)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if (0x70b < uVar1) {
    if (uVar1 == 0xf439b) {
      FUN_0042c420(in_ECX);
    }
    else if (uVar1 == 0xf43a2) {
      FUN_0042c420(in_ECX);
      return;
    }
    return;
  }
  if (uVar1 == 0x70b) {
    (**(code **)(**(int **)(in_ECX + 0xfc) + 0x90))(1);
    (**(code **)(**(int **)(in_ECX + 0x100) + 0x90))(1);
    return;
  }
  if (uVar1 == 0x578) {
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(*(int *)(in_ECX + 0xf8) + 0x20) == iVar2) {
      FUN_0042c070();
      return;
    }
    if (*(int *)(*(int *)(in_ECX + 0xfc) + 0x20) == iVar2) {
      FUN_0042c310(in_ECX);
      return;
    }
    if (*(int *)(*(int *)(in_ECX + 0x100) + 0x20) != iVar2) {
      if (*(int *)(*(int *)(in_ECX + 0x110) + 0x20) == iVar2) {
        if (*(int *)(in_ECX + 0x11c) < 1) {
          return;
        }
        FUN_0042bfe0(in_ECX,*(int *)(in_ECX + 0x11c) + -1);
        return;
      }
      if (*(int *)(*(int *)(in_ECX + 0x114) + 0x20) != iVar2) {
        if (*(int *)(*(int *)(in_ECX + 0x104) + 0x20) != iVar2) {
          return;
        }
        FUN_0042c470(in_ECX);
        return;
      }
      iVar2 = *(int *)(in_ECX + 0x11c) + 1;
      if (*(int *)(in_ECX + 0x120) <= iVar2) {
        return;
      }
      FUN_0042bfe0(in_ECX,iVar2);
      return;
    }
  }
  else if (uVar1 != 0x70a) {
    return;
  }
  FUN_0042c0c0(in_ECX);
  return;
}

