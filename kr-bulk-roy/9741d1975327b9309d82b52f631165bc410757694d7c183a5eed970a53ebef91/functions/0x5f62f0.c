
void FUN_005f62f0(int param_1)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  
  FUN_007445d0(param_1);
  if (*(int *)(param_1 + 0x10) == 0x82) {
    if (*(int *)(in_ECX + 0x24) != -0xa8) {
      FUN_0043c810((float)*(int *)(*(int *)(in_ECX + 0x24) + 0xc4) / 120.0);
      iVar3 = FUN_008fed10();
      iVar4 = *(int *)(in_ECX + 0xd0);
      iVar5 = *(int *)(iVar4 + 0xd8) * iVar3;
      if (0 < iVar3) {
        if (*(int *)(iVar4 + 0xb8) < iVar5 + *(int *)(iVar4 + 0xc4)) {
          iVar4 = *(int *)(iVar4 + 0xb8);
        }
        else {
          iVar4 = *(int *)(iVar4 + 0xd8) * iVar3 + *(int *)(iVar4 + 0xc4);
        }
        piVar1 = *(int **)(in_ECX + 0xd0);
        pcVar2 = *(code **)(*piVar1 + 0x128);
        piVar1[0x31] = iVar4;
        (*pcVar2)();
        (**(code **)(*piVar1 + 200))();
        FUN_005f6700(in_ECX);
        return;
      }
      if (iVar5 + *(int *)(iVar4 + 0xc4) < 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(iVar4 + 0xd8) * iVar3 + *(int *)(iVar4 + 0xc4);
      }
      piVar1 = *(int **)(in_ECX + 0xd0);
      pcVar2 = *(code **)(*piVar1 + 0x128);
      piVar1[0x31] = iVar4;
      (*pcVar2)();
      (**(code **)(*piVar1 + 200))();
    }
    FUN_005f6700(in_ECX);
  }
  return;
}

