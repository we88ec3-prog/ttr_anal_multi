
undefined4 FUN_004e3660(int param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int in_ECX;
  int iVar5;
  uint uVar6;
  undefined4 local_8;
  
  puVar1 = (uint *)(in_ECX + 0x68fc);
  uVar6 = (uint)(*(byte *)(param_1 + 2) >> 5);
  uVar4 = *(int *)(in_ECX + 0x6900) - *(int *)(in_ECX + 0x68fc) >> 2;
  if ((uVar4 <= uVar6) && (iVar5 = (uVar6 - uVar4) + 1, iVar5 != 0)) {
    local_8 = 0;
    do {
      puVar2 = *(undefined4 **)(in_ECX + 0x6900);
      iVar5 = iVar5 + -1;
      if (&local_8 < puVar2) {
        puVar3 = (undefined4 *)*puVar1;
        if (&local_8 < puVar3) goto LAB_004e36df;
        if (puVar2 == *(undefined4 **)(in_ECX + 0x6904)) {
          FUN_006d6240();
        }
        if (*(undefined4 **)(in_ECX + 0x6900) != (undefined4 *)0x0) {
          **(undefined4 **)(in_ECX + 0x6900) =
               *(undefined4 *)(*puVar1 + ((int)&local_8 - (int)puVar3 >> 2) * 4);
        }
      }
      else {
LAB_004e36df:
        if (puVar2 == *(undefined4 **)(in_ECX + 0x6904)) {
          FUN_006d6240();
        }
        if (*(undefined4 **)(in_ECX + 0x6900) != (undefined4 *)0x0) {
          **(undefined4 **)(in_ECX + 0x6900) = 0;
        }
      }
      *(int *)(in_ECX + 0x6900) = *(int *)(in_ECX + 0x6900) + 4;
    } while (iVar5 != 0);
  }
  puVar1 = (uint *)(*puVar1 + uVar6 * 4);
  *puVar1 = *puVar1 | 1 << (*(char *)(param_1 + 2) - 1U & 0x1f);
  return 0;
}

