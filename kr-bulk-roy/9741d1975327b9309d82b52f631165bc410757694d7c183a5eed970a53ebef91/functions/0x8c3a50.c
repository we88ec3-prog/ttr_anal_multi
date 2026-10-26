
short FUN_008c3a50(undefined4 param_1,uint *param_2)

{
  undefined1 *puVar1;
  short sVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined1 *puVar8;
  
  param_1 = *param_2 + 1;
  sVar2 = 0;
  if (0xffff < param_1) {
    *param_2 = 0;
    return 0;
  }
  do {
    puVar3 = (undefined1 *)FUN_008c3950();
    if (puVar3 != (undefined1 *)0x0) {
      uVar4 = (uint)CONCAT11(*puVar3,puVar3[1]);
      uVar6 = param_1 & 0xff;
      uVar7 = (uint)CONCAT11(puVar3[6],puVar3[7]);
      if (uVar7 != 0) {
        if (uVar6 < uVar4) {
          uVar5 = 0;
          uVar6 = uVar4;
        }
        else {
          uVar5 = uVar6 - uVar4;
        }
        param_1 = (param_1 & 0xffffff00) + uVar6;
        if (uVar5 < CONCAT11(puVar3[2],puVar3[3])) {
          puVar8 = puVar3 + 6 + uVar7 + uVar5 * 2 + -1;
          do {
            puVar1 = puVar8 + 1;
            puVar8 = puVar8 + 2;
            if (CONCAT11(*puVar1,*puVar8) != 0) {
              sVar2 = CONCAT11(puVar3[4],puVar3[5]) + CONCAT11(*puVar1,*puVar8);
              if (sVar2 != 0) {
                *param_2 = param_1;
                return sVar2;
              }
            }
            param_1 = param_1 + 1;
            uVar5 = uVar5 + 1;
          } while (uVar5 < CONCAT11(puVar3[2],puVar3[3]));
        }
      }
    }
    param_1 = (param_1 & 0xffffff00) + 0x100;
  } while (param_1 < 0x10000);
  *param_2 = 0;
  return sVar2;
}

