
void FUN_006d79b0(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  size_t _Size;
  int iVar5;
  uint uVar6;
  undefined1 local_48 [4];
  int local_44;
  int local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  int *local_34;
  undefined1 *local_30;
  void *local_2c;
  undefined1 local_28 [24];
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_38 = param_1;
  local_34 = param_2;
  (**(code **)(*param_2 + 0x34))(param_2,local_48,0,0x2000);
  (**(code **)(*param_2 + 0x30))(param_2,local_28);
  iVar2 = local_10;
  uVar6 = local_10 * 0x18 + 0x1fU >> 3 & 0x1ffffffc;
  _Size = uVar6 * local_c;
  local_2c = (void *)FUN_00891268(_Size);
  _memset(local_2c,0,_Size);
  iVar5 = 0;
  local_40 = local_44;
  if (0 < local_c) {
    local_30 = (undefined1 *)((int)local_2c + 2);
    do {
      iVar4 = 0;
      puVar3 = local_30;
      if (0 < iVar2) {
        do {
          uVar1 = *(undefined4 *)(local_44 + (iVar5 * local_10 + iVar4) * 4);
          puVar3[-2] = (char)uVar1;
          local_3c._2_1_ = (undefined1)((uint)uVar1 >> 0x10);
          puVar3[-1] = (char)((uint)uVar1 >> 8);
          *puVar3 = local_3c._2_1_;
          iVar4 = iVar4 + 1;
          puVar3 = puVar3 + 3;
          param_2 = local_34;
          local_3c = uVar1;
        } while (iVar4 < iVar2);
      }
      iVar5 = iVar5 + 1;
      local_30 = local_30 + uVar6;
    } while (iVar5 < local_c);
  }
  *local_38 = local_2c;
  (**(code **)(*param_2 + 0x38))(param_2);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

