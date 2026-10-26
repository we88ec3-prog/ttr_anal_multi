
void FUN_0073d410(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 *puVar7;
  int in_ECX;
  int *unaff_FS_OFFSET;
  int local_20;
  int local_1c [4];
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar1 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f27b;
  local_1c[3] = *unaff_FS_OFFSET;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)(local_1c + 3);
  iVar3 = FUN_0073e670(*(undefined4 *)(in_ECX + 0x1c),*(undefined4 *)(in_ECX + 0x20),
                       *(undefined4 *)(in_ECX + 0x38));
  if (iVar3 != 0) {
    local_1c[1] = 0;
    local_1c[2] = 0;
    FUN_0073d2d0(uVar2);
    iVar4 = FUN_00891268(0x2c);
    local_8 = 0;
    if (iVar4 == 0) {
      uVar5 = 0;
    }
    else {
      local_1c[0] = iVar3;
      FUN_008438c0(local_1c);
      if (local_20 == *(int *)(iVar1 + 0x20)) {
        uVar5 = 0;
      }
      else {
        uVar5 = *(undefined4 *)(local_20 + 0x10);
      }
      uVar5 = FUN_0073fd00(iVar4,uVar5,*(undefined4 *)(in_ECX + 0x34),*(undefined4 *)(in_ECX + 0x38)
                          );
    }
    iVar1 = param_1;
    local_8 = 0xffffffff;
    param_1 = 0;
    piVar6 = (int *)FUN_008438c0(&param_1);
    if (*piVar6 == *(int *)(iVar1 + 0x30)) {
      param_1 = 0;
      puVar7 = (undefined4 *)FUN_0073fc30();
      *puVar7 = uVar5;
    }
  }
  *unaff_FS_OFFSET = local_1c[3];
  return;
}

