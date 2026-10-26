
void FUN_0043bee0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  undefined4 local_3c [2];
  int local_34;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00934374;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00755e50(local_14);
  piVar1 = (int *)(in_ECX + 0xf4);
  FUN_006c0f40();
  FUN_0043c660();
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  iVar4 = DAT_00f943ac;
  local_3c[0] = 0x5d;
  FUN_0082ef00(local_3c);
  if ((local_34 != *(int *)(iVar4 + 8)) && (*(int *)(local_34 + 0x10) != 0)) {
    iVar4 = *piVar1;
    FUN_007444b0(0xbf6b);
    *(undefined1 *)(iVar4 + 0xa4) = 1;
    iVar4 = *piVar1;
    if ((*(char *)(iVar4 + 0xa4) != '\0') && (*(int *)(iVar4 + 0x94) != 0)) {
      iVar2 = (**(code **)(**(int **)(iVar4 + 0x94) + 4))();
      if (iVar2 == 0xbf6b) {
        *(undefined1 *)(*(int *)(iVar4 + 0x94) + 0x4c) = 1;
      }
    }
    if ((DAT_00fb7a08 & 1) == 0) {
      DAT_00fb7a08 = DAT_00fb7a08 | 1;
      local_8 = 1;
      FUN_0081ee80();
      _atexit(FUN_00bcd310);
      local_8 = 0xffffffff;
    }
    puVar3 = (undefined4 *)FUN_00426ec0();
    local_8 = 2;
    if (7 < (uint)puVar3[5]) {
      puVar3 = (undefined4 *)*puVar3;
    }
    FUN_00763360(puVar3);
    iVar4 = *piVar1;
    if ((*(char *)(iVar4 + 0xa4) != '\0') && (*(int *)(iVar4 + 0x94) != 0)) {
      iVar4 = (**(code **)(**(int **)(iVar4 + 0x94) + 4))();
      if (iVar4 == 0xbf6b) {
        FUN_0077b200();
      }
    }
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    local_30 = local_30 & 0xffff0000;
    local_1c = 7;
    local_20 = 0;
    (**(code **)(*(int *)*piVar1 + 200))();
  }
  FUN_0043c110();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

