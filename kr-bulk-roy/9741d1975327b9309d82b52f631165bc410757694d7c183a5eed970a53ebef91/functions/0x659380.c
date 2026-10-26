
void FUN_00659380(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *in_ECX;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00919efa;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = CONCAT31(local_14._1_3_,1);
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 0;
    FUN_0058d410(uVar5);
    _atexit((_func_4879 *)&LAB_00bccdc0);
  }
  local_8 = 0xffffffff;
  FUN_0058eb30(L"MoveLock",&local_14);
  iVar1 = in_ECX[4];
  iVar2 = in_ECX[5];
  iVar3 = in_ECX[2];
  iVar4 = in_ECX[3];
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 1;
    FUN_0058d410(uVar5);
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = 0xffffffff;
  }
  FUN_0058ee60(&DAT_00faaf80);
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 2;
    FUN_0058d410(uVar5);
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = 0xffffffff;
  }
  FUN_0058ee60(&DAT_00faaf80);
  (**(code **)(*in_ECX + 0xbc))
            (in_ECX[2],in_ECX[3],in_ECX[2] + (iVar1 - iVar3),(iVar2 - iVar4) + in_ECX[3]);
  *(bool *)((int)in_ECX + 0xea) = (char)local_14 == '\0';
  (**(code **)(*in_ECX + 0x16c))((char)local_14 == '\0');
  (**(code **)(*(int *)in_ECX[0x44] + 0xa0))(local_14);
  ExceptionList = local_10;
  return;
}

