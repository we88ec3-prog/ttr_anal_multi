
void FUN_005f97c0(void)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  int iVar3;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if (DAT_00f94300 != -0x23a0) {
    iVar1 = *(int *)(DAT_00f94300 + 0x50b8);
    iVar3 = 0;
    iVar2 = (**(code **)(*in_ECX + 0x198))();
    if (0 < iVar2) {
      do {
        if (iVar1 < iVar3 + -0x4f + in_ECX[0x3c] * 0x50) {
          FUN_005dd480();
        }
        else {
          iVar2 = FUN_005dd930(in_ECX[0x3c]);
          if (iVar2 == 0) {
            FUN_005dd3c0(0,0,0,0,1);
          }
          else {
            FUN_005dd3c0(*(undefined4 *)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 0x14),
                         *(undefined4 *)(iVar2 + 8),0,1);
          }
        }
        iVar3 = iVar3 + 1;
        iVar2 = (**(code **)(*in_ECX + 0x198))();
      } while (iVar3 < iVar2);
    }
  }
  ExceptionList = local_14;
  return;
}

