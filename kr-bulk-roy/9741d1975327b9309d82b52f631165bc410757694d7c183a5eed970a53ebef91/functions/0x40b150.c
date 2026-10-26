
void FUN_0040b150(int param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uStack_38;
  undefined **local_28 [4];
  char *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00908bb0;
  local_10 = ExceptionList;
  uStack_38 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_38;
  ExceptionList = &local_10;
  uVar5 = param_2 | 0xf;
  if (uVar5 != 0xffffffff) {
    uVar1 = *(uint *)(param_1 + 0x14);
    uVar4 = uVar1 >> 1;
    param_2 = uVar5;
    if ((uVar5 / 3 < uVar4) && (param_2 = uVar4 + uVar1, -uVar4 - 2 < uVar1)) {
      param_2 = 0xfffffffe;
    }
  }
  local_8 = 0;
  puVar2 = &uStack_38;
  if ((param_2 + 1 != 0) &&
     (iVar3 = FUN_00891268(param_2 + 1), puVar2 = (uint *)local_14, iVar3 == 0)) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_28,&local_18);
    local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00c857a8);
  }
  local_14 = (undefined1 *)puVar2;
  FUN_0040b22a();
  return;
}

