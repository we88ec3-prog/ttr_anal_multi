
int FUN_008c4de0(int param_1,uint param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined1 *puVar7;
  uint uVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  int iVar11;
  undefined1 *puVar12;
  int local_c;
  
  iVar6 = *(int *)(param_1 + 0x10);
  iVar11 = iVar6 + 0x200d;
  puVar7 = (undefined1 *)(iVar6 + 0x200e);
  puVar9 = (undefined1 *)(iVar6 + 0x200f);
  puVar12 = (undefined1 *)(iVar6 + 0x200c);
  local_c = CONCAT31(CONCAT21(CONCAT11(*puVar12,*(undefined1 *)(iVar6 + 0x200d)),*puVar7),*puVar9);
  if (local_c != 0) {
    while( true ) {
      puVar10 = puVar9 + 8;
      puVar1 = (undefined1 *)(iVar11 + 8);
      uVar8 = CONCAT31(CONCAT21(CONCAT11(puVar12[4],*(undefined1 *)(iVar11 + 4)),puVar7[4]),
                       puVar9[4]);
      puVar2 = puVar12 + 8;
      puVar3 = puVar7 + 8;
      puVar9 = puVar9 + 0xc;
      puVar7 = puVar7 + 0xc;
      puVar4 = puVar12 + 0xc;
      puVar5 = (undefined1 *)(iVar11 + 0xc);
      puVar12 = puVar12 + 0xc;
      iVar11 = iVar11 + 0xc;
      if (param_2 < uVar8) break;
      if (param_2 <= CONCAT31(CONCAT21(CONCAT11(*puVar2,*puVar1),*puVar3),*puVar10)) {
        return param_2 + (CONCAT31(CONCAT21(CONCAT11(*puVar4,*puVar5),*puVar7),*puVar9) - uVar8);
      }
      local_c = local_c + -1;
      if (local_c == 0) {
        return 0;
      }
    }
  }
  return 0;
}

