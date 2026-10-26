
undefined4 * FUN_00511400(void)

{
  int *in_EAX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint local_8;
  
  puVar3 = DAT_00fe3714;
  if (*(char *)((int)DAT_00fe3714[1] + 0x15) == '\0') {
    puVar1 = (undefined4 *)DAT_00fe3714[1];
    do {
      if ((int)puVar1[3] < *in_EAX) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x15) == '\0');
  }
  if ((puVar3 != DAT_00fe3714) && ((int)puVar3[3] <= *in_EAX)) {
    return puVar3 + 4;
  }
  local_8 = local_8 & 0xffffff00;
  FUN_00511c30();
  FUN_00511880(puVar3);
  return (undefined4 *)(local_8 + 0x10);
}

