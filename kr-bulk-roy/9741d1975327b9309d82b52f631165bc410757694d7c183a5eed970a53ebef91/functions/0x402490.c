
void FUN_00402490(uint param_1)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  uint uStack_38;
  undefined **local_28 [3];
  char *local_1c [2];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009068c0;
  local_10 = ExceptionList;
  uStack_38 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_38;
  ExceptionList = &local_10;
  uVar5 = param_1 | 7;
  if (uVar5 < 0x7fffffff) {
    uVar1 = *(uint *)(in_ECX + 0x14);
    uVar4 = uVar1 >> 1;
    param_1 = uVar5;
    if ((uVar5 / 3 < uVar4) && (param_1 = uVar4 + uVar1, 0x7ffffffe - uVar4 < uVar1)) {
      param_1 = 0x7ffffffe;
    }
  }
  param_1 = param_1 + 1;
  local_8 = 0;
  puVar2 = &uStack_38;
  if ((param_1 != 0) &&
     ((puVar2 = &uStack_38, 0x7fffffff < param_1 ||
      (iVar3 = FUN_00891268(param_1 * 2), puVar2 = (uint *)local_14, iVar3 == 0)))) {
    local_14 = (undefined1 *)puVar2;
    local_1c[0] = (char *)0x0;
    std::exception::exception((exception *)local_28,local_1c);
    local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00c857a8);
  }
  local_14 = (undefined1 *)puVar2;
  FUN_00402576();
  return;
}

