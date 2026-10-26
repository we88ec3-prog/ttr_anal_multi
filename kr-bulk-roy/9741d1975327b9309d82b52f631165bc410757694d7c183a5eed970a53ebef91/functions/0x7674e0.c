
void FUN_007674e0(void)

{
  int *piVar1;
  int iVar2;
  int *in_EAX;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  iVar4 = in_EAX[0x44];
  iVar2 = in_EAX[0x45];
  if (iVar4 == iVar2) {
LAB_0076751c:
    uVar5 = iVar2 - iVar4 >> 2;
    iVar4 = 0;
  }
  else {
    iVar3 = iVar2 - iVar4 >> 2;
    puVar6 = *(undefined4 **)(iVar4 + -4 + iVar3 * 4);
    piVar1 = puVar6 + 4;
    if (*piVar1 != 0) {
      if (7 < (uint)puVar6[5]) {
        puVar6 = (undefined4 *)*puVar6;
      }
      if (*(short *)((int)puVar6 + *piVar1 * 2 + -2) == 10) goto LAB_0076751c;
    }
    iVar3 = iVar3 + -1;
    in_EAX[0x54] = iVar3;
    if (iVar3 < 0) {
      in_EAX[0x54] = 0;
    }
    uVar5 = (in_EAX[0x45] - in_EAX[0x44] >> 2) - 1;
    uVar5 = -(uint)(uVar5 != 0) & uVar5;
    iVar4 = *(int *)(*(int *)(in_EAX[0x44] + in_EAX[0x54] * 4) + 0x10);
  }
  in_EAX[0x53] = 0;
  in_EAX[0x55] = 0;
  if ((char)in_EAX[0x52] == '\0') {
    in_EAX[0x54] = 0;
    in_EAX[0x56] = 0;
  }
  else {
    in_EAX[0x54] = uVar5;
    in_EAX[0x56] = iVar4;
  }
  in_EAX[0x4f] = uVar5;
  in_EAX[0x50] = iVar4;
  FUN_00767ec0();
  FUN_00767b30();
  FUN_00767fa0();
                    /* WARNING: Could not recover jumptable at 0x007675c1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_EAX + 0x1b0))();
  return;
}

