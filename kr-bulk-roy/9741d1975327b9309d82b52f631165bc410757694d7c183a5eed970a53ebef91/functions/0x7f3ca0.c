
/* WARNING: Type propagation algorithm not settling */

int FUN_007f3ca0(int param_1,int param_2)

{
  undefined4 **ppuVar1;
  undefined4 **ppuVar2;
  void *pvVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  uint *puVar11;
  undefined4 *puVar12;
  undefined4 local_84 [26];
  uint local_1c;
  uint local_18;
  undefined1 *local_14 [4];
  
  pvVar3 = ExceptionList;
  local_14[2] = &LAB_00905416;
  local_14[1] = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = local_14 + 1;
  *(int *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  local_14[3] = (undefined1 *)0x1;
  local_18 = 0;
  local_1c = *(int *)(param_2 + 0x28) - *(int *)(param_2 + 0x24) >> 2;
  if (local_1c == 0) {
    ExceptionList = pvVar3;
    return param_1;
  }
  do {
    puVar5 = (undefined4 *)FUN_00891268(0x80,uVar4);
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      puVar5[0x1a] = 1;
      puVar5[0x1b] = 1;
      puVar5[0x1c] = 1;
      puVar5[0x1d] = 1;
      _memset(local_84,0,0x68);
      puVar9 = local_84;
      puVar10 = puVar5;
      for (iVar7 = 0x1a; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
      }
      puVar5[0x1e] = 1;
      puVar5[0x1f] = 0;
    }
    puVar9 = *(undefined4 **)(*(int *)(param_2 + 0x24) + local_18 * 4);
    puVar10 = puVar9;
    puVar12 = puVar5;
    for (iVar7 = 0x1e; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar12 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar12 = puVar12 + 1;
    }
    puVar5[0x1f] = puVar9[0x1f];
    puVar11 = (uint *)(param_1 + 0x24);
    puVar5[0x1e] = puVar9[0x1e];
    ppuVar1 = *(undefined4 ***)(param_1 + 0x28);
    local_14[0] = (undefined1 *)puVar5;
    if ((local_14 < ppuVar1) && (ppuVar2 = (undefined4 **)*puVar11, ppuVar2 <= local_14)) {
      if (ppuVar1 == *(undefined4 ***)(param_1 + 0x2c)) {
        uVar6 = (int)ppuVar1 - (int)ppuVar2 >> 2;
        if (0x3ffffffe < uVar6) {
LAB_007f3e6f:
                    /* WARNING: Subroutine does not return */
          FUN_0087db30("vector<T> too long");
        }
        uVar6 = uVar6 + 1;
        uVar8 = (int)*(undefined4 ***)(param_1 + 0x2c) - (int)ppuVar2 >> 2;
        if (uVar8 < uVar6) {
          if (0x3fffffff - (uVar8 >> 1) < uVar8) {
            uVar8 = 0;
          }
          else {
            uVar8 = uVar8 + (uVar8 >> 1);
          }
          if (uVar8 < uVar6) {
            uVar8 = uVar6;
          }
          FUN_00797980(uVar8);
        }
      }
      if (*(undefined4 **)(param_1 + 0x28) != (undefined4 *)0x0) {
        **(undefined4 **)(param_1 + 0x28) =
             *(undefined4 *)(*puVar11 + ((int)local_14 - (int)ppuVar2 >> 2) * 4);
      }
    }
    else {
      if (ppuVar1 == *(undefined4 ***)(param_1 + 0x2c)) {
        uVar6 = (int)((int)ppuVar1 - *puVar11) >> 2;
        if (0x3ffffffe < uVar6) goto LAB_007f3e6f;
        uVar6 = uVar6 + 1;
        uVar8 = (int)((int)*(undefined4 ***)(param_1 + 0x2c) - *puVar11) >> 2;
        if (uVar8 < uVar6) {
          if (0x3fffffff - (uVar8 >> 1) < uVar8) {
            uVar8 = 0;
          }
          else {
            uVar8 = uVar8 + (uVar8 >> 1);
          }
          if (uVar8 < uVar6) {
            uVar8 = uVar6;
          }
          FUN_00797980(uVar8);
        }
      }
      if (*(undefined4 **)(param_1 + 0x28) != (undefined4 *)0x0) {
        **(undefined4 **)(param_1 + 0x28) = puVar5;
      }
    }
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 4;
    local_18 = local_18 + 1;
    if (local_1c <= local_18) {
      ExceptionList = local_14[1];
      return param_1;
    }
  } while( true );
}

