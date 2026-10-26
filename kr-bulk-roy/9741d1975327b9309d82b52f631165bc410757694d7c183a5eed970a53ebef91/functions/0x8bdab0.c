
void FUN_008bdab0(undefined4 param_1)

{
  undefined *puVar1;
  undefined **ppuVar2;
  
  puVar1 = &DAT_00bebcc8;
  ppuVar2 = &PTR_DAT_00bd6f48;
  do {
    FUN_008bcd10(param_1,puVar1);
    puVar1 = ppuVar2[1];
    ppuVar2 = ppuVar2 + 1;
  } while (puVar1 != (undefined *)0x0);
  return;
}

