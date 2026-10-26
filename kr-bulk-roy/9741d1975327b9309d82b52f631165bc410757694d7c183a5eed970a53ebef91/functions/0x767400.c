
void FUN_00767400(void)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  int *in_EAX;
  int iVar4;
  
  if (in_EAX[0x44] == in_EAX[0x45]) {
    return;
  }
  cVar3 = FUN_00767c20();
  if (cVar3 == '\0') {
    iVar1 = in_EAX[0x50];
    if (iVar1 < 1) {
      uVar2 = in_EAX[0x4f];
      if ((int)(uVar2 - 1) < 0) goto LAB_00767495;
      if ((uVar2 < (uint)(in_EAX[0x45] - in_EAX[0x44] >> 2)) &&
         (*(int *)(*(int *)(in_EAX[0x44] + uVar2 * 4) + 0x10) == 0)) {
        FUN_00765d70();
      }
      iVar1 = *(int *)(*(int *)(in_EAX[0x44] + -4 + in_EAX[0x4f] * 4) + 0x10);
      iVar4 = in_EAX[0x4f] + -1;
      in_EAX[0x4f] = iVar4;
    }
    else {
      iVar4 = in_EAX[0x4f];
    }
    in_EAX[0x50] = iVar1 + -1;
    FUN_00765ef0(in_EAX,iVar4);
  }
LAB_00767495:
  in_EAX[0x53] = in_EAX[0x4f];
  in_EAX[0x54] = in_EAX[0x4f];
  in_EAX[0x55] = in_EAX[0x50];
  in_EAX[0x56] = in_EAX[0x50];
  FUN_00767ec0();
  FUN_00767b30();
  FUN_00767fa0();
                    /* WARNING: Could not recover jumptable at 0x007674d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_EAX + 0x1b0))();
  return;
}

