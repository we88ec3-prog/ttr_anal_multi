
void FUN_0066a260(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  int *piVar5;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  if (uVar1 < 0x579) {
    if (uVar1 == 0x578) {
      iVar4 = *(int *)(param_1 + 8);
      if (iVar4 == *(int *)(in_ECX[0x3d] + 0x20)) {
        FUN_006689f0(in_ECX);
        return;
      }
      if (iVar4 == *(int *)(in_ECX[0x3e] + 0x20)) {
        (**(code **)(*in_ECX + 0xd4))();
        return;
      }
      iVar3 = 0;
      piVar5 = in_ECX + 0x43;
      do {
        if (iVar4 == *(int *)(*piVar5 + 0x20)) {
          FUN_0066a730(in_ECX,iVar3);
          return;
        }
        iVar3 = iVar3 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar3 < 3);
      return;
    }
    if (uVar1 == 0x387) {
      puVar2 = (undefined4 *)FUN_00891268(0x14);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = FoxUI::FXUIEvent::vftable;
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0xf4352;
        FUN_004072a0();
        return;
      }
      FUN_004072a0();
      return;
    }
    if (uVar1 == 0x3eb) {
      if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x3f] + 0x20)) {
        iVar4 = in_ECX[9];
        *(int *)(iVar4 + 0x13dc) = in_ECX[0x40];
        *(undefined1 *)(iVar4 + 0x13d9) = 1;
        return;
      }
      if (*(int *)(param_1 + 8) == *(int *)(in_ECX[0x40] + 0x20)) {
        iVar4 = in_ECX[9];
        *(int *)(iVar4 + 0x13dc) = in_ECX[0x41];
        *(undefined1 *)(iVar4 + 0x13d9) = 1;
        return;
      }
    }
  }
  else if (uVar1 == 0xf43a4) {
    FUN_0066b210(in_ECX,param_1);
  }
  else if (uVar1 == 0xf43d5) {
    iVar4 = FUN_004068c0();
    if (*(int *)(iVar4 + 0x14) == 0x6a7) {
      FUN_00669a00();
      return;
    }
  }
  return;
}

