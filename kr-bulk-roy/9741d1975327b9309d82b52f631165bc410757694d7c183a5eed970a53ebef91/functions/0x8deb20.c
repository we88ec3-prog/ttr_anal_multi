
int FUN_008deb20(undefined4 param_1,int param_2,int param_3,char param_4)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int *unaff_EBX;
  uint local_4c;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  uVar3 = *(uint *)(param_2 + 0x1c);
  local_14 = uVar3;
  _memset(unaff_EBX,0,0xba4);
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  *unaff_EBX = param_2;
  unaff_EBX[1] = uVar3;
  local_c = FUN_008b9850(param_2);
  local_8 = FUN_008bacd0(param_2,&DAT_00bea100);
  if (local_8 != 0) goto LAB_008def06;
  if ((((char)unaff_EBX[4] != '\x01') || (*(byte *)((int)unaff_EBX + 0x12) < 4)) ||
     (4 < *(byte *)((int)unaff_EBX + 0x13))) {
    local_8 = 2;
    goto LAB_008def06;
  }
  local_8 = FUN_008b9820(param_2,*(byte *)((int)unaff_EBX + 0x12) - 4);
  if ((((local_8 != 0) || (local_8 = FUN_008dd9f0(0), local_8 != 0)) ||
      ((local_8 = FUN_008dd9f0(0), local_8 != 0 ||
       ((local_8 = FUN_008dd9f0(1), local_8 != 0 || (local_8 = FUN_008dd9f0(1), local_8 != 0))))))
     || (local_8 = FUN_008ddce0(&local_34,unaff_EBX + 0x149,unaff_EBX + 0x14a), local_8 != 0))
  goto LAB_008def06;
  unaff_EBX[0x148] = local_2c;
  if (param_4 == '\0') {
    local_10 = 0;
    if (1 < (uint)unaff_EBX[7]) goto LAB_008dec85;
  }
  else {
    local_10 = param_3;
    if (unaff_EBX[7] <= param_3) {
      local_8 = 6;
      FUN_008ddb10();
      return local_8;
    }
    unaff_EBX[2] = unaff_EBX[7];
  }
  if ((((param_3 < 0) || (local_8 = FUN_008de8d0(local_10,param_2,local_c,param_1), local_8 != 0))
      || (local_8 = FUN_008b97e0(param_2,unaff_EBX[0x167] + local_c), local_8 != 0)) ||
     (local_8 = FUN_008dd9f0(0), local_8 != 0)) goto LAB_008def06;
  if (unaff_EBX[0x16c] == 0xffff) {
    unaff_EBX[0x1da] = 0;
    local_8 = 0;
  }
  else {
    local_8 = FUN_008b97e0(param_2,unaff_EBX[0x174] + local_c);
    if ((local_8 != 0) || (local_8 = FUN_008dd9f0(0), local_8 != 0)) goto LAB_008def06;
    if (local_4c < 0x101) {
      unaff_EBX[0x1da] = local_4c;
      iVar1 = FUN_008bc7d0(local_14,0x23c,0,local_4c,0,&local_8);
      if (local_8 == 0) {
        if (local_4c != 0) {
          piVar2 = unaff_EBX + 0x1db;
          uVar3 = local_4c;
          do {
            *piVar2 = iVar1;
            piVar2 = piVar2 + 1;
            iVar1 = iVar1 + 0x23c;
            uVar3 = uVar3 - 1;
          } while (uVar3 != 0);
        }
        uVar3 = 0;
        iVar1 = local_8;
        if (local_4c != 0) {
          do {
            local_8 = iVar1;
            local_8 = FUN_008de8d0(uVar3,param_2,local_c,param_1);
            if (local_8 != 0) goto LAB_008dee0e;
            uVar3 = uVar3 + 1;
            local_8 = 0;
            iVar1 = 0;
          } while (uVar3 < local_4c);
        }
        local_8 = FUN_008de0a0(unaff_EBX[0x128]);
      }
    }
LAB_008dee0e:
    FUN_008ddb10();
    if (local_8 != 0) goto LAB_008def06;
  }
  if (unaff_EBX[0x167] == 0) {
LAB_008dec85:
    local_8 = 3;
    FUN_008ddb10();
    return local_8;
  }
  unaff_EBX[3] = unaff_EBX[0x128];
  local_8 = FUN_008ddce0(unaff_EBX + 0x15,unaff_EBX + 0x147,0);
  if (local_8 != 0) goto LAB_008def06;
  iVar1 = 0;
  if (unaff_EBX[3] == 0) goto LAB_008deeda;
  if (unaff_EBX[0x16c] == 0xffff) {
LAB_008dee7e:
    local_14 = local_14 & 0xffffff00;
  }
  else {
    local_14 = CONCAT31(local_14._1_3_,1);
    if (param_4 == '\0') goto LAB_008dee7e;
  }
  local_8 = FUN_008de2b0(param_2,local_14);
  if ((local_8 == 0) &&
     ((iVar1 = 0, unaff_EBX[0x16c] != 0xffff ||
      (local_8 = FUN_008de590(unaff_EBX + 0x1d,unaff_EBX + 0x120,unaff_EBX[3],param_2,local_c),
      iVar1 = local_8, local_8 == 0)))) {
LAB_008deeda:
    local_8 = iVar1;
    iVar1 = FUN_008ddf90(local_10);
    unaff_EBX[0x146] = iVar1;
    FUN_008ddb10();
    return local_8;
  }
LAB_008def06:
  FUN_008ddb10();
  return local_8;
}

