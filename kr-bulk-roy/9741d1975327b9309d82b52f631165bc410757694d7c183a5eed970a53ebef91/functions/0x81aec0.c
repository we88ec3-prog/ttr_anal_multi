
/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_0081aec0(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  iVar5 = in_ECX[6] - in_ECX[5];
  puVar1 = in_ECX + 5;
  ppuVar2 = (undefined4 **)(local_14 + 1);
  local_14[0] = (undefined1 *)in_ECX;
  local_14[1] = ExceptionList;
  do {
    ExceptionList = ppuVar2;
    if (param_1 < (uint)(iVar5 >> 2)) {
      puVar6 = (undefined4 *)**(int **)(*puVar1 + param_1 * 4);
      *puVar6 = param_2;
      puVar6[1] = param_3;
      puVar6[2] = param_4;
      ExceptionList = local_14[1];
      return 1;
    }
    puVar6 = (undefined4 *)FUN_00891268(0x28,uVar4);
    local_14[3] = (undefined1 *)0x0;
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      local_14[0] = (undefined1 *)puVar6;
      puVar7 = (undefined4 *)FUN_00891268(0xc,uVar4);
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
    ppuVar2 = (undefined4 **)in_ECX[6];
    local_14[0] = (undefined1 *)puVar6;
    if ((local_14 < ppuVar2) && (ppuVar3 = (undefined4 **)*puVar1, ppuVar3 <= local_14)) {
      if (ppuVar2 == (undefined4 **)in_ECX[7]) {
        uVar8 = (int)ppuVar2 - (int)ppuVar3 >> 2;
        if (0x3ffffffe < uVar8) {
LAB_0081b05c:
                    /* WARNING: Subroutine does not return */
          FUN_0087db30("vector<T> too long");
        }
        uVar8 = uVar8 + 1;
        uVar9 = (int)in_ECX[7] - (int)ppuVar3 >> 2;
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
      if ((undefined4 *)in_ECX[6] != (undefined4 *)0x0) {
        *(undefined4 *)in_ECX[6] =
             *(undefined4 *)(*puVar1 + ((int)local_14 - (int)ppuVar3 >> 2) * 4);
      }
    }
    else {
      if (ppuVar2 == (undefined4 **)in_ECX[7]) {
        uVar8 = (int)((int)ppuVar2 - *puVar1) >> 2;
        if (0x3ffffffe < uVar8) goto LAB_0081b05c;
        uVar8 = uVar8 + 1;
        uVar9 = (int)((int)in_ECX[7] - *puVar1) >> 2;
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
      if ((undefined4 *)in_ECX[6] != (undefined4 *)0x0) {
        *(undefined4 *)in_ECX[6] = puVar6;
      }
    }
    in_ECX[6] = in_ECX[6] + 4;
    iVar5 = in_ECX[6] - *puVar1;
    ppuVar2 = ExceptionList;
  } while( true );
}

