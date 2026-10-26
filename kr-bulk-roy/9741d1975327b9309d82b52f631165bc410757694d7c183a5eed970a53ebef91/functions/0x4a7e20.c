
void FUN_004a7e20(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  puVar2 = DAT_00fb7270;
  if (DAT_00fb7270 != DAT_00fb7274) {
    FID_conflict__memcpy(DAT_00fb7270,DAT_00fb7274,0);
    DAT_00fb7274 = puVar2;
  }
  uVar4 = DAT_00fb7264 - DAT_00fb7260 >> 2;
  if (uVar4 != 0) {
    uVar6 = 0;
    puVar2 = DAT_00fb7274;
    do {
      puVar1 = (undefined4 *)(DAT_00fb7260 + uVar6 * 4);
      if (*(char *)(*(int *)(DAT_00fb7260 + uVar6 * 4) + 8) != '\0') {
        if ((puVar1 < puVar2) && (DAT_00fb7270 <= puVar1)) {
          iVar5 = (int)puVar1 - (int)DAT_00fb7270;
          if (puVar2 == DAT_00fb7278) {
            FUN_006d6240();
            puVar2 = DAT_00fb7274;
          }
          puVar3 = (undefined4 *)0x0;
          if (puVar2 != (undefined4 *)0x0) {
            *puVar2 = DAT_00fb7270[iVar5 >> 2];
            puVar3 = DAT_00fb7274;
          }
        }
        else {
          if (puVar2 == DAT_00fb7278) {
            FUN_006d6240();
            puVar2 = DAT_00fb7274;
          }
          puVar3 = (undefined4 *)0x0;
          if (puVar2 != (undefined4 *)0x0) {
            *puVar2 = *puVar1;
            puVar3 = DAT_00fb7274;
          }
        }
        puVar2 = puVar3 + 1;
        DAT_00fb7274 = puVar2;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar4);
  }
  return;
}

