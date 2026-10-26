
/* WARNING: Removing unreachable block (ram,0x008664bf) */

void FUN_00866280(void)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  int local_4c;
  int local_48;
  uint local_44;
  uint *local_3c;
  uint local_38;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00913c08;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar3 = *(int *)(in_ECX + 0x34) - *(int *)(in_ECX + 0x30);
  iVar5 = iVar3 >> 0x1f;
  local_44 = 0;
  if (iVar3 / 0x11c + iVar5 != iVar5) {
    local_4c = 0;
    local_48 = 0;
    uVar7 = uVar2;
    do {
      local_8 = 0xffffffff;
      if ((uint)((*(int *)(in_ECX + 0x44) - *(int *)(in_ECX + 0x40)) / 0x1c) <= local_44) {
LAB_00866521:
                    /* WARNING: Subroutine does not return */
        FUN_0087db7d("invalid vector<T> subscript",uVar7);
      }
      FUN_00403040(local_48 + *(int *)(in_ECX + 0x40),0,0xffffffff);
      local_8 = 0;
      FUN_00721910();
      FUN_00721910();
      iVar5 = *(int *)(in_ECX + 0x30);
      if ((uint)((*(int *)(in_ECX + 0x34) - iVar5) / 0x11c) <= local_44) goto LAB_00866521;
      uVar1 = *(uint *)(local_4c + 8 + iVar5);
      iVar5 = local_4c + iVar5;
      FUN_00721910();
      uVar4 = 0;
      if (uVar1 != 0) {
        do {
          FUN_00843770();
          FUN_00721910();
          FUN_00721910();
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar1);
      }
      puVar6 = (uint *)(iVar5 + 0x18);
      local_38 = 0;
      do {
        uVar1 = *puVar6;
        FUN_00721910();
        uVar4 = 0;
        if (uVar1 != 0) {
          do {
            FUN_008437e0(iVar5);
            FUN_00721910();
            FUN_00721910();
            uVar4 = uVar4 + 1;
          } while (uVar4 < uVar1);
        }
        local_38 = local_38 + 1;
        puVar6 = puVar6 + 4;
      } while (local_38 < 8);
      local_3c = (uint *)(iVar5 + 0x98);
      local_38 = 0;
      do {
        uVar1 = *local_3c;
        FUN_00721910();
        uVar4 = 0;
        if (uVar1 != 0) {
          do {
            FUN_00843850(iVar5);
            FUN_00721910();
            FUN_00721910();
            uVar4 = uVar4 + 1;
          } while (uVar4 < uVar1);
        }
        local_3c = local_3c + 4;
        local_38 = local_38 + 1;
      } while (local_38 < 8);
      local_48 = local_48 + 0x1c;
      local_4c = local_4c + 0x11c;
      local_44 = local_44 + 1;
    } while (local_44 < (uint)((*(int *)(in_ECX + 0x34) - *(int *)(in_ECX + 0x30)) / 0x11c));
  }
  local_8 = 0xffffffff;
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

