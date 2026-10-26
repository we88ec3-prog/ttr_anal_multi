
/* WARNING: Removing unreachable block (ram,0x007dadbc) */

void FUN_007daca0(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920796;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0xd4) == 1) {
    *(undefined4 *)(in_ECX + 0xd4) = 0;
    iVar1 = *(int *)(in_ECX + 0x1c);
    iVar3 = FUN_00407e70(0,uVar2);
    if (iVar3 != 0 || CONCAT31((int3)((uint)iVar3 >> 8),iVar1 != 0) != 0) {
      if ((DAT_00fd94d8 & 1) == 0) {
        DAT_00fd94d8 = DAT_00fd94d8 | 1;
        local_8 = 0;
        FUN_007b5430();
        _atexit((_func_4879 *)&LAB_00bce660);
        local_8 = 0xffffffff;
      }
      FUN_007b5f30(in_ECX + 4);
      FUN_00403040(in_ECX + 0xb4,0,0xffffffff);
      local_8 = 1;
      FUN_00401ed0(in_ECX + 0xc,0,0xffffffff);
      if (*(int *)(in_ECX + 0xd0) != 0) {
        uVar4 = FUN_0049aee0();
        FUN_007b67e0(uVar4);
        *(undefined4 *)(in_ECX + 0xd0) = 0;
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

