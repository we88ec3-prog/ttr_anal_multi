
void FUN_00767320(void)

{
  char cVar1;
  int *in_EAX;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  cVar1 = FUN_00767c20();
  if (cVar1 == '\0') {
    uVar4 = in_EAX[0x4f];
    uVar2 = in_EAX[0x45] - in_EAX[0x44] >> 2;
    if (uVar2 <= uVar4) {
      return;
    }
    iVar3 = *(int *)(in_EAX[0x44] + uVar4 * 4);
    uVar5 = in_EAX[0x50];
    if (uVar5 < *(uint *)(iVar3 + 0x10)) {
      FUN_00671e60();
      if (*(uint *)(iVar3 + 0x10) < uVar5) {
        return;
      }
      if ((int)uVar5 < 0) {
        uVar5 = 0;
      }
      iVar3 = FUN_00776f20(iVar3,uVar5);
      if (iVar3 < 0) {
        return;
      }
      uVar4 = in_EAX[0x4f];
    }
    else {
      uVar4 = uVar4 + 1;
      if ((uVar2 <= uVar4) || (*(int *)(*(int *)(in_EAX[0x44] + uVar4 * 4) + 0x10) == 0))
      goto LAB_007673ab;
    }
    FUN_00765ef0(in_EAX,uVar4);
  }
LAB_007673ab:
  in_EAX[0x53] = in_EAX[0x4f];
  in_EAX[0x54] = in_EAX[0x4f];
  in_EAX[0x55] = in_EAX[0x50];
  in_EAX[0x56] = in_EAX[0x50];
  FUN_00767ec0();
  FUN_00767b30();
  FUN_00767fa0();
                    /* WARNING: Could not recover jumptable at 0x007673ef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_EAX + 0x1b0))();
  return;
}

