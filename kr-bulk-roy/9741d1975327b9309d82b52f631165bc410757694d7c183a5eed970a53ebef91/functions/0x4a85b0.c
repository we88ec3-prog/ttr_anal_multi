
void FUN_004a85b0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  puVar2 = DAT_00fb7290;
  if (DAT_00fb7290 != DAT_00fb7294) {
    FID_conflict__memcpy(DAT_00fb7290,DAT_00fb7294,0);
    DAT_00fb7294 = puVar2;
  }
  uVar4 = DAT_00fb7284 - DAT_00fb7280 >> 2;
  if (uVar4 != 0) {
    uVar6 = 0;
    puVar2 = DAT_00fb7294;
    do {
      puVar1 = (undefined4 *)(DAT_00fb7280 + uVar6 * 4);
      if (*(char *)(*(int *)(DAT_00fb7280 + uVar6 * 4) + 8) != '\0') {
        if ((puVar1 < puVar2) && (DAT_00fb7290 <= puVar1)) {
          iVar5 = (int)puVar1 - (int)DAT_00fb7290;
          if (puVar2 == DAT_00fb7298) {
            FUN_004deab0();
            puVar2 = DAT_00fb7294;
          }
          puVar3 = (undefined4 *)0x0;
          if (puVar2 != (undefined4 *)0x0) {
            *puVar2 = DAT_00fb7290[iVar5 >> 2];
            puVar3 = DAT_00fb7294;
          }
        }
        else {
          if (puVar2 == DAT_00fb7298) {
            FUN_004deab0();
            puVar2 = DAT_00fb7294;
          }
          puVar3 = (undefined4 *)0x0;
          if (puVar2 != (undefined4 *)0x0) {
            *puVar2 = *puVar1;
            puVar3 = DAT_00fb7294;
          }
        }
        puVar2 = puVar3 + 1;
        DAT_00fb7294 = puVar2;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar4);
  }
  return;
}

