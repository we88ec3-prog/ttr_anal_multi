
void FUN_00402dc0(uint param_1)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  uint uStack_3c;
  undefined **local_2c [4];
  char *local_1c [2];
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00908bd0;
  local_10 = ExceptionList;
  uStack_3c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_3c;
  ExceptionList = &local_10;
  uVar5 = param_1 | 0xf;
  if (uVar5 != 0xffffffff) {
    uVar1 = *(uint *)(in_ECX + 0x14);
    uVar4 = uVar1 >> 1;
    param_1 = uVar5;
    if ((uVar5 / 3 < uVar4) && (param_1 = uVar4 + uVar1, -uVar4 - 2 < uVar1)) {
      param_1 = 0xfffffffe;
    }
  }
  local_8 = 0;
  puVar2 = &uStack_3c;
  if ((param_1 + 1 != 0) &&
     (iVar3 = FUN_00891268(param_1 + 1), puVar2 = (uint *)local_14, iVar3 == 0)) {
    local_1c[0] = (char *)0x0;
    std::exception::exception((exception *)local_2c,local_1c);
    local_2c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_2c,&DAT_00c857a8);
  }
  local_14 = (undefined1 *)puVar2;
  FUN_00402e9c();
  return;
}

