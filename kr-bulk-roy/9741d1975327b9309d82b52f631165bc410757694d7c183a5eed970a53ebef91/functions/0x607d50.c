
void FUN_00607d50(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined1 auStack_70 [20];
  undefined4 uStack_5c;
  undefined1 auStack_44 [4];
  undefined1 *local_40;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093e6fc;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_44;
  ExceptionList = &local_14;
  FUN_007459c0();
  iVar2 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_00607dc4;
    iVar2 = FUN_00745c20();
  }
  if ((((iVar2 != 0) && (*(int *)(iVar2 + 0x60) != 0)) &&
      ((*(uint *)(iVar2 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar2 + 0x60) != 0)) {
    uStack_5c = 0x607dc4;
    FUN_0074a010();
  }
LAB_00607dc4:
  if (*(int *)(*(int *)(in_ECX + 0xf4) + 0xcc) != 0) {
    uStack_5c = 0x607ddb;
    FUN_0042c8e0();
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    uStack_5c = 0x607e06;
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  local_40 = auStack_70;
  FUN_00412df0();
  local_c = 1;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_c._0_1_ = 2;
    local_c._1_3_ = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_c = CONCAT31(local_c._1_3_,1);
  }
  local_3c = 0x1a;
  FUN_005740f0(&local_3c);
  if (local_40 == DAT_00fe5ac8) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  puVar3 = (undefined4 *)(local_40 + 0x10);
  if (7 < *(uint *)(local_40 + 0x24)) {
    puVar3 = (undefined4 *)*puVar3;
  }
  local_c = 0xffffffff;
  FUN_00424c80(puVar3);
  local_c = 3;
  uStack_5c = 0x607ec6;
  FUN_00757800();
  local_c = 0xffffffff;
  if (7 < local_24) {
    uStack_5c = 0x607ede;
    FUN_0089120c();
  }
  local_38 = local_38 & 0xffff0000;
  local_24 = 7;
  local_28 = 0;
  (**(code **)(**(int **)(in_ECX + 0x108) + 200))();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_44);
  return;
}

