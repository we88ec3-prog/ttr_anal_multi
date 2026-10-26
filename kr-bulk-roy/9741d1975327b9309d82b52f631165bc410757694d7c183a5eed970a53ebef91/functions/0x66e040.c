
/* WARNING: Removing unreachable block (ram,0x0066e184) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0066e040(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00916868;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined1 *)(*(int *)(in_ECX + 0xf0) + 200) = 0;
  *(undefined1 *)(*(int *)(in_ECX + 0xf4) + 200) = 0;
  uVar1 = _DAT_00fe5abc & 1;
  *(undefined1 *)(*(int *)(in_ECX + 0xf0) + 0xca) = 1;
  uVar4 = uVar2;
  if (uVar1 == 0) {
    _DAT_00fe5abc = _DAT_00fe5abc | 1;
    DAT_00fe5ab4 = 7;
    _DAT_00fe5ab0 = 0;
    DAT_00fe5aa0._0_2_ = 0;
    _atexit((_func_4879 *)&LAB_00bcfe10);
  }
  FUN_0047a6d0(uVar4);
  FUN_004026e0(&DAT_00fe5aa0,0,0xffffffff);
  local_8 = 0;
  iVar3 = FUN_0044df20(0,&DAT_00bed1fc,0);
  if (iVar3 != 0) {
    iVar3 = *(int *)(in_ECX + 0xf0);
    if (*(char *)(iVar3 + 0x141) == '\0') {
      FUN_00757710();
    }
    else {
      FUN_006edb10("Not supported operation");
    }
    *(undefined4 *)(iVar3 + 0x168) = 0;
    *(undefined4 *)(iVar3 + 0x160) = 0;
    *(undefined4 *)(iVar3 + 0x164) = 0;
    *(undefined4 *)(iVar3 + 0x14c) = 0;
    (**(code **)(**(int **)(in_ECX + 0xf0) + 200))();
    (**(code **)(**(int **)(in_ECX + 0x104) + 0xa0))(1);
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

