
/* WARNING: Removing unreachable block (ram,0x00683c02) */
/* WARNING: Removing unreachable block (ram,0x00683c1c) */

void FUN_00683a80(void)

{
  char cVar1;
  uint uVar2;
  int in_ECX;
  undefined4 extraout_EDX;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920c56;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar3 = 0;
  do {
    FUN_0040aa10(*(undefined4 *)(in_ECX + 0x100));
    iVar3 = iVar3 + 1;
  } while (iVar3 < 9);
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_004095e0(0xa4);
  FUN_004095e0(0xa5);
  FUN_004095e0(0xa6);
  FUN_004095e0(0xa7);
  FUN_004095e0(0xa8);
  FUN_004095e0(0xa9);
  FUN_004095e0(0xaa);
  FUN_004095e0(0xab);
  FUN_004095e0(0xac);
  *(byte *)(in_ECX + 0x13c) = (byte)(*(uint *)(*(int *)(in_ECX + 0x108) + 0x28) >> 9) & 1;
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8._0_1_ = 2;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8._0_1_ = 1;
  }
  cVar1 = *(char *)(in_ECX + 0x13c);
  FUN_00402160(L"false",5);
  local_8 = CONCAT31(local_8._1_3_,3);
  if (cVar1 != '\0') {
    FUN_00402160(L"true",4);
  }
  FUN_0058ec10(&DAT_00faaf80,L"CorrectEquipCheck");
  ExceptionList = local_10;
  __security_check_cookie
            (uVar2 ^ (uint)&stack0xfffffffc,extraout_EDX,FoxUI::FXUIBinderBase::vftable);
  return;
}

