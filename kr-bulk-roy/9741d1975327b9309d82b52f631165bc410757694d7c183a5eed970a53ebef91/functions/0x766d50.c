
void FUN_00766d50(void)

{
  int *in_EAX;
  undefined4 *puVar1;
  int iVar2;
  
  if ((uint)in_EAX[0x4f] < (uint)(in_EAX[0x45] - in_EAX[0x44] >> 2)) {
    puVar1 = *(undefined4 **)(in_EAX[0x44] + in_EAX[0x4f] * 4);
    iVar2 = puVar1[4];
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      if (7 < (uint)puVar1[5]) {
        puVar1 = (undefined4 *)*puVar1;
      }
      if (*(short *)((int)puVar1 + iVar2 * 2 + -2) == 10) {
        iVar2 = iVar2 + -1;
      }
    }
    in_EAX[0x50] = iVar2;
    FUN_00767ba0();
    FUN_00767ec0();
    FUN_00767b30();
    FUN_00767fa0();
                    /* WARNING: Could not recover jumptable at 0x00766dbe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*in_EAX + 0x1b0))();
    return;
  }
  return;
}

