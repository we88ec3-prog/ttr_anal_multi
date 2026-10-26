
uint FUN_00612d60(int param_1,undefined4 param_2,byte param_3)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093e28c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fb11a8 & 1) == 0) {
    DAT_00fb11a8 = DAT_00fb11a8 | 1;
    local_c = 0;
    FUN_00813890(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccec0);
  }
  local_c = 0xffffffff;
  local_20 = param_2;
  FUN_0082ef00(&local_20);
  if (local_1c == DAT_00fb11b0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(local_1c + 0x10);
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  uVar1 = (uint)*(byte *)(param_1 + 0x161);
  if (uVar1 < 10) {
    iVar2 = uVar1 * 0x210;
    uVar1 = iVar2 + DAT_00f94304;
    uVar6 = -(uint)(*(int *)(iVar2 + 0x5c + DAT_00f94304) != 0) & uVar1;
  }
  else {
    uVar6 = 0;
  }
  if (iVar5 == 0) {
    ExceptionList = local_14;
    return uVar1 & 0xffffff00;
  }
  bVar4 = param_3;
  if (param_3 == 0) {
    bVar4 = 0;
  }
  iVar2 = *(int *)(iVar5 + 0x14);
  iVar5 = *(int *)(iVar5 + 0x18);
  if (iVar2 == iVar5) {
    bVar3 = 0;
  }
  else {
    bVar3 = (char)(iVar5 - iVar2 >> 2) - 1;
  }
  if (bVar4 < bVar3) {
    param_3 = -(param_3 != 0) & param_3;
  }
  else if (iVar2 == iVar5) {
    param_3 = 0;
  }
  else {
    param_3 = (char)(iVar5 - iVar2 >> 2) - 1;
  }
  if ((uint)(iVar5 - iVar2 >> 2) <= (uint)param_3) {
    ExceptionList = local_14;
    return (uint)(0xfe < *(byte *)(uVar6 + 8));
  }
  ExceptionList = local_14;
  return (uint)(*(byte *)(*(int *)(iVar2 + (uint)param_3 * 4) + 0x24) <= *(byte *)(uVar6 + 8));
}

