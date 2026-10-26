
void FUN_007cc120(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 in_ECX;
  undefined4 *unaff_EDI;
  int local_ac;
  int *local_a8;
  int local_a4;
  int local_5c;
  undefined4 local_28;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091eb97;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *unaff_EDI = 0;
  local_14 = uVar2;
  FUN_007818c0(&local_ac,param_1);
  local_8 = 0;
  if (local_5c != 0) {
    FUN_00781cc0(uVar2);
  }
  local_5c = 0;
  iVar3 = FUN_00891268(0xb0);
  local_8._0_1_ = 1;
  if (iVar3 == 0) {
    local_28 = 0;
  }
  else {
    local_28 = FUN_007816a0(iVar3,in_ECX,param_2,0);
  }
  local_8._0_1_ = 0;
  cVar1 = (**(code **)(local_ac + 4))();
  if ((cVar1 != '\0') && (iVar3 = local_a4 - (int)local_a8 >> 2, 0 < iVar3)) {
    if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db7d("invalid vector<T> subscript");
    }
    if ((int *)*local_a8 == (int *)0x0) {
      iVar3 = FUN_00891268(0xd0);
      local_8._0_1_ = 2;
      if (iVar3 == 0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = (int *)FUN_0084ce10(iVar3);
      }
      local_8._0_1_ = 0;
      *unaff_EDI = piVar5;
      (**(code **)(*piVar5 + 0x10))(&local_ac);
    }
    else {
      uVar4 = (**(code **)(*(int *)*local_a8 + 0xc))();
      *unaff_EDI = uVar4;
    }
  }
  FUN_00781cc0();
  local_8 = 0xffffffff;
  FUN_00781b20();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

