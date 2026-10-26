
int FUN_0061d1e0(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint3 uVar4;
  byte bVar5;
  uint uVar6;
  int local_20;
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
    local_20 = 0;
  }
  else {
    local_20 = *(int *)(local_1c + 0x10);
  }
  iVar2 = local_20;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  uVar3 = *(uint *)(param_1 + 0x218);
  if (uVar3 < 10) {
    uVar3 = uVar3 * 0x210 + DAT_00f94304;
    uVar6 = -(uint)(*(int *)(uVar3 + 0x5c) != 0) & uVar3;
  }
  else {
    uVar6 = 0;
  }
  uVar3 = uVar3 >> 8;
  if (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x14);
    iVar2 = *(int *)(iVar2 + 0x18);
    if (iVar1 == iVar2) {
      bVar5 = 0;
    }
    else {
      bVar5 = (char)(iVar2 - iVar1 >> 2) - 1;
    }
    param_3 = ((int)param_3 < 1) - 1 & param_3;
    if ((int)(uint)bVar5 <= (int)param_3) {
      if (iVar1 == iVar2) {
        param_3 = 0;
      }
      else {
        param_3 = (uint)(byte)((char)(iVar2 - iVar1 >> 2) - 1);
      }
    }
    if ((param_3 & 0xff) < (uint)(iVar2 - iVar1 >> 2)) {
      bVar5 = *(byte *)(*(int *)(*(int *)(local_20 + 0x14) + (param_3 & 0xff) * 4) + 0x24);
      uVar4 = (uint3)((uint)*(int *)(local_20 + 0x14) >> 8);
    }
    else {
      bVar5 = 0xff;
      uVar4 = 0;
    }
    if (bVar5 <= *(byte *)(uVar6 + 8)) {
      ExceptionList = local_14;
      return CONCAT31(uVar4,1);
    }
    uVar3 = (uint)uVar4;
  }
  ExceptionList = local_14;
  return uVar3 << 8;
}

