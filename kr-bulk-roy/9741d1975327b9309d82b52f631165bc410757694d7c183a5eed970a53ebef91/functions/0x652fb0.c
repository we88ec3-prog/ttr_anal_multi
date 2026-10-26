
void FUN_00652fb0(int param_1)

{
  ushort uVar1;
  char cVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint local_20;
  int iStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00935cec;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  piVar4 = (int *)(param_1 + 0xe8);
  local_20 = 0x10;
  do {
    if (((uint)((int *)*piVar4)[10] >> 8 & 1) == 0) {
      (**(code **)(*(int *)*piVar4 + 0x94))(1,uVar3);
    }
    iVar5 = *(int *)(param_1 + 200);
    (**(code **)(*(int *)*piVar4 + 0xbc))
              (*(undefined4 *)(iVar5 + 8),*(undefined4 *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 0x10)
               ,*(undefined4 *)(iVar5 + 0x14));
    piVar4 = piVar4 + 1;
    local_20 = local_20 - 1;
  } while (local_20 != 0);
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    uStack_c = 0;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    uStack_c = 0xffffffff;
  }
  if (DAT_00fab134 != 0) {
    uVar1 = *(ushort *)(DAT_00fab134 + 0x30);
    if ((char)uVar1 == '\x01') {
      if ((DAT_00fab22c & 1) == 0) {
        DAT_00fab22c = DAT_00fab22c | 1;
        uStack_c = 1;
        FUN_004dec90();
        _atexit((_func_4879 *)&LAB_00bcce30);
        uStack_c = 0xffffffff;
      }
      local_20 = (uint)uVar1;
      FUN_0082ef00(&local_20);
      if ((iStack_1c != DAT_00fab13c) && (*(int *)(iStack_1c + 0x10) != 0)) {
        if (*(int *)(*(int *)(iStack_1c + 0x10) + 0x3d4) == 0) {
          *(undefined1 *)(param_1 + 300) = 0;
          ExceptionList = local_14;
          return;
        }
        cVar2 = FUN_006532f0();
        if (cVar2 == '\0') {
          *(undefined4 *)(param_1 + 0xdc) = 1;
        }
        iVar5 = *(int *)(param_1 + 0xdc);
        if (iVar5 < 0x10) {
          piVar4 = (int *)(param_1 + 0xe8 + iVar5 * 4);
          iVar5 = 0x10 - iVar5;
          do {
            if (((uint)((int *)*piVar4)[10] >> 8 & 1) != 0) {
              (**(code **)(*(int *)*piVar4 + 0x94))(0);
            }
            piVar4 = piVar4 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        *(undefined1 *)(param_1 + 300) = 1;
      }
    }
  }
  ExceptionList = local_14;
  return;
}

