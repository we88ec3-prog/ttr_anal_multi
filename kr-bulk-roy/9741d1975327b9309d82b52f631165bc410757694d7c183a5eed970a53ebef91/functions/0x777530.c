
bool FUN_00777530(uint param_1,int param_2)

{
  uint uVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  int local_10;
  
  iVar2 = in_EAX - param_1;
  if ((iVar2 < 0) || (uVar1 = *(uint *)(param_2 + 0x10), uVar1 < param_1 + 1)) {
    return false;
  }
  if (iVar2 == 0) {
    iVar2 = FUN_00777410();
    if ((((iVar2 != 0) && (iVar2 != 1)) && (iVar2 != 9)) && (iVar2 != 3)) {
      return iVar2 == 4;
    }
    return true;
  }
  local_10 = 0;
  iVar4 = local_10;
  if (param_1 != 0) {
    iVar6 = 1;
    uVar7 = param_1;
    while (uVar7 = uVar7 - 1, iVar4 = local_10, -1 < (int)uVar7) {
      if (uVar1 <= param_1 - iVar6) goto LAB_007775f5;
      iVar3 = FUN_00777410();
      iVar4 = iVar6;
      if (((iVar3 == 1) || (iVar3 == 2)) ||
         ((iVar3 == 3 || ((iVar3 == 4 || (iVar6 = iVar6 + 1, iVar4 = local_10, 3 < iVar6))))))
      break;
    }
  }
  local_10 = iVar4;
  if (uVar1 <= param_1) {
LAB_007775f5:
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid string position");
  }
  iVar4 = FUN_00777410();
  if (uVar1 <= param_1 - local_10) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid string position");
  }
  iVar3 = FUN_00777410();
  iVar5 = 1;
  iVar6 = iVar4;
  uVar7 = param_1;
  if (1 < iVar2) {
    do {
      uVar7 = uVar7 + 1;
      if (uVar1 <= uVar7) goto LAB_007775f5;
      iVar4 = FUN_00777410();
      if (iVar4 == 0) {
        return false;
      }
      if ((uVar7 == 0) && (4 < iVar4)) {
        return false;
      }
      if ((iVar6 == 2) || (iVar6 == 5)) goto LAB_007776bc;
      if (iVar6 == 6) {
        if (iVar4 != 9) goto LAB_007776bc;
      }
      else {
        if (iVar6 == 7) {
LAB_007776bc:
          bVar10 = SBORROW4(iVar4,4);
          bVar9 = iVar4 + -4 < 0;
          bVar8 = iVar4 == 4;
        }
        else {
          if (iVar6 != 3) {
            if (iVar6 != 8) {
              if (iVar6 == 9) {
                bVar10 = SBORROW4(iVar4,5);
                bVar9 = iVar4 + -5 < 0;
                bVar8 = iVar4 == 5;
                goto LAB_007776bf;
              }
              if (iVar6 != 4) goto LAB_007776c5;
            }
            goto LAB_007776bc;
          }
          bVar10 = SBORROW4(iVar4,1);
          bVar9 = iVar4 + -1 < 0;
          bVar8 = iVar4 == 1;
        }
LAB_007776bf:
        if (!bVar8 && bVar10 == bVar9) {
          return false;
        }
      }
LAB_007776c5:
      iVar5 = iVar5 + 1;
      iVar6 = iVar4;
    } while (iVar5 < iVar2);
  }
  iVar6 = FUN_00777410();
  if (iVar6 == 0) {
    return false;
  }
  iVar2 = iVar2 + -1;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  if ((iVar2 + param_1 == 0) && (4 < iVar6)) {
    return false;
  }
  if ((iVar4 != 2) && (iVar4 != 5)) {
    if (iVar4 == 6) {
      if ((iVar6 != 9) && (4 < iVar6)) {
        return false;
      }
      goto LAB_00777762;
    }
    if (iVar4 == 7) {
      if (iVar3 != 7) goto LAB_00777762;
    }
    else {
      if (iVar4 == 3) {
        if (1 < iVar6) {
          return false;
        }
        goto LAB_00777762;
      }
      if (iVar4 != 8) {
        if (iVar4 == 9) {
          if (5 < iVar6) {
            return false;
          }
        }
        else if ((iVar4 == 4) && (4 < iVar6)) {
          return false;
        }
        goto LAB_00777762;
      }
    }
  }
  if (4 < iVar6) {
    return false;
  }
LAB_00777762:
  if ((1 < local_10) && (4 < iVar6)) {
    return false;
  }
  return true;
}

