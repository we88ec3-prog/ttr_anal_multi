
void FUN_007d91f0(void)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  undefined1 auStack_54 [4];
  int local_50;
  int local_4c;
  int local_48;
  uint local_44;
  int local_40;
  int *local_3c;
  uint local_38 [4];
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0091c941;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_54;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffa0;
  ExceptionList = &local_14;
  if (*(int *)(in_ECX + 0x108) != 1) {
    local_50 = 0;
    if (0 < *(int *)(in_ECX + 0xbc)) {
      local_4c = 0;
      do {
        local_40 = *(int *)(local_4c + *(int *)(in_ECX + 0xc0));
        local_24 = 0xf;
        local_28 = 0;
        local_38[0] = local_38[0] & 0xffffff00;
        FUN_00403040(in_ECX + 0xd0,0,0xffffffff);
        local_c = 0;
        if ((*(int *)(in_ECX + 8) != *(int *)(in_ECX + 0xc)) &&
           (local_44 = 0, *(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8) >> 5 != 0)) {
          local_48 = 0;
          do {
            iVar1 = local_48;
            piVar3 = (int *)(*(int *)(in_ECX + 8) + local_48);
            if (local_40 == *piVar3) {
              FUN_00401ed0(piVar3 + 1,0,0xffffffff);
              iVar1 = *(int *)(*(int *)(in_ECX + 8) + iVar1 + 0x14);
              iVar4 = FUN_00407e70(0,uVar2);
              if (iVar4 != 0 || iVar1 != 0) {
                piVar3 = (int *)FUN_00891268(0x2c);
                local_c._0_1_ = 1;
                local_3c = piVar3;
                if (piVar3 == (int *)0x0) {
                  piVar3 = (int *)0x0;
                }
                else {
                  *piVar3 = (uint)*(ushort *)(in_ECX + 0x18) * 1000 + local_50;
                  piVar3[1] = 0;
                  piVar3[2] = 0;
                  piVar3[3] = 1;
                  piVar3[9] = 0xf;
                  piVar3[8] = 0;
                  *(undefined1 *)(piVar3 + 4) = 0;
                  FUN_00403040(local_38,0,0xffffffff);
                }
                if ((DAT_00fd94d8 & 1) == 0) {
                  DAT_00fd94d8 = DAT_00fd94d8 | 1;
                  local_c._0_1_ = 2;
                  FUN_007b5430();
                  _atexit((_func_4879 *)&LAB_00bce660);
                }
                local_c = (uint)local_c._1_3_ << 8;
                FUN_007b61d0(&DAT_00fd9420,piVar3,in_ECX + 4);
              }
            }
            local_44 = local_44 + 1;
            local_48 = local_48 + 0x20;
          } while (local_44 < (uint)(*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8) >> 5));
        }
        local_c = 0xffffffff;
        if (0xf < local_24) {
          FUN_0089120c(local_38[0]);
        }
        local_4c = local_4c + 0x14;
        local_50 = local_50 + 1;
      } while (local_50 < *(int *)(in_ECX + 0xbc));
    }
    *(undefined4 *)(in_ECX + 0x108) = 1;
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_54);
  return;
}

