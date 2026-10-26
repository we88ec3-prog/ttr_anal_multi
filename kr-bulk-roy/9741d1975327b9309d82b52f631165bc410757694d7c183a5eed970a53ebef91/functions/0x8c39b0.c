
short FUN_008c39b0(undefined4 param_1,byte param_2)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  puVar2 = (undefined1 *)FUN_008c3950();
  if (puVar2 == (undefined1 *)0x0) {
    return 0;
  }
  uVar3 = (uint)param_2 - (uint)CONCAT11(*puVar2,puVar2[1]);
  if (((uVar3 < CONCAT11(puVar2[2],puVar2[3])) && (CONCAT11(puVar2[6],puVar2[7]) != 0)) &&
     (iVar1 = (uint)CONCAT11(puVar2[6],puVar2[7]) + uVar3 * 2,
     CONCAT11(puVar2[iVar1 + 6],puVar2[iVar1 + 7]) != 0)) {
    return CONCAT11(puVar2[4],puVar2[5]) + CONCAT11(puVar2[iVar1 + 6],puVar2[iVar1 + 7]);
  }
  return 0;
}

