
void FUN_0066daf0(undefined4 param_1,int param_2,uint param_3,int param_4,uint param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int *unaff_FS_OFFSET;
  undefined4 local_64 [15];
  int local_28 [4];
  uint local_18;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090a9d8;
  local_10 = *unaff_FS_OFFSET;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  if (param_3 != param_5) {
    do {
      param_5 = param_5 - 1;
      if (param_3 == param_5) break;
      uVar3 = param_5;
      if (*(uint *)(param_4 + 8) <= param_5) {
        uVar3 = param_5 - *(uint *)(param_4 + 8);
      }
      uVar4 = param_3;
      if (*(uint *)(param_2 + 8) <= param_3) {
        uVar4 = param_3 - *(uint *)(param_2 + 8);
      }
      uVar1 = *(undefined4 *)(*(int *)(param_4 + 4) + uVar3 * 4);
      puVar2 = *(undefined4 **)(*(int *)(param_2 + 4) + uVar4 * 4);
      puVar7 = local_64;
      puVar6 = puVar2;
      for (iVar5 = 0xf; puVar6 = puVar6 + 1, iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar6;
        puVar7 = puVar7 + 1;
      }
      FUN_00507f70(local_28,puVar2 + 0x10);
      local_8 = 0;
      FUN_0066d490(puVar2);
      FUN_0066d490(uVar1);
      local_8 = 0xffffffff;
      if (local_28[0] != 0) {
        FUN_0089120c(local_28[0]);
      }
      param_3 = param_3 + 1;
    } while (param_3 != param_5);
  }
  *unaff_FS_OFFSET = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

