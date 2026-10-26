
void FUN_006f6b60(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint local_8;
  
  iVar4 = 1;
  if (1 < *(int *)(param_1 + 4)) {
    local_8 = FUN_006f5460();
    do {
      piVar1 = (int *)FUN_006f50f0();
      switch(piVar1[2]) {
      case 3:
        iVar2 = FUN_006fb5d0();
        if (iVar2 == 0) {
          uVar3 = 0;
        }
        else {
          uVar3 = *(uint *)(*piVar1 + 0xc);
        }
        break;
      case 4:
        uVar3 = *(uint *)(*piVar1 + 0xc);
        break;
      case 5:
        uVar3 = FUN_006f9f10();
        break;
      default:
        uVar3 = 0;
        break;
      case 7:
        uVar3 = *(uint *)(*piVar1 + 0x10);
      }
      if (((*(int *)(param_1 + 4) - iVar4) + 1 < 10) && (local_8 <= uVar3)) break;
      local_8 = local_8 + uVar3;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 4));
    FUN_006f5bb0();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + (1 - iVar4);
  }
  return;
}

