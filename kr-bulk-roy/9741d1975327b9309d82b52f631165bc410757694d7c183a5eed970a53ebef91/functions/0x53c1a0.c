
undefined4 FUN_0053c1a0(short param_1)

{
  int in_EAX;
  uint uVar1;
  int iVar2;
  uint uVar3;
  short *psVar4;
  
  uVar3 = 0;
  uVar1 = *(int *)(in_EAX + 8) - *(int *)(in_EAX + 4) >> 1;
  if (uVar1 != 0) {
    psVar4 = *(short **)(in_EAX + 4);
    do {
      if (*psVar4 == param_1) {
        return 0;
      }
      uVar3 = uVar3 + 1;
      psVar4 = psVar4 + 1;
    } while (uVar3 < uVar1);
  }
  FUN_0044b4e0();
  iVar2 = FUN_0041a4d0();
  if (*(int *)(iVar2 + 0x5ed8) != 0) {
    iVar2 = FUN_0041a4d0();
    if (**(short **)(iVar2 + 0x5ed8) != param_1) {
      FUN_00414680();
      FUN_004a3fc0();
      FUN_00414680();
      FUN_004a4000();
    }
  }
  return 1;
}

