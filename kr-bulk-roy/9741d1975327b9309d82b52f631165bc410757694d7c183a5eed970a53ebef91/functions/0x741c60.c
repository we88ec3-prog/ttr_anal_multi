
void FUN_00741c60(int param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *unaff_FS_OFFSET;
  uint uStack_34;
  undefined **local_24 [3];
  char *local_18;
  undefined1 *local_14;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00907e70;
  local_10 = *unaff_FS_OFFSET;
  uStack_34 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_34;
  *unaff_FS_OFFSET = (int)&local_10;
  uVar5 = param_2 | 7;
  if (uVar5 < 0x7fffffff) {
    uVar1 = *(uint *)(param_1 + 0x14);
    uVar4 = uVar1 >> 1;
    param_2 = uVar5;
    if ((uVar5 / 3 < uVar4) && (param_2 = uVar4 + uVar1, 0x7ffffffe - uVar4 < uVar1)) {
      param_2 = 0x7ffffffe;
    }
  }
  param_2 = param_2 + 1;
  local_8 = 0;
  puVar2 = &uStack_34;
  if ((param_2 != 0) &&
     ((puVar2 = &uStack_34, 0x7fffffff < param_2 ||
      (iVar3 = FUN_00891268(param_2 * 2), puVar2 = (uint *)local_14, iVar3 == 0)))) {
    local_14 = (undefined1 *)puVar2;
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_24,&local_18);
    local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_24,&DAT_00c857a8);
  }
  local_14 = (undefined1 *)puVar2;
  FUN_00741d44();
  return;
}

