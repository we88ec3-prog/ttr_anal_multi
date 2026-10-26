
/* WARNING: Removing unreachable block (ram,0x00839176) */

void FUN_00839060(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  uint *puVar6;
  uint uVar7;
  uint local_8;
  
  puVar5 = *(ushort **)(param_1 + 0x18);
  if (puVar5 != *(ushort **)(param_1 + 0x1c)) {
    puVar6 = (uint *)(param_1 + 0x48);
    do {
      uVar7 = (uint)*puVar5;
      *(undefined4 *)(*(int *)(param_1 + 0x38) + uVar7 * 4) = 0;
      puVar1 = *(uint **)(param_1 + 0x4c);
      local_8 = uVar7;
      if (&local_8 < puVar1) {
        puVar2 = (uint *)*puVar6;
        if (&local_8 < puVar2) goto LAB_00839102;
        if (puVar1 == *(uint **)(param_1 + 0x50)) {
          uVar7 = (int)puVar1 - (int)puVar2 >> 2;
          if (0x3ffffffe < uVar7) goto LAB_00839190;
          uVar7 = uVar7 + 1;
          uVar3 = (int)*(uint **)(param_1 + 0x50) - (int)puVar2 >> 2;
          if (uVar3 < uVar7) {
            if (0x3fffffff - (uVar3 >> 1) < uVar3) {
              uVar3 = 0;
            }
            else {
              uVar3 = uVar3 + (uVar3 >> 1);
            }
            if (uVar3 < uVar7) {
              uVar3 = uVar7;
            }
            FUN_006ddf10(uVar3);
          }
        }
        if (*(undefined4 **)(param_1 + 0x4c) != (undefined4 *)0x0) {
          **(undefined4 **)(param_1 + 0x4c) =
               *(undefined4 *)(*puVar6 + ((int)&local_8 - (int)puVar2 >> 2) * 4);
        }
      }
      else {
LAB_00839102:
        if (puVar1 == *(uint **)(param_1 + 0x50)) {
          uVar3 = (int)((int)puVar1 - *puVar6) >> 2;
          if (0x3ffffffe < uVar3) {
LAB_00839190:
                    /* WARNING: Subroutine does not return */
            FUN_0087db30("vector<T> too long");
          }
          uVar3 = uVar3 + 1;
          uVar4 = (int)((int)*(uint **)(param_1 + 0x50) - *puVar6) >> 2;
          if (uVar4 < uVar3) {
            if (0x3fffffff - (uVar4 >> 1) < uVar4) {
              uVar4 = 0;
            }
            else {
              uVar4 = uVar4 + (uVar4 >> 1);
            }
            if (uVar4 < uVar3) {
              uVar4 = uVar3;
            }
            FUN_006ddf10(uVar4);
          }
        }
        if (*(uint **)(param_1 + 0x4c) != (uint *)0x0) {
          **(uint **)(param_1 + 0x4c) = uVar7;
        }
      }
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 4;
      puVar5 = puVar5 + 2;
    } while (puVar5 != *(ushort **)(param_1 + 0x1c));
  }
  if (*(int *)(param_1 + 0x18) != *(int *)(param_1 + 0x1c)) {
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x18);
  }
  return;
}

