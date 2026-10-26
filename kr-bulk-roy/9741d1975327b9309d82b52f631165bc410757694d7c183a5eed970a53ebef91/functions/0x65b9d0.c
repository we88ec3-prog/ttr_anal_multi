
int FUN_0065b9d0(uint param_1,int param_2,int param_3)

{
  int *in_EAX;
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int local_14;
  
  param_3 = (param_2 - *in_EAX >> 2) * 0x20 + param_3;
  if (param_1 != 0) {
    if (-in_EAX[4] - 1U < param_1) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("vector<bool> too long");
    }
    FUN_0065baf0();
    uVar1 = in_EAX[4];
    if (uVar1 == 0) {
      in_EAX[4] = param_1;
      return param_3;
    }
    iVar6 = *in_EAX;
    uVar5 = 0;
    local_14 = iVar6;
    if (uVar1 != 0) {
      if (((int)uVar1 < 0) && (uVar1 != 0)) {
        local_14 = (-uVar1 - 1 >> 5) * -4 + -4;
      }
      else {
        local_14 = (uVar1 >> 5) * 4;
      }
      local_14 = iVar6 + local_14;
      uVar5 = uVar1 & 0x1f;
    }
    uVar1 = uVar1 + param_1;
    uVar3 = 0;
    in_EAX[4] = uVar1;
    if (uVar1 != 0) {
      if (((int)uVar1 < 0) && (uVar1 != 0)) {
        iVar4 = (-uVar1 - 1 >> 5) * -4 + -4;
      }
      else {
        iVar4 = (uVar1 >> 5) * 4;
      }
      iVar6 = iVar6 + iVar4;
      uVar3 = uVar1 & 0x1f;
    }
    puVar2 = (undefined4 *)FUN_0065b430(param_3);
    FUN_0065cbb0(param_1,*puVar2,puVar2[1],local_14,uVar5,iVar6,uVar3);
  }
  return param_3;
}

