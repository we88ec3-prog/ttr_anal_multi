
void FUN_00766e10(void)

{
  uint uVar1;
  int *in_EAX;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if (in_EAX[0x44] == in_EAX[0x45]) {
    return;
  }
  uVar1 = in_EAX[0x50];
  if ((int)uVar1 < 1) {
    iVar2 = in_EAX[0x4f] + -1;
    if (-1 < iVar2) {
      puVar3 = *(undefined4 **)(in_EAX[0x44] + -4 + in_EAX[0x4f] * 4);
      iVar4 = puVar3[4];
      if (iVar4 == 0) {
        iVar4 = 0;
      }
      else {
        if (7 < (uint)puVar3[5]) {
          puVar3 = (undefined4 *)*puVar3;
        }
        if (*(short *)((int)puVar3 + iVar4 * 2 + -2) == 10) {
          iVar4 = iVar4 + -1;
        }
      }
      in_EAX[0x4f] = iVar2;
      in_EAX[0x50] = iVar4;
    }
  }
  else {
    iVar2 = *(int *)(in_EAX[0x44] + in_EAX[0x4f] * 4);
    FUN_00671e60();
    if (*(uint *)(iVar2 + 0x10) < uVar1) {
      return;
    }
    iVar2 = FUN_00777030();
    if (iVar2 < 0) {
      return;
    }
    in_EAX[0x50] = in_EAX[0x50] - iVar2;
  }
  FUN_00767ba0();
  FUN_00767ec0();
  FUN_00767b30();
  FUN_00767fa0();
                    /* WARNING: Could not recover jumptable at 0x00766ec7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_EAX + 0x1b0))();
  return;
}

