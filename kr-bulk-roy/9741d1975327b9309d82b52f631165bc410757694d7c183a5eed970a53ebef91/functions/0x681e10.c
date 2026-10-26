
/* WARNING: Removing unreachable block (ram,0x00681fb4) */
/* WARNING: Removing unreachable block (ram,0x00681fc8) */

void FUN_00681e10(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 in_ECX;
  int in_EDX;
  undefined1 local_30 [4];
  undefined4 *local_2c;
  undefined4 local_28;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00942cc2;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 **)(in_EDX + 0xcc) = param_3;
  *(undefined4 *)(in_EDX + 0xd4) = in_ECX;
  *(undefined4 *)(in_EDX + 0xd0) = 1;
  if (param_3 == (undefined4 *)0x6) {
    *(undefined4 *)(in_EDX + 0xd0) = 3;
  }
  else if (param_3 == (undefined4 *)0x5) {
    *(undefined4 *)(in_EDX + 0xd0) = 4;
  }
  *(undefined4 *)(*(int *)(in_EDX + 0xd8) + 700) = *(undefined4 *)(in_EDX + 0xd0);
  *(undefined4 *)(*(int *)(in_EDX + 0xdc) + 700) = *(undefined4 *)(in_EDX + 0xd0);
  *(undefined4 *)(*(int *)(in_EDX + 0xe0) + 700) = *(undefined4 *)(in_EDX + 0xd0);
  *(undefined4 *)(*(int *)(in_EDX + 0xe4) + 700) = *(undefined4 *)(in_EDX + 0xd0);
  *(undefined4 *)(*(int *)(in_EDX + 0xe8) + 700) = *(undefined4 *)(in_EDX + 0xd0);
  *(undefined4 *)(*(int *)(in_EDX + 0xec) + 700) = *(undefined4 *)(in_EDX + 0xd0);
  *(undefined4 *)(*(int *)(in_EDX + 0xf0) + 700) = *(undefined4 *)(in_EDX + 0xd0);
  *(undefined4 *)(*(int *)(in_EDX + 0xf4) + 700) = *(undefined4 *)(in_EDX + 0xd0);
  *(undefined4 *)(*(int *)(in_EDX + 0xf8) + 700) = *(undefined4 *)(in_EDX + 0xd0);
  *(undefined4 *)(*(int *)(in_EDX + 0xfc) + 700) = *(undefined4 *)(in_EDX + 0xd0);
  local_28 = 0;
  local_2c = (undefined4 *)FUN_00891268(0x24,uVar2);
  if (local_2c == (undefined4 *)0x0) {
    local_14 = (char *)0x0;
    std::exception::exception((exception *)local_20,&local_14);
    local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_20,&DAT_00c857a8);
  }
  *local_2c = local_2c;
  local_2c[1] = local_2c;
  local_2c[2] = local_2c;
  *(undefined1 *)(local_2c + 8) = 1;
  *(undefined1 *)((int)local_2c + 0x21) = 1;
  local_8 = 0;
  FUN_004fc250(DAT_00fe1db4,param_1,param_2,local_30,param_4);
  FUN_00835c70((undefined4 *)(in_EDX + 0xd4));
  if (param_3 == local_2c) {
    iVar3 = *(int *)(in_EDX + 0x100);
    if (iVar3 != *(int *)(in_EDX + 0x104)) {
      *(int *)(in_EDX + 0x104) = iVar3;
    }
  }
  else {
    FUN_004fcdc0(param_3 + 4);
  }
  *(undefined4 *)(in_EDX + 0x120) = 0;
  iVar3 = *(int *)(in_EDX + 0x104) - *(int *)(in_EDX + 0x100) >> 3;
  fVar1 = (float)iVar3;
  if (iVar3 < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  FUN_0043c810(fVar1 / 10.0);
  uVar4 = FUN_008fed10();
  *(undefined4 *)(in_EDX + 0x124) = uVar4;
  FUN_00682290();
  local_8 = 1;
  FUN_0085e680(*local_2c,local_2c);
  FUN_0089120c(local_2c);
  ExceptionList = local_10;
  return;
}

