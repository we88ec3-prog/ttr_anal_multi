
int * FUN_004ba6e0(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  void *pvVar2;
  int *piVar3;
  void *pvVar4;
  uint uVar5;
  uint uStack_38;
  uint uStack_34;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00939ef9;
  local_14 = ExceptionList;
  uStack_34 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  uStack_38 = 0x438;
  uStack_38 = FUN_00891268();
  piVar3 = (int *)0x0;
  local_c = 0;
  if (uStack_38 != 0) {
    piVar3 = (int *)FUN_004d0b80();
  }
  local_c = 0xffffffff;
  param_1 = param_1 + in_ECX * 0x38;
  *(short *)(piVar3 + 1) = (short)in_ECX * 1000;
  uStack_38 = (uint)*(ushort *)(param_1 + 0x5ee0);
  (**(code **)(*piVar3 + 0x3c))();
  FUN_004d0fe0();
  pvVar4 = (void *)0x0;
  pvVar2 = (void *)(*(int *)(param_1 + 0x5eec) - *(int *)(param_1 + 0x5ee8) >> 3);
  if (pvVar2 != (void *)0x0) {
    do {
      if ((piVar3[0x57] != 0) && (piVar3[0xdc] != 0)) {
        FUN_007a7510(piVar3[0x57],*(undefined4 *)(*(int *)(param_1 + 0x5ee8) + (int)pvVar4 * 8),
                     *(undefined4 *)(*(int *)(param_1 + 0x5ee8) + 4 + (int)pvVar4 * 8));
      }
      pvVar4 = (void *)((int)pvVar4 + 1);
    } while (pvVar4 < pvVar2);
  }
  (**(code **)(*piVar3 + 0x44))(param_1 + 0x5ed4,1);
  (**(code **)(*piVar3 + 0x58))(*(undefined1 *)(param_1 + 0x5edc));
  (**(code **)(*piVar3 + 0x5c))(*(undefined4 *)(param_1 + 0x5ee4));
  piVar3[0x107] = 0;
  if (piVar3[0xda] != 0) {
    *(undefined4 *)(piVar3[0xda] + 0x24) = 0;
  }
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  uVar5 = (uint)*(ushort *)(piVar3 + 1);
  uStack_38 = uVar5;
  FUN_0082ef00(&uStack_38);
  if (uStack_34 == DAT_00fab13c) {
    uStack_34 = uVar5;
    uVar1 = FUN_0057ef20();
    FUN_0082f200(&DAT_00fab138,uVar1);
  }
  else {
    FUN_006edb60(&DAT_00c0cef0,uVar5);
  }
  ExceptionList = pvVar2;
  return piVar3;
}

