
undefined4 FUN_008ca290(undefined4 param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint local_c;
  int local_8;
  
  piVar1 = (int *)(in_ECX + 0x2f8);
  *piVar1 = 0;
  *(undefined4 *)(in_ECX + 0x2fc) = 0;
  *(undefined4 *)(in_ECX + 0x300) = 0;
  *(undefined4 *)(in_ECX + 0x304) = 0;
  *(undefined4 *)(in_ECX + 0x308) = 0;
  *(undefined4 *)(in_ECX + 0x30c) = 0;
  iVar3 = FUN_008c2b00();
  if (((iVar3 == 0) && (7 < local_c)) && (iVar3 = FUN_008bc7a0(param_1,local_c,piVar1), iVar3 == 0))
  {
    puVar2 = (undefined1 *)*piVar1;
    *(undefined1 **)(in_ECX + 0x2fc) = puVar2 + local_c;
    uVar7 = (uint)CONCAT11(puVar2[2],puVar2[3]);
    uVar5 = CONCAT31(CONCAT21(CONCAT11(puVar2[4],puVar2[5]),puVar2[6]),puVar2[7]);
    if (((CONCAT11(*puVar2,puVar2[1]) == 1) && (7 < uVar5)) &&
       ((uVar7 <= uVar5 - 8 >> 2 && (uVar5 + 1 <= local_c)))) {
      iVar6 = *piVar1 + 8;
      iVar4 = 0;
      *(uint *)(in_ECX + 0x300) = *piVar1 + uVar5;
      iVar3 = iVar6 + uVar7 * 4;
      local_8 = 0;
      *(uint *)(in_ECX + 0x308) = uVar7;
      *(uint *)(in_ECX + 0x304) = local_c - uVar5;
      if (1 < uVar7) {
        local_c = (uVar7 - 2 >> 1) + 1;
        do {
          iVar4 = iVar4 + (uint)CONCAT11(*(undefined1 *)(iVar6 + 2),*(undefined1 *)(iVar6 + 3)) * 10
          ;
          local_8 = local_8 + (uint)CONCAT11(*(undefined1 *)(iVar6 + 6),*(undefined1 *)(iVar6 + 7))
                              * 10;
          iVar6 = iVar6 + 8;
          uVar7 = uVar7 - 2;
          local_c = local_c + -1;
        } while (local_c != 0);
      }
      if (uVar7 != 0) {
        iVar3 = iVar3 + (uint)CONCAT11(*(undefined1 *)(iVar6 + 2),*(undefined1 *)(iVar6 + 3)) * 10;
      }
      if ((uint)(local_8 + iVar4 + iVar3) <= *piVar1 + uVar5) {
        *(undefined1 *)(in_ECX + 0x30c) = 1;
        return 0;
      }
    }
    FUN_008bab90(param_1,piVar1);
    *piVar1 = 0;
    *(undefined4 *)(in_ECX + 0x2fc) = 0;
    *(undefined4 *)(in_ECX + 0x300) = 0;
    *(undefined4 *)(in_ECX + 0x304) = 0;
    *(undefined4 *)(in_ECX + 0x308) = 0;
    *(undefined4 *)(in_ECX + 0x30c) = 0;
  }
  return 8;
}

