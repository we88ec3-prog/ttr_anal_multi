
void FUN_0078d840(int param_1,undefined4 param_2)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = param_1 - in_EAX >> 4;
  iVar4 = iVar5 - (param_1 - in_EAX >> 0x1f) >> 1;
  if (0 < iVar4) {
    iVar2 = iVar4 * 2 + 2;
    do {
      iVar4 = iVar4 + -1;
      iVar2 = iVar2 + -2;
      iVar1 = iVar4;
      for (iVar3 = iVar2; iVar3 < iVar5; iVar3 = iVar3 * 2 + 2) {
        if (*(int *)(in_EAX + 8 + iVar3 * 0x10) < *(int *)(in_EAX + -8 + iVar3 * 0x10)) {
          iVar3 = iVar3 + -1;
        }
        *(undefined4 *)(in_EAX + 4 + iVar1 * 0x10) = *(undefined4 *)(in_EAX + 4 + iVar3 * 0x10);
        *(undefined4 *)(in_EAX + 8 + iVar1 * 0x10) = *(undefined4 *)(in_EAX + 8 + iVar3 * 0x10);
        *(undefined4 *)(in_EAX + 0xc + iVar1 * 0x10) = *(undefined4 *)(in_EAX + 0xc + iVar3 * 0x10);
        iVar1 = iVar3;
      }
      if (iVar3 == iVar5) {
        iVar3 = in_EAX + -0x10 + iVar5 * 0x10;
        *(undefined4 *)(in_EAX + 4 + iVar1 * 0x10) = *(undefined4 *)(in_EAX + -0xc + iVar5 * 0x10);
        *(undefined4 *)(in_EAX + 8 + iVar1 * 0x10) = *(undefined4 *)(iVar3 + 8);
        *(undefined4 *)(in_EAX + 0xc + iVar1 * 0x10) = *(undefined4 *)(iVar3 + 0xc);
      }
      FUN_007900a0(iVar4,param_2);
    } while (0 < iVar4);
  }
  return;
}

