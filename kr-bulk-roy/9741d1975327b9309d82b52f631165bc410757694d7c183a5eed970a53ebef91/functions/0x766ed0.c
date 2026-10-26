
void FUN_00766ed0(void)

{
  int *in_EAX;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  iVar1 = in_EAX[0x44];
  if ((iVar1 != in_EAX[0x45]) && ((uint)in_EAX[0x4f] < (uint)(in_EAX[0x45] - iVar1 >> 2))) {
    iVar1 = *(int *)(iVar1 + in_EAX[0x4f] * 4);
    uVar5 = in_EAX[0x50];
    FUN_00671e60();
    if (uVar5 <= *(uint *)(iVar1 + 0x10)) {
      if ((int)uVar5 < 0) {
        uVar5 = 0;
      }
      iVar1 = FUN_00776f20(iVar1,uVar5);
      if (-1 < iVar1) {
        puVar2 = *(undefined4 **)(in_EAX[0x44] + in_EAX[0x4f] * 4);
        iVar3 = puVar2[4];
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          puVar4 = puVar2;
          if (7 < (uint)puVar2[5]) {
            puVar4 = (undefined4 *)*puVar2;
          }
          if (*(short *)((int)puVar4 + iVar3 * 2 + -2) == 10) {
            iVar3 = iVar3 + -1;
          }
        }
        if (iVar3 < in_EAX[0x50] + iVar1) {
          uVar5 = in_EAX[0x4f] + 1;
          if ((uint)(in_EAX[0x45] - in_EAX[0x44] >> 2) <= uVar5) {
            if (7 < (uint)puVar2[5]) {
              puVar2 = (undefined4 *)*puVar2;
            }
            if (*(short *)((int)puVar2 + iVar3 * 2) != 10) goto LAB_00766f9e;
          }
          in_EAX[0x50] = 0;
          in_EAX[0x4f] = uVar5;
        }
        else {
          in_EAX[0x50] = in_EAX[0x50] + iVar1;
        }
LAB_00766f9e:
        FUN_00767ba0();
        FUN_00767ec0();
        FUN_00767b30();
        FUN_00767fa0();
                    /* WARNING: Could not recover jumptable at 0x00766fc5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*in_EAX + 0x1b0))();
        return;
      }
    }
  }
  return;
}

