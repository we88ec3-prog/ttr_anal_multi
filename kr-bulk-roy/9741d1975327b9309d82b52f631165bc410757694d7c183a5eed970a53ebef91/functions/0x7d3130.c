
void FUN_007d3130(void)

{
  undefined4 **ppuVar1;
  undefined4 **ppuVar2;
  undefined4 *puVar3;
  uint uVar4;
  int in_ECX;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00904a58;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_c = 0;
  FUN_007cc6f0(*(undefined4 *)(in_ECX + 0x10),0,&local_28,DAT_00d61f20 ^ (uint)&stack0xffffffc0);
  local_2c = 0;
  if (local_24 - local_28 >> 3 != 0) {
    puVar7 = (uint *)(in_ECX + 100);
    do {
      uVar6 = local_2c;
      puVar3 = (undefined4 *)FUN_00891268(8);
      puVar3[1] = *(undefined4 *)(local_28 + uVar6 * 8);
      *puVar3 = *(undefined4 *)(local_28 + 4 + uVar6 * 8);
      ppuVar1 = *(undefined4 ***)(in_ECX + 0x68);
      local_30 = puVar3;
      if ((&local_30 < ppuVar1) && (ppuVar2 = (undefined4 **)*puVar7, ppuVar2 <= &local_30)) {
        if (ppuVar1 == *(undefined4 ***)(in_ECX + 0x6c)) {
          uVar4 = (int)ppuVar1 - (int)ppuVar2 >> 2;
          if (0x3ffffffe < uVar4) {
LAB_007d32bf:
                    /* WARNING: Subroutine does not return */
            FUN_0087db30("vector<T> too long");
          }
          uVar4 = uVar4 + 1;
          uVar5 = (int)*(undefined4 ***)(in_ECX + 0x6c) - (int)ppuVar2 >> 2;
          if (uVar5 < uVar4) {
            if (0x3fffffff - (uVar5 >> 1) < uVar5) {
              uVar5 = 0;
            }
            else {
              uVar5 = uVar5 + (uVar5 >> 1);
            }
            if (uVar5 < uVar4) {
              uVar5 = uVar4;
            }
            FUN_00797980(uVar5);
            uVar6 = local_2c;
          }
        }
        if (*(undefined4 **)(in_ECX + 0x68) != (undefined4 *)0x0) {
          **(undefined4 **)(in_ECX + 0x68) =
               *(undefined4 *)(*puVar7 + ((int)&local_30 - (int)ppuVar2 >> 2) * 4);
        }
      }
      else {
        if (ppuVar1 == *(undefined4 ***)(in_ECX + 0x6c)) {
          uVar4 = (int)((int)ppuVar1 - *puVar7) >> 2;
          if (0x3ffffffe < uVar4) goto LAB_007d32bf;
          uVar4 = uVar4 + 1;
          uVar5 = (int)((int)*(undefined4 ***)(in_ECX + 0x6c) - *puVar7) >> 2;
          if (uVar5 < uVar4) {
            if (0x3fffffff - (uVar5 >> 1) < uVar5) {
              uVar5 = 0;
            }
            else {
              uVar5 = uVar5 + (uVar5 >> 1);
            }
            if (uVar5 < uVar4) {
              uVar5 = uVar4;
            }
            FUN_00797980(uVar5);
            uVar6 = local_2c;
          }
        }
        if (*(undefined4 **)(in_ECX + 0x68) != (undefined4 *)0x0) {
          **(undefined4 **)(in_ECX + 0x68) = puVar3;
        }
      }
      *(int *)(in_ECX + 0x68) = *(int *)(in_ECX + 0x68) + 4;
      local_2c = uVar6 + 1;
    } while (local_2c < (uint)(local_24 - local_28 >> 3));
  }
  if (local_28 != 0) {
    FUN_0089120c(local_28);
  }
  ExceptionList = local_14;
  return;
}

