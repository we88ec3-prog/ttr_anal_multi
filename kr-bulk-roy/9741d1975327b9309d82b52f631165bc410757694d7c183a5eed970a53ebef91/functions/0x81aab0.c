
/* WARNING: Type propagation algorithm not settling */

void FUN_0081aab0(int param_1,uint param_2,int *param_3)

{
  uint *puVar1;
  undefined4 **ppuVar2;
  undefined4 **ppuVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *in_ECX;
  uint uVar9;
  undefined1 *local_14 [4];
  
  local_14[3] = (undefined1 *)0xffffffff;
  local_14[2] = &LAB_0091cc2b;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar5 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14);
  puVar1 = (uint *)(param_1 + 0x14);
  ppuVar2 = (undefined4 **)(local_14 + 1);
  local_14[0] = (undefined1 *)in_ECX;
  local_14[1] = ExceptionList;
  do {
    ExceptionList = ppuVar2;
    if (param_2 < (uint)(iVar5 >> 2)) {
      uVar4 = (**(code **)(*param_3 + 4))();
      if ((uVar4 & 0x11000000) == 0x11000000) {
        *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 2;
      }
      else {
        uVar4 = (**(code **)(*param_3 + 4))();
        if ((uVar4 & 0x12100000) == 0x12100000) {
          *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 4;
        }
        else {
          uVar4 = (**(code **)(*param_3 + 4))();
          if ((uVar4 & 0x12200000) == 0x12200000) {
            *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 8;
          }
          else {
            uVar4 = (**(code **)(*param_3 + 4))();
            if ((uVar4 & 0x14100000) == 0x14100000) {
              *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x10;
            }
          }
        }
      }
      FUN_007bb350();
      ExceptionList = local_14[1];
      return;
    }
    puVar6 = (undefined4 *)FUN_00891268(0x28,uVar4);
    local_14[3] = (undefined1 *)0x0;
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      local_14[0] = (undefined1 *)puVar6;
      puVar7 = (undefined4 *)FUN_00891268(0xc);
      if (puVar7 == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)0x0;
      }
      else {
        *puVar7 = 0;
        puVar7[1] = 0;
        puVar7[2] = 0;
      }
      *puVar6 = puVar7;
      puVar6[1] = 0;
      puVar6[2] = 0;
      puVar6[3] = 0;
      puVar6[5] = 0;
      puVar6[6] = 0;
      puVar6[7] = 0;
      *(undefined1 *)(puVar6 + 9) = 0;
    }
    local_14[3] = (undefined1 *)0xffffffff;
    ppuVar2 = *(undefined4 ***)(param_1 + 0x18);
    local_14[0] = (undefined1 *)puVar6;
    if ((local_14 < ppuVar2) && (ppuVar3 = (undefined4 **)*puVar1, ppuVar3 <= local_14)) {
      if (ppuVar2 == *(undefined4 ***)(param_1 + 0x1c)) {
        uVar8 = (int)ppuVar2 - (int)ppuVar3 >> 2;
        if (0x3ffffffe < uVar8) {
LAB_0081ac35:
                    /* WARNING: Subroutine does not return */
          FUN_0087db30("vector<T> too long");
        }
        uVar8 = uVar8 + 1;
        uVar9 = (int)*(undefined4 ***)(param_1 + 0x1c) - (int)ppuVar3 >> 2;
        if (uVar9 < uVar8) {
          if (0x3fffffff - (uVar9 >> 1) < uVar9) {
            uVar9 = 0;
          }
          else {
            uVar9 = uVar9 + (uVar9 >> 1);
          }
          if (uVar9 < uVar8) {
            uVar9 = uVar8;
          }
          FUN_00797980(uVar9);
        }
      }
      if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
        **(undefined4 **)(param_1 + 0x18) =
             *(undefined4 *)(*puVar1 + ((int)local_14 - (int)ppuVar3 >> 2) * 4);
      }
    }
    else {
      if (ppuVar2 == *(undefined4 ***)(param_1 + 0x1c)) {
        uVar8 = (int)((int)ppuVar2 - *puVar1) >> 2;
        if (0x3ffffffe < uVar8) goto LAB_0081ac35;
        uVar8 = uVar8 + 1;
        uVar9 = (int)((int)*(undefined4 ***)(param_1 + 0x1c) - *puVar1) >> 2;
        if (uVar9 < uVar8) {
          if (0x3fffffff - (uVar9 >> 1) < uVar9) {
            uVar9 = 0;
          }
          else {
            uVar9 = uVar9 + (uVar9 >> 1);
          }
          if (uVar9 < uVar8) {
            uVar9 = uVar8;
          }
          FUN_00797980(uVar9);
        }
      }
      if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
        **(undefined4 **)(param_1 + 0x18) = puVar6;
      }
    }
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 4;
    iVar5 = *(int *)(param_1 + 0x18) - *puVar1;
    ppuVar2 = ExceptionList;
  } while( true );
}

