
uint FUN_00777240(undefined4 *param_1)

{
  uint uVar1;
  short sVar2;
  uint uVar3;
  uint in_EAX;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar3 = param_1[4];
  if (uVar3 < in_EAX) {
    return 0xfffffffe;
  }
  if (in_EAX == 0) {
    return 0xffffffff;
  }
  uVar1 = in_EAX - 1;
  if (uVar1 <= uVar3) {
    if (uVar3 == uVar1) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db7d("invalid string position");
    }
    if (7 < (uint)param_1[5]) {
      param_1 = (undefined4 *)*param_1;
    }
    sVar2 = *(short *)((int)param_1 + uVar1 * 2);
    if ((((0x5a < (ushort)(sVar2 - 0xe01U)) || (iVar4 = FUN_00777130(), iVar4 != 0)) ||
        (iVar4 = FUN_00777150(), iVar4 != 0)) ||
       (((ushort)(sVar2 - 0xe50U) < 10 || (iVar4 = FUN_00777180(), iVar4 != 0)))) {
      return uVar1;
    }
    iVar4 = in_EAX - 2;
    if (-1 < iVar4) {
      iVar6 = 0;
      do {
        iVar6 = iVar6 + 1;
        FUN_007779f0();
        iVar5 = FUN_00777130();
        if (((iVar5 != 0) || (iVar5 = FUN_00777150(), iVar5 != 0)) ||
           (iVar5 = FUN_00777180(), iVar5 != 0)) {
          return uVar1 - iVar6;
        }
        iVar4 = iVar4 + -1;
      } while (-1 < iVar4);
    }
    in_EAX = 0xffffffff;
  }
  return in_EAX;
}

