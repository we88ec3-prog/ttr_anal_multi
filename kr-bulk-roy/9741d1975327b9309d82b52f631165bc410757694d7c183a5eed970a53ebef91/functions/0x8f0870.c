
void FUN_008f0870(int param_1)

{
  int iVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  undefined1 local_30 [4];
  int local_2c;
  undefined4 local_28;
  uint local_24;
  int local_20;
  int local_1c;
  ushort local_18;
  ushort local_16;
  int local_14;
  ushort local_10;
  byte local_e;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar1 = *(int *)(param_1 + 0x68);
  local_28 = *(undefined4 *)(iVar1 + 0x1c);
  iVar2 = *(int *)(param_1 + 0x2a4);
  local_20 = (**(code **)(param_1 + 0x1fc))(param_1,0x67766172,iVar1,local_30);
  if (local_20 == 0) {
    iVar4 = FUN_008b9850(iVar1);
    local_2c = iVar4;
    local_20 = FUN_008bacd0(iVar1,&DAT_00beaa4c,&local_1c);
    if (local_20 == 0) {
      *(uint *)(iVar2 + 0x18) = (uint)local_16;
      *(uint *)(iVar2 + 0x20) = (uint)local_10;
      local_24 = local_c + iVar4;
      if ((local_1c != 0x10000) || (local_18 != **(ushort **)(iVar2 + 8))) {
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      uVar5 = FUN_008bc7d0(local_28,4,0,local_10 + 1,0,&local_20);
      *(undefined4 *)(iVar2 + 0x24) = uVar5;
      if (local_20 == 0) {
        if ((local_e & 1) == 0) {
          local_20 = FUN_008babe0(iVar1,*(int *)(iVar2 + 0x20) * 2 + 2);
          if (local_20 != 0) goto LAB_008f0a80;
          uVar6 = 0;
          do {
            uVar7 = FUN_008b9960(iVar1);
            *(uint *)(*(int *)(iVar2 + 0x24) + uVar6 * 4) = local_24 + (uVar7 & 0xffff) * 2;
            uVar6 = uVar6 + 1;
          } while (uVar6 <= *(uint *)(iVar2 + 0x20));
        }
        else {
          local_20 = FUN_008babe0(iVar1,*(int *)(iVar2 + 0x20) * 4 + 4);
          if (local_20 != 0) goto LAB_008f0a80;
          uVar6 = 0;
          do {
            iVar4 = FUN_008b99c0(iVar1);
            *(uint *)(*(int *)(iVar2 + 0x24) + uVar6 * 4) = iVar4 + local_24;
            uVar6 = uVar6 + 1;
          } while (uVar6 <= *(uint *)(iVar2 + 0x20));
        }
        FUN_008baca0(iVar1);
        if (*(int *)(iVar2 + 0x18) != 0) {
          uVar5 = FUN_008bc7d0(local_28,4,0,(uint)local_18 * *(int *)(iVar2 + 0x18),0,&local_20);
          *(undefined4 *)(iVar2 + 0x1c) = uVar5;
          if (((local_20 == 0) &&
              (local_20 = FUN_008b97e0(iVar1,local_14 + local_2c), local_20 == 0)) &&
             (local_20 = FUN_008babe0(iVar1,(uint)local_18 * *(int *)(iVar2 + 0x18) * 2),
             local_20 == 0)) {
            local_24 = 0;
            if (*(int *)(iVar2 + 0x18) != 0) {
              uVar6 = (uint)local_18;
              local_24 = 0;
              do {
                uVar7 = 0;
                if (uVar6 != 0) {
                  do {
                    sVar3 = FUN_008b9960(iVar1);
                    *(int *)(*(int *)(iVar2 + 0x1c) + (local_18 * local_24 + uVar7) * 4) = sVar3 * 4
                    ;
                    uVar6 = (uint)local_18;
                    uVar7 = uVar7 + 1;
                  } while (uVar7 < uVar6);
                }
                local_24 = local_24 + 1;
              } while (local_24 < *(uint *)(iVar2 + 0x18));
            }
            FUN_008baca0(iVar1);
          }
        }
      }
    }
  }
LAB_008f0a80:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

