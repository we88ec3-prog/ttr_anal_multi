
void FUN_00476970(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *in_ECX;
  int *piVar5;
  int local_14;
  int local_10;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    iVar3 = *(int *)(param_1 + 8);
    if (iVar3 == *(int *)(in_ECX[0x56] + 0x20)) {
      local_14 = 0;
      piVar5 = in_ECX + 0x3d;
      local_10 = 10;
      do {
        local_14 = local_14 + (uint)*(ushort *)(*piVar5 + 0x298);
        puVar4 = (undefined4 *)FUN_00891268(0x1c);
        if (puVar4 != (undefined4 *)0x0) {
          uVar1 = *(undefined4 *)(*piVar5 + 0x2a0);
          uVar2 = *(undefined4 *)(*piVar5 + 0x29c);
          puVar4[1] = 0xffffffff;
          puVar4[2] = 0xffffffff;
          puVar4[3] = 0;
          puVar4[4] = 0xf4369;
          *puVar4 = FoxUI::FXUIEventI2::vftable;
          puVar4[5] = uVar2;
          puVar4[6] = uVar1;
        }
        FUN_004072a0();
        piVar5 = piVar5 + 1;
        local_10 = local_10 + -1;
      } while (local_10 != 0);
      if (local_14 != 0) {
        FUN_004775b0(local_14);
        FUN_00476d10(in_ECX);
        (**(code **)(*in_ECX + 200))();
        return;
      }
    }
    else {
      if (iVar3 == *(int *)(in_ECX[0x58] + 0x20)) {
        FUN_004774b0(in_ECX);
      }
      else if (iVar3 != *(int *)(in_ECX[0x57] + 0x20)) {
        return;
      }
      (**(code **)(*in_ECX + 0xd4))();
    }
  }
  else if (*(int *)(param_1 + 0x10) == 0x58c) {
    piVar5 = in_ECX + 0x3d;
    local_14 = 10;
    do {
      if (*(int *)(param_1 + 8) == *(int *)(*piVar5 + 0x20)) {
        puVar4 = (undefined4 *)FUN_00891268(0x1c);
        if (puVar4 != (undefined4 *)0x0) {
          uVar1 = *(undefined4 *)(*piVar5 + 0x2a0);
          uVar2 = *(undefined4 *)(*piVar5 + 0x29c);
          puVar4[1] = 0xffffffff;
          puVar4[2] = 0xffffffff;
          puVar4[3] = 0;
          puVar4[4] = 0xf4369;
          *puVar4 = FoxUI::FXUIEventI2::vftable;
          puVar4[5] = uVar2;
          puVar4[6] = uVar1;
        }
        FUN_004072a0();
        FUN_004451b0(0xffffffff,0,0,0);
        FUN_00477b20();
      }
      piVar5 = piVar5 + 1;
      local_14 = local_14 + -1;
    } while (local_14 != 0);
    return;
  }
  return;
}

