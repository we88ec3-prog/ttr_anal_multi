
void FUN_0043bb60(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 *puVar5;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009201f6;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0043c480(local_14);
  FUN_006c9840();
  FUN_0043c570(600);
  FUN_0043c570(700);
  iVar2 = *(int *)(in_ECX + 0x248);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar2 + 0xa4) = 1;
  iVar2 = *(int *)(in_ECX + 0x248);
  if ((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) {
    iVar1 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))();
    if (iVar1 == 0xbf6b) {
      *(undefined1 *)(*(int *)(iVar2 + 0x94) + 0x4c) = 1;
    }
  }
  (**(code **)(**(int **)(in_ECX + 0x24c) + 0x198))(0x1fe);
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  iVar2 = DAT_00f943ac;
  local_38 = 0x10;
  FUN_0082ef00(&local_38);
  if ((local_34 != *(int *)(iVar2 + 8)) && (local_34 = *(int *)(local_34 + 0x10), local_34 != 0)) {
    iVar2 = 0;
    puVar5 = (undefined4 *)(in_ECX + 600);
    do {
      iVar2 = iVar2 + 1;
      puVar3 = (undefined4 *)FUN_004068f0();
      local_8 = 1;
      if (7 < (uint)puVar3[5]) {
        puVar3 = (undefined4 *)*puVar3;
      }
      uVar4 = FUN_00763360(puVar3);
      local_8 = 0xffffffff;
      *puVar5 = uVar4;
      if (7 < local_1c) {
        FUN_0089120c(local_30);
      }
      puVar5 = puVar5 + 1;
    } while (iVar2 < 3);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

