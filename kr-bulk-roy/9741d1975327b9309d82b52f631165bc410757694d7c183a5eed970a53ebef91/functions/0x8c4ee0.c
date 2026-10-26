
int FUN_008c4ee0(int param_1,uint *param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  uint uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  int iVar10;
  int iVar11;
  int local_14;
  int local_10;
  uint local_c;
  
  iVar11 = *(int *)(param_1 + 0x10);
  local_c = *param_2 + 1;
  local_10 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar11 + 0x200c),
                                        *(undefined1 *)(iVar11 + 0x200d)),
                               *(undefined1 *)(iVar11 + 0x200e)),*(undefined1 *)(iVar11 + 0x200f));
  local_14 = 0;
  if (local_10 == 0) {
    *param_2 = 0;
    return 0;
  }
  puVar8 = (undefined1 *)(iVar11 + 0x200f);
  puVar6 = (undefined1 *)(iVar11 + 0x200e);
  iVar10 = iVar11 + 0x200d;
  iVar11 = iVar11 + 0x200c;
  while( true ) {
    puVar9 = puVar8 + 8;
    puVar1 = (undefined1 *)(iVar10 + 8);
    uVar7 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar11 + 4),*(undefined1 *)(iVar10 + 4)),
                              puVar6[4]),puVar8[4]);
    puVar2 = (undefined1 *)(iVar11 + 8);
    puVar3 = puVar6 + 8;
    puVar8 = puVar8 + 0xc;
    puVar6 = puVar6 + 0xc;
    puVar4 = (undefined1 *)(iVar11 + 0xc);
    puVar5 = (undefined1 *)(iVar10 + 0xc);
    iVar11 = iVar11 + 0xc;
    iVar10 = iVar10 + 0xc;
    if (local_c < uVar7) {
      local_c = uVar7;
    }
    if ((local_c <= CONCAT31(CONCAT21(CONCAT11(*puVar2,*puVar1),*puVar3),*puVar9)) &&
       (local_14 = (CONCAT31(CONCAT21(CONCAT11(*puVar4,*puVar5),*puVar6),*puVar8) - uVar7) + local_c
       , local_14 != 0)) break;
    local_10 = local_10 + -1;
    if (local_10 == 0) {
      *param_2 = 0;
      return local_14;
    }
  }
  *param_2 = local_c;
  return local_14;
}

