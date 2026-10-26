
void FUN_006ec650(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *unaff_EDI;
  int local_8;
  
  puVar2 = param_1;
  local_8 = 0;
  if (0 < (int)param_1[8]) {
    do {
      uVar1 = *(undefined4 *)(puVar2[7] + local_8 * 4);
      iVar3 = (**(code **)(*(int *)*puVar2 + 0x2c))
                        ((int *)*puVar2,*unaff_EDI,unaff_EDI[1],unaff_EDI[3],unaff_EDI[4],uVar1,
                         &param_1);
      if (-1 < iVar3) {
        iVar3 = FUN_006ed1c0();
        if (-1 < iVar3) {
          *(undefined4 *)(unaff_EDI[8] + unaff_EDI[9] * 4) = uVar1;
          unaff_EDI[9] = unaff_EDI[9] + 1;
        }
        if ((undefined4 *)(puVar2[0x14] + 1) < param_1) {
          param_1 = (undefined4 *)(puVar2[0x14] + 1);
        }
        iVar3 = FUN_006ed1c0();
        if (-1 < iVar3) {
          *(undefined4 **)(unaff_EDI[0xb] + unaff_EDI[0xc] * 4) = param_1;
          unaff_EDI[0xc] = unaff_EDI[0xc] + 1;
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < (int)puVar2[8]);
  }
  return;
}

