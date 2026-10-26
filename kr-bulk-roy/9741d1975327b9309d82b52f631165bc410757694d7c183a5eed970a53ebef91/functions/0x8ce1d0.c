
void FUN_008ce1d0(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *in_EAX;
  int iVar4;
  uint *in_ECX;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint local_10;
  byte *local_c;
  undefined4 *local_8;
  
  iVar6 = *in_EAX;
  local_c = (byte *)in_EAX[2];
  uVar7 = 0;
  local_8 = (undefined4 *)0x0;
  local_10 = 0;
  FUN_008cdfc0();
  if (iVar6 != 0) {
    iVar5 = 0;
    do {
      if (local_8 == (undefined4 *)0x0) {
        local_10 = (uint)*local_c;
        local_c = local_c + 1;
        local_8 = (undefined4 *)0x80;
      }
      if ((local_10 & (uint)local_8) != 0) {
        uVar1 = *(uint *)(in_ECX[2] + 0x10 + iVar5);
        iVar4 = in_ECX[2] + iVar5;
        if (((uVar1 & 4) == 0) && (*(uint *)(iVar4 + 0x10) = uVar1 | 4, uVar7 < *in_ECX)) {
          *(int *)(in_ECX[3] + uVar7 * 4) = iVar4;
          uVar7 = uVar7 + 1;
        }
      }
      local_8 = (undefined4 *)((int)local_8 >> 1);
      iVar5 = iVar5 + 0x1c;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  in_ECX[1] = uVar7;
  puVar2 = (undefined4 *)in_ECX[3];
  if (1 < (int)uVar7) {
    local_c = (byte *)(uVar7 - 1);
    local_10 = 0;
    local_8 = puVar2;
    do {
      local_8 = local_8 + 1;
      piVar3 = (int *)*local_8;
      for (uVar7 = local_10; (-1 < (int)uVar7 && (*piVar3 <= *(int *)puVar2[uVar7]));
          uVar7 = uVar7 + -1) {
        puVar2[uVar7 + 1] = (int *)puVar2[uVar7];
        puVar2[uVar7] = piVar3;
      }
      local_10 = local_10 + 1;
      local_c = (byte *)((int)local_c + -1);
    } while (local_c != (byte *)0x0);
  }
  return;
}

