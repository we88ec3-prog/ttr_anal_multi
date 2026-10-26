
void FUN_0047c5d0(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0x578) {
    iVar1 = *(int *)(param_1 + 8);
    if (*(int *)(in_ECX[0x42] + 0x20) == iVar1) {
      (**(code **)(*in_ECX + 0xd4))();
      return;
    }
    if (*(int *)(in_ECX[0x41] + 0x20) == iVar1) {
      if (*(int *)(in_ECX[0x3f] + 0xcc) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(*(int *)(in_ECX[0x3f] + 0xcc) + 0xdc);
      }
      if (iVar1 != 0) {
        FUN_0047d810(in_ECX,iVar1);
        return;
      }
    }
    else if (*(int *)(in_ECX[0x40] + 0x20) == iVar1) {
      FUN_0047d490();
    }
  }
  else if (iVar1 == 0x70a) {
    if (4999 < *(uint *)(param_1 + 8)) {
      if (*(int *)(in_ECX[0x3f] + 0xcc) != 0) {
        FUN_0047d810(in_ECX,*(undefined4 *)(*(int *)(in_ECX[0x3f] + 0xcc) + 0xdc));
        return;
      }
      FUN_0047d810(in_ECX,0);
      return;
    }
  }
  else if ((iVar1 == 0x70b) && (*(uint *)(param_1 + 8) < 4000)) {
    if (*(int *)(in_ECX[0x3e] + 0xcc) != 0) {
      FUN_0047cb00(in_ECX,*(undefined4 *)(*(int *)(*(int *)(in_ECX[0x3e] + 0xcc) + 0xdc) + 0x248));
      return;
    }
    FUN_0047cb00(in_ECX,uRam00000248);
    return;
  }
  return;
}

