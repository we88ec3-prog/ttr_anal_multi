
void FUN_006dc180(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  bool bVar2;
  char cVar3;
  undefined4 uVar4;
  int unaff_ESI;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00919843;
  local_14 = ExceptionList;
  if (*(int *)(unaff_ESI + 0x10) == 0) {
    return;
  }
  bVar2 = true;
  ExceptionList = &local_14;
  if ((DAT_00f8d9a8 & 1) == 0) {
    DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
    local_c = 0;
    FUN_00523540(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
    local_c = CONCAT31(local_c._1_3_,1);
    FUN_00521080(&DAT_00f8d9bc);
    _atexit((_func_4879 *)&LAB_00bccc50);
  }
  local_c = 0xffffffff;
  local_2c = param_1;
  FUN_008438c0(&local_2c);
  if ((local_28 == DAT_00f8d9b0) || (iVar1 = *(int *)(local_28 + 0x10), iVar1 == 0))
  goto switchD_006dc256_caseD_3;
  uVar4 = 0;
  if (*(int *)(iVar1 + 8) - 1U < 0x2b) {
    uVar4 = FUN_00520f40();
  }
  FUN_006dc350(unaff_ESI,uVar4);
  switch(*(undefined4 *)(iVar1 + 8)) {
  case 1:
    uVar4 = 0x24;
    break;
  case 2:
  case 0x2b:
    uVar4 = 0x25;
    break;
  default:
    goto switchD_006dc256_caseD_3;
  case 0x24:
    cVar3 = FUN_006dd150(unaff_ESI,1);
    goto joined_r0x006dc2aa;
  case 0x25:
    cVar3 = FUN_006dd150(unaff_ESI,2);
    if (cVar3 != '\0') {
      uVar4 = FUN_00520f40();
      FUN_006dc700(unaff_ESI,uVar4);
    }
    cVar3 = FUN_006dd150(unaff_ESI,0x2b);
joined_r0x006dc2aa:
    if (cVar3 != '\0') {
      uVar4 = FUN_00520f40();
      FUN_006dc700(unaff_ESI,uVar4);
    }
    goto switchD_006dc256_caseD_3;
  }
  cVar3 = FUN_006dd150(unaff_ESI,uVar4);
  if (cVar3 != '\0') {
    bVar2 = false;
  }
switchD_006dc256_caseD_3:
  local_24 = param_1;
  local_20 = param_2;
  local_1c = param_3;
  FUN_0052ef90();
  if (bVar2) {
    FUN_007a7240(*(undefined4 *)(unaff_ESI + 0x10),param_1,param_2,param_3);
  }
  ExceptionList = local_14;
  return;
}

