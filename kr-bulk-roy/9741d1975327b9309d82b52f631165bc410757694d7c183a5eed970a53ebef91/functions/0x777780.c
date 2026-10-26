
undefined4 FUN_00777780(uint param_1,undefined2 *param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int local_10;
  
  uVar6 = *param_3;
  uVar5 = uVar6 - 1;
  if ((int)uVar5 < 0) {
    return 0;
  }
  uVar1 = *(uint *)(param_1 + 0x10);
  if (uVar1 <= uVar6 - 1) {
LAB_007777ae:
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid string position");
  }
  iVar2 = FUN_00777410();
  iVar3 = FUN_00777410();
  if ((iVar2 != iVar3) && ((1 < iVar2 - 6U || (1 < iVar3 - 6U)))) {
    if (iVar2 - 8U < 2) {
      if (iVar3 - 5U < 3) {
        iVar2 = 1;
        while( true ) {
          if ((int)(*param_3 - iVar2) < 0) {
            return 0;
          }
          FUN_007779f0();
          iVar3 = FUN_00777410();
          if ((5 < iVar3) && (iVar3 < 8)) break;
          iVar2 = iVar2 + 1;
          if (3 < iVar2) {
            return 0;
          }
        }
        iVar3 = FUN_00777410();
        param_1 = (uint)(iVar3 == 5);
        FUN_00402400(*param_3 - iVar2,1);
        FUN_004f0b60((*param_3 - iVar2) + param_1,1,*param_2);
        return 0;
      }
      if (iVar3 - 8U < 2) goto LAB_00777899;
    }
    if ((iVar2 == 5) && (iVar3 - 6U < 4)) {
      iVar2 = 1;
      local_10 = 0;
      uVar6 = uVar5;
      do {
        if ((int)uVar6 < 0) {
          return 0;
        }
        if (uVar1 <= uVar6) goto LAB_007777ae;
        iVar3 = FUN_00777410();
        if (iVar3 == 1) {
          local_10 = iVar2 + -1;
          if (local_10 < 0) {
            return 0;
          }
          break;
        }
        iVar2 = iVar2 + 1;
        uVar6 = uVar6 - 1;
      } while (iVar2 < 4);
      iVar2 = 1;
      while (-1 < (int)uVar5) {
        if (uVar1 <= uVar5) goto LAB_007777ae;
        iVar3 = FUN_00777410();
        if (iVar3 == 5) {
          uVar5 = *param_3;
          iVar3 = 0;
          if (uVar5 - iVar2 < uVar1) {
            iVar4 = FUN_00777410();
            if ((iVar4 == 5) && (1 < local_10)) {
              iVar3 = 1;
            }
            FUN_00402400(uVar5 - iVar2,1);
            FUN_004f0b60((*param_3 - iVar3) - iVar2,1,*param_2);
            return 0;
          }
                    /* WARNING: Subroutine does not return */
          FUN_0087db7d("invalid string position");
        }
        iVar2 = iVar2 + 1;
        uVar5 = uVar5 - 1;
        if (3 < iVar2) {
          return 0;
        }
      }
    }
    return 0;
  }
LAB_00777899:
  *param_3 = uVar5;
  if (-1 < (int)uVar5) {
    FUN_00402400(uVar5,1);
    return 1;
  }
  *param_3 = uVar6;
  return 1;
}

