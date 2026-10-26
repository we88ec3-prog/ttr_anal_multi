
void FUN_007682e0(void)

{
  char cVar1;
  int *in_EAX;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (in_EAX[9] != -0xa8) {
    FUN_0043c810((float)*(int *)(in_EAX[9] + 0xc4) / 120.0);
    iVar2 = FUN_008fed10();
    if (iVar2 < 1) {
      uVar4 = in_EAX[0x4d] + iVar2 & (in_EAX[0x4d] + iVar2 < 0) - 1;
    }
    else {
      cVar1 = FUN_00768190();
      if (in_EAX[0x57] == 1) {
        if (cVar1 == '\0') {
          iVar3 = (in_EAX[0x45] - in_EAX[0x44] >> 2) + -1;
        }
        else {
          iVar3 = in_EAX[0x45] - in_EAX[0x44] >> 2;
        }
        uVar4 = iVar3 - in_EAX[0x4e] & (iVar3 - in_EAX[0x4e] < 0) - 1;
      }
      else if (cVar1 == '\0') {
        uVar4 = (in_EAX[0x45] - in_EAX[0x44] >> 2) - 1;
      }
      else {
        uVar4 = in_EAX[0x45] - in_EAX[0x44] >> 2;
      }
      if (in_EAX[0x4d] + iVar2 <= (int)uVar4) {
        uVar4 = in_EAX[0x4d] + iVar2;
      }
    }
    in_EAX[0x4d] = uVar4;
    FUN_00767fa0();
    (**(code **)(*in_EAX + 0x1b0))();
  }
  return;
}

