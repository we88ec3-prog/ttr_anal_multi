
void FUN_007821b0(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 **ppuVar2;
  undefined4 **ppuVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint local_c;
  undefined4 *local_8;
  
  FUN_00725070();
  local_c = 0;
  if (*(int *)(param_1 + 0x60) == 0) {
    return;
  }
  do {
    puVar4 = (undefined4 *)FUN_00891268();
    puVar7 = (undefined4 *)0x0;
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[2] = 0;
      puVar4[3] = 0;
      puVar4[4] = 0;
      puVar4[5] = 0;
      puVar7 = puVar4;
    }
    local_8 = puVar7;
    FUN_006ddcc0();
    FUN_006ddcc0(param_2,puVar7 + 1);
    FUN_006ddcc0(param_2,puVar7 + 2,4,0);
    FUN_006ddcc0(param_2,puVar7 + 3,4,0);
    piVar1 = puVar7 + 4;
    FUN_006ddcc0(param_2,piVar1,4,0);
    if (*piVar1 != 0) {
      uVar5 = FUN_0087dc3d(*piVar1);
      puVar7[5] = uVar5;
    }
    FUN_006ddcc0(param_2,puVar7[5],*piVar1,0);
    ppuVar2 = *(undefined4 ***)(param_1 + 0x78);
    if ((&local_8 < ppuVar2) && (ppuVar3 = *(undefined4 ***)(param_1 + 0x74), ppuVar3 <= &local_8))
    {
      if (ppuVar2 == *(undefined4 ***)(param_1 + 0x7c)) {
        uVar6 = (int)ppuVar2 - (int)ppuVar3 >> 2;
        if (0x3ffffffe < uVar6) {
LAB_0078235d:
                    /* WARNING: Subroutine does not return */
          FUN_0087db30();
        }
        if ((uint)((int)*(undefined4 ***)(param_1 + 0x7c) - (int)ppuVar3 >> 2) < uVar6 + 1) {
          FUN_00797980();
        }
      }
      if (*(undefined4 **)(param_1 + 0x78) != (undefined4 *)0x0) {
        **(undefined4 **)(param_1 + 0x78) =
             *(undefined4 *)(*(int *)(param_1 + 0x74) + ((int)&local_8 - (int)ppuVar3 >> 2) * 4);
      }
    }
    else {
      if (ppuVar2 == *(undefined4 ***)(param_1 + 0x7c)) {
        uVar6 = (int)ppuVar2 - *(int *)(param_1 + 0x74) >> 2;
        if (0x3ffffffe < uVar6) goto LAB_0078235d;
        if ((uint)((int)*(undefined4 ***)(param_1 + 0x7c) - *(int *)(param_1 + 0x74) >> 2) <
            uVar6 + 1) {
          FUN_00797980();
        }
      }
      if (*(undefined4 **)(param_1 + 0x78) != (undefined4 *)0x0) {
        **(undefined4 **)(param_1 + 0x78) = puVar7;
      }
    }
    *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + 4;
    local_c = local_c + 1;
    if (*(uint *)(param_1 + 0x60) <= local_c) {
      return;
    }
  } while( true );
}

