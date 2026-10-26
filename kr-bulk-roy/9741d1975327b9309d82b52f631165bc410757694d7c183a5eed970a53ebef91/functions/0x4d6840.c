
void FUN_004d6840(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *in_ECX;
  int *piVar5;
  void *pvStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00933e19;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  puVar2 = (undefined4 *)FUN_00891268(0x24,uVar1);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2[7] = 7;
    puVar2[6] = 0;
    *(undefined2 *)(puVar2 + 2) = 0;
  }
  *puVar2 = 0;
  *(undefined1 *)(puVar2 + 1) = 1;
  FUN_004026e0(in_ECX,0,0xffffffff);
  FUN_004d7b00(param_1);
  iVar3 = FUN_00891268(0x7c,uVar1);
  piVar5 = (int *)0x0;
  local_c = 0;
  if (iVar3 != 0) {
    if (7 < (uint)in_ECX[5]) {
      in_ECX = (undefined4 *)*in_ECX;
    }
    piVar5 = (int *)FUN_004d47f0(in_ECX,0xfffef4bc);
  }
  if ((DAT_00fb7354 & 1) == 0) {
    DAT_00fb7354 = DAT_00fb7354 | 1;
    local_c = 1;
    FUN_005533d0();
    _atexit((_func_4879 *)&LAB_00bcd100);
  }
  local_c = 0xffffffff;
  (**(code **)(*piVar5 + 4))();
  (**(code **)(*piVar5 + 0x20))(DAT_00fb73ac,DAT_00fb73b0);
  piVar5[0x10] = 1;
  uVar4 = FUN_0057ef20();
  FUN_0082f200(&DAT_00fb7378,uVar4);
  DAT_00fb7398 = DAT_00fb7398 + 1;
  if (*(int *)(param_1 + 0x120) == 0) {
    FUN_004d6c90();
  }
  ExceptionList = pvStack_1c;
  return;
}

