
void FUN_00462010(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009415ec;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc0d44 & 1) == 0) {
    DAT_00fc0d44 = DAT_00fc0d44 | 1;
    local_8 = 0;
    FUN_00462200();
    _atexit(FUN_00bcd800);
  }
  local_8 = 0xffffffff;
  puVar1 = (undefined4 *)FUN_00401070();
  if ((DAT_00fc0d44 & 1) == 0) {
    DAT_00fc0d44 = DAT_00fc0d44 | 1;
    local_8 = 1;
    FUN_00462200();
    _atexit(FUN_00bcd800);
    local_8 = 0xffffffff;
  }
  puVar2 = (undefined4 *)FUN_00401140();
  if ((puVar1 != (undefined4 *)0x0) && (puVar2 != (undefined4 *)0x0)) {
    *(undefined4 *)(param_1 + 0xfc) = *puVar1;
    *(undefined4 *)(param_1 + 0x100) = *puVar2;
    FUN_00757800();
    (**(code **)(**(int **)(param_1 + 0xf0) + 200))();
    FUN_00757800();
    (**(code **)(**(int **)(param_1 + 0xf8) + 200))();
    iVar3 = FUN_00404ba0();
    *(undefined4 *)(iVar3 + 0x6990) = in_ECX;
  }
  ExceptionList = local_10;
  return;
}

